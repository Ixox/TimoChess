/*
  ==============================================================================

    StockfishWrapper.h
    Created: 28 Feb 2017 4:13:22pm
    Author:  xavier

  ==============================================================================
*/

#ifndef STOCKFISHWRAPPER_H_INCLUDED
#define STOCKFISHWRAPPER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"



class Move
{
    public:
        Move(String m) {
            move = m;
        }
        String move;
        LinkedListPointer<Move> nextListItem;
};


class StockfishWrapper;

class LookFor : public Thread {
    public:
        LookFor(const char* name, StockfishWrapper* stockfishWrapper) : Thread(name) {
            this->stockfishWrapper = stockfishWrapper;
        }
        void run();
    private : 
        StockfishWrapper *stockfishWrapper;
};

enum Variant {
    CHESS = 1,
    RACING_KINGS,
    ATOMIC
};


class StockfishWrapper {
    public:
         friend class LookFor;
        int startStockfishProcess();
        void initUCI();
        void startGame();
        void addMove(String move);
        void startSearchingBestMove();
        void startSearchingBestMoveInMillis(int millis);
        void setLevel(int level);
        void setVariant(Variant variant);
        Variant getVariant() { return variant; }
        String checkBestMove();
        void clean();
        void cancelLastMove();
        void startLookingFor(String move);
        String getLookForString();
    private:
        String getAllMoves();
        Variant variant;
        pid_t pid;
        int wpipe[2];
        int rpipe[2];
        FILE *ostream, *istream;
        LinkedListPointer<Move> moves;

        void setLookForFound(String str, bool b);
        String lookForFound;
        CriticalSection lookForFoundCriticalSection;
        bool isLookForFound;
        String lookForString;

        LookFor* lookForThread;
};



#endif  // STOCKFISHWRAPPER_H_INCLUDED
