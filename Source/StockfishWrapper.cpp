/*
  ==============================================================================

    StockfishWrapper.cpp
    Created: 28 Feb 2017 4:13:22pm
    Author:  xavier

  ==============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>

#include "../JuceLibraryCode/JuceHeader.h"
#include "StockfishWrapper.h"

// #define SW_DEBUG 1

/*
  ==============================================================================
    LookFor 
  ==============================================================================
*/
void LookFor::run() {
    // printf("------------ LOOKFOR THREAD\n");
    char  *line;
    size_t len = 1024;
    ssize_t read;        
    line = (char*)malloc(1024);
    while ((read = getline(&line, &len, stockfishWrapper->istream)) != -1) {
#ifdef SW_DEBUG
         printf("SF >>> %s", line);
#endif
        StringArray words;

        words.addTokens(String(line), " \n", "\"");
        // Mate and Cp are not specified on bestmove line
        bool bestMoveLine = strncmp(line, "bestmove", 8) == 0;
        if (!bestMoveLine) {
            stockfishWrapper->setMate(10000);
            stockfishWrapper->setCp(10000);
        } else {
            stockfishWrapper->setPonder("");
        }

        for (int k=0; k < words.size() -1; k++ ) {
            String word = words[k];
            String value  = words[k + 1];
            if (word == "ponder") {
                String sf_ponder = value;
#ifdef SW_DEBUG
                printf("SF * ponder : %s\n", sf_ponder.toRawUTF8());
#endif
                stockfishWrapper->setPonder(sf_ponder);
            } else if (word == "mate") { 
                int sf_mate = atoi(value.toRawUTF8());
#ifdef SW_DEBUG
                printf("SF * mate : %i\n", sf_mate);
#endif                    
                stockfishWrapper->setMate(sf_mate);
            } else if (word == "cp") { 
                int sf_cp = atoi(value.toRawUTF8());
#ifdef SW_DEBUG
                printf("SF * cp : %i\n", sf_cp);
#endif                    
                stockfishWrapper->setCp(sf_cp);
            }
        }

        if (stockfishWrapper->lookForString.length() > 0 && strncmp(line, stockfishWrapper->lookForString.toRawUTF8(), stockfishWrapper->lookForString.length()) == 0) {
            // printf("-- LOOKFOR THREAD : '%s' FOUND !\n", stockfishWrapper->lookForString.toRawUTF8());
            stockfishWrapper->setLookForFound(line, true);
        }
    }
}



/*
  ==============================================================================
    StockfishWrapper 
  ==============================================================================
*/
int StockfishWrapper::startStockfishProcess() {
    if (pipe(wpipe) || pipe(rpipe))
    {
        fprintf(stderr, "Pipe creation failed.\n");
        return EXIT_FAILURE;
    }
    pid = fork();
    if (pid == 0)
    {
        /* Stockfish process */
        setvbuf(stdin, NULL, _IOLBF, BUFSIZ);
        setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
        setvbuf(stderr, NULL, _IOLBF, BUFSIZ);
        dup2(wpipe[0], STDIN_FILENO);
        dup2(rpipe[1], STDOUT_FILENO);
        dup2(rpipe[1], STDERR_FILENO);
        close(wpipe[0]);
        close(wpipe[1]);
        close(rpipe[0]);
        close(rpipe[1]);
        if (execl("/usr/games/stockfishVariant", "stockfishVariant", NULL) == -1)
        {
            if (execl("/usr/bin/stockfishVariant", "stockfishVariant", NULL) == -1)
            {
                fprintf(stderr, "Exec stockfish failed.\n");
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }

    /* parent process */

    close(wpipe[0]); /* Close other end */
    close(rpipe[1]); /* Close other end */

    istream = fdopen(rpipe[0], "r");
    if (setvbuf(istream, NULL, _IOLBF, BUFSIZ) != 0) {
        printf("### ERROR ### 1");
    }
    
    ostream = fdopen(wpipe[1], "w");
    if (setvbuf(ostream, NULL, _IOLBF, BUFSIZ) != 0) {
        printf("### ERROR ### 2");
    }
    
    lookForThread = new LookFor("lookFor", this);
    lookForThread->startThread();

    return EXIT_SUCCESS;
}


void StockfishWrapper::initUCI() {
    fprintf(ostream, "uci\n");
    // fprintf(ostream, "setoption name Threads value 4\n");
    fprintf(ostream, "setoption name Hash value 128\n");
    // fprintf(ostream, "setoption name MultiPV value 2\n");
    // fprintf(ostream, "setoption name Minimum Thinking Time value 2000\n");
    startLookingFor("uciok");
    while (!isLookForFound)  { Thread::sleep(100); }

}


void StockfishWrapper::startGame() {
    moves.deleteAll();    

    printf("To Stockfish : UCINEWGAME\n");

    fprintf(ostream, "ucinewgame\n");
    if (this->variant != 0) {
        // send variant to stockfish....
        this->setVariant(this->variant);
    }
    fprintf(ostream, "isready\n");
    startLookingFor("readyok");

    while (!isLookForFound)  { Thread::sleep(100); }
}





void StockfishWrapper::setLookForFound(String str, bool b) {
    ScopedLock lock(lookForFoundCriticalSection);
    lookForFound = str;
    isLookForFound = b;
}

void StockfishWrapper::startLookingFor(String lookFor)
{
#ifdef SW_DEBUG    
    printf("startLookingFor...%s\n", lookFor.toRawUTF8());
#endif
    lookForString = lookFor;
    setLookForFound("", false);
}

String StockfishWrapper::getLookForString() {
    if (isLookForFound) {
        return lookForFound;
    }
    return "";
}

void StockfishWrapper::addMove(String move)
{    
    moves.append(new Move(move));
}

void StockfishWrapper::setLevel(int level)
{
    fprintf(ostream, "setoption name Skill Level value %i\n", level);
    printf(">>>> setoption name Skill Level value %i <<<<\n", level);
    
}


void StockfishWrapper::setVariant(Variant variant)
{
    this->variant = variant;
    String variantName = "#NOT_DEFINED#";
    switch (variant) {
        case CHESS:
            variantName = "chess";
            break;
        case ATOMIC:
            variantName = "atomic";
            break;
        case RACING_KINGS:
            variantName = "racingkings";
            break;
    }
    fprintf(ostream, "setoption name UCI_Variant value %s\n", variantName.toRawUTF8());
    printf(">>>> setoption name UCI_Variant value %s\n", variantName.toRawUTF8());
}


String StockfishWrapper::getAllMoves() {
    String allMoves = "";
    if (moves.size() >0) {
        for (int k=0; k< moves.size() ; k++) {
            allMoves += moves[k].get()->move;
            allMoves += ' ';            
        }
    }
    return allMoves;
}

void StockfishWrapper::startSearchingBestMoveInMillis(int millis) {
    String newPosString = getAllMoves();

    if (newPosString.length() >0) {
        newPosString = " moves " + newPosString ;
    }
        
    //printf(">>>>>>>>>>>>>>> this->startingFen size %i :  %s\n", this->startingFen.length(), this->startingFen.toRawUTF8());
    if (this->startingFen.length() > 0 ) {
       fprintf(ostream, "position fen \"%s\" %s\n", this->startingFen.toRawUTF8(), newPosString.toRawUTF8());
#ifdef SW_DEBUG    
      printf(">>>> position fen \"%s\" %s\n", this->startingFen.toRawUTF8(), newPosString.toRawUTF8());      
#endif
    } else {
       fprintf(ostream, "position startpos %s\n", newPosString.toRawUTF8());
#ifdef SW_DEBUG    
       printf(">>>> position startpos %s\n", newPosString.toRawUTF8());
#endif
    }
    
    startLookingFor("bestmove");
    fprintf(ostream, "go  movetime %i\n", millis);
}


void StockfishWrapper::startSearchingBestMove()
{
    String newPosString = getAllMoves();

    if (newPosString.length() >0) {
        newPosString = " moves " + newPosString ;
    }
    
    // printf(">>>>>>>>>>>>>>> this->startingFen size %i :  %s\n", this->startingFen.length(), this->startingFen.toRawUTF8());
    if (this->startingFen.length() > 0 ) {
       fprintf(ostream, "position fen \"%s\" %s\n", this->startingFen.toRawUTF8(), newPosString.toRawUTF8());        
#ifdef SW_DEBUG    
       printf(">>>> position fen \"%s\" %s\n", this->startingFen.toRawUTF8(), newPosString.toRawUTF8());      
#endif
    } else {
       fprintf(ostream, "position startpos %s\n", newPosString.toRawUTF8());
#ifdef SW_DEBUG    
       printf(">>>> position startpos %s\n", newPosString.toRawUTF8());
#endif
    }
    
    startLookingFor("bestmove");
    fprintf(ostream, "go  \n");
#ifdef SW_DEBUG    
    printf(">>>>> go \n");
#endif
}


String StockfishWrapper::checkBestMove() {
    String bestMoveLine = this->getLookForString();
    if (bestMoveLine.length() > 0) {
        StringArray strings;
        strings.addTokens (bestMoveLine, " \n", "\"");
        String bm = strings[1];
#ifdef SW_DEBUG       
        printf(">>>> BESTMOVE : %s\n", bm.toRawUTF8());
#endif
        return bm;
    }
    return "";
    
}


void StockfishWrapper::cancelLastMove() {
    printf(">>> STOCKFISH WILL CANCEL LAST MOVE size : %i\n", moves.size());

    String newPosString = "";
    if (moves.size() >0) {
        for (int k=0; k< moves.size() ; k++) {
            newPosString += "(";
            newPosString += k;
            newPosString += ")";
            newPosString += moves[k].get()->move;
            newPosString += ' ';
            
        }
    }
    newPosString +=" \n";
        
    printf("Size : %i : %s", moves.size(), newPosString.toRawUTF8());

    moves.remove(moves[moves.size() -1].get());
    printf(">>> STOCKFISH CANCELED LAST MOVE size : %i\n", moves.size());
    newPosString = "";
    if (moves.size() >0) {
        for (int k=0; k< moves.size() ; k++) {
            newPosString += "(";
            newPosString += k;
            newPosString += ")";
            newPosString += moves[k].get()->move;
            newPosString += ' ';
            
        }
    }
    newPosString +=" \n";
        
    printf("Size : %i : %s", moves.size(), newPosString.toRawUTF8());
}


void StockfishWrapper::clean() {
    printf(">>>> stockfish cleaning\n");
    /* kill stockfish */
    kill(pid, SIGTERM);
    //lookForThread->stopThread();
    printf(">>>> stockfish cleaning : wait for thread\n");
    if (lookForThread->waitForThreadToExit(1000)) {
        printf(">>>> stockfish cleaning : thread terminated\n");
    } else {
        printf(">>>> stockfish cleaning : thread NOT terminated ##\n");
    }
    moves.deleteAll();
    fclose(istream);    
    fclose(ostream);    
}


void StockfishWrapper::setStartingFen(String startingFen) {
    this->startingFen = startingFen;    
}

String StockfishWrapper::getStartingFen() {
    return this->startingFen;    
}

