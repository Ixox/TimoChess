/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "GameSetup.h"
#include "GamePage.h"
#include "PawnPromotion.h"
#include "BoardComponent.h"
#include "GameListener.h"
#include "StockfishWrapper.h"
#include "ChessBoard.h"
#include "EndOfTheGame.h"

//==============================================================================
class TimoChessApplication  : public JUCEApplication
{
public:
    //==============================================================================
    TimoChessApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        // This method is where you should put your application's initialisation code..

        mainWindow = new MainWindow (getApplicationName());
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainContentComponent class.
    */
    class MainWindow    : public DocumentWindow, public GameListener
    {
    public:
        MainWindow (String name)  : DocumentWindow (name,
                                                    Colours::lightgrey,
                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            gameSetup = new GameSetup();
            gameSetup->setGameListener(this);
            gamePage = new GamePage();
            gamePage->setGameListener(this);
            pawnPromotion = new PawnPromotion();
            pawnPromotion->setGameListener(this);
            boardComponent = new BoardComponent();
            boardComponent->setGameListener(this);
            endOfTheGame = new EndOfTheGame();
            endOfTheGame->setGameListener(this);
            
            setup();
            
            stockfish = new StockfishWrapper();
            stockfish->startStockfishProcess();
            stockfish->initUCI();
            
            
            gamePage->setStockfish(stockfish);
        }

        void closeButtonPressed() override
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
            
            delete gamePage;
            delete gameSetup;
            stockfish->clean();
            delete stockfish;
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

        void setup() {
            setContentNonOwned (gameSetup, true);            
            setVisible (true);
            gameSetup->grabKeyboardFocus();
        }
        
        void startGame() {            
            // DEBUG 
            // Mate en 1 coup
            //stockfish->setStartingFen("5r2/k5P1/8/8/8/3R4/1R6/6K1 w - - 0 1");
            //Mate en 2 coup
             stockfish->setStartingFen("5r2/1k4P1/8/8/8/3R4/2R5/6K1 w - - 0 1");
            // White plays and PATE !
            //stockfish->setStartingFen("7k/5Q2/8/8/8/8/8/K4R2 w - - 0 1");
            // Pawn Promotion
             // stockfish->setStartingFen("5r2/k5P1/8/8/8/8/1K4p1/8 w - - 0 1");
            // Castle ?
            // stockfish->setStartingFen("r3k2r/pppqpppp/8/8/8/8/PP1PPQPP/R3K2R w KQkq - 0 1");
             

            // PATE !
            // stockfish->setStartingFen( "k7/P7/K7/8/8/4B3/8/8 w - - 0 1");

            stockfish->setLevel(gameSetup->getLevel()); 
            stockfish->setVariant(gameSetup->getVariant()); 

            gamePage->start(gameSetup->getRealPlayerColor());
            setContentNonOwned (gamePage, true);
            setVisible (true);
            gamePage->grabKeyboardFocus();
        }
        void resumeGame() {            
            setContentNonOwned (gamePage, true);
            setVisible (true);
            gamePage->grabKeyboardFocus();
        }
        void showBoard(ChessBoard* chessBoard) {
            boardComponent->setChessboard(chessBoard);
            setContentNonOwned (boardComponent, true);
            setVisible (true);
            boardComponent->grabKeyboardFocus();
        }
        void askForPromotionPiece(Color color) {
            pawnPromotion->setColor(color);
            setContentNonOwned (pawnPromotion, true);
            setVisible (true);
            pawnPromotion->grabKeyboardFocus();
        }
        void answerPromotionPiece(Piece promotion) {
            gamePage->setPromotionChoice(promotion);
            setContentNonOwned (gamePage, true);
            setVisible (true);
            gamePage->grabKeyboardFocus();
        }
        void gameFinished(Color winner, Color realPlayerColor, String additionalText) {
            endOfTheGame->theWinnerIs(winner, realPlayerColor, additionalText);
            setContentNonOwned (endOfTheGame, true);
            setVisible (true);
            endOfTheGame->grabKeyboardFocus();            
        }


    private:
        GameSetup *gameSetup;
        GamePage *gamePage;
        BoardComponent *boardComponent;
        PawnPromotion *pawnPromotion;
        EndOfTheGame *endOfTheGame;
        StockfishWrapper *stockfish;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    ScopedPointer<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (TimoChessApplication)
