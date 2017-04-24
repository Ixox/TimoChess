/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_1DB0FB510054D7EE__
#define __JUCE_HEADER_1DB0FB510054D7EE__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "GameListener.h"
#include "StockfishWrapper.h"
#include "ChessBoard.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GamePage  : public Component,
                  public Timer,
                  public ButtonListener
{
public:
    //==============================================================================
    GamePage ();
    ~GamePage();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setGameListener(GameListener *gl);
    void setStockfish(StockfishWrapper * stockfishWrapper);
    void start(Color realPlayerColor);
    void timerCallback();
    void setPromotionChoice(Piece piece);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    bool keyPressed (const KeyPress& key) override;

    // Binary resources:
    static const char* reset_png;
    static const int reset_pngSize;
    static const char* showBoard_png;
    static const int showBoard_pngSize;
    static const char* cancel_png;
    static const int cancel_pngSize;
    static const char* cancel_png2;
    static const int cancel_png2Size;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GameListener *gameListener;
    StockfishWrapper * stockfish;
    String playerCurrentMove;
    ChessBoard board;
    void showCurrentMovingPiece(Color color, String move);
    void showEventualTakenPiece(Color color, String move);
    void pawnPromotion(String move);
    void cleanPieceImages(Color color);
    void setMoveError(bool error);
    void displayPlayerCurrentMove();
    bool needsPromotionChoice(String move);
    void realPlayerMove(String playerCurrentMove);
    void cancelPreviousTurn();
    bool moveError;
    Color currentPlayerColor;
    Color realPlayerColor;
    int ticTac;
    int waitTillTicTac;
    ScopedPointer<Label> *playerMove;
    ScopedPointer<Label> *playerMoveOld;
    ScopedPointer<Label> *computerMove;
    ScopedPointer<Label> *computerMoveOld;
    bool waitForPromotionChoice;
    bool waitForPlayerToMoveComputerPiece;
    bool playerAskedToCancelPreviousTurn;
    bool playerCanAskToCancelPreviousTurn;
    String playerMovesComputerPiece;
    String computerBestMove;
    int turnNumber;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> resetButton;
    ScopedPointer<Label> whiteMove;
    ScopedPointer<Label> blackMove;
    ScopedPointer<Label> whiteMoveOld;
    ScopedPointer<Label> blackMoveOld;
    ScopedPointer<ImageButton> whitePieceButton;
    ScopedPointer<ImageButton> blackPieceButton;
    ScopedPointer<ImageButton> boardButton;
    ScopedPointer<ImageButton> whiteTakesBlackButton;
    ScopedPointer<ImageButton> blackTakesWhiteButton;
    ScopedPointer<ImageButton> cancelButton;
    ScopedPointer<Drawable> drawable1;
    ScopedPointer<Drawable> drawable2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GamePage)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1DB0FB510054D7EE__
