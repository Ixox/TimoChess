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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GamePage.h"

// #define GP_DEBUG
//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GamePage::GamePage ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (resetButton = new ImageButton ("reset button"));
    resetButton->setButtonText (TRANS("RESET"));
    resetButton->addListener (this);

    resetButton->setImages (false, true, true,
                            ImageCache::getFromMemory (reset_png, reset_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (whiteMove = new Label ("whiteMove label",
                                              TRANS("C2C4")));
    whiteMove->setFont (Font ("OpenDyslexicAlta", 190.00f, Font::bold));
    whiteMove->setJustificationType (Justification::centredLeft);
    whiteMove->setEditable (false, false, false);
    whiteMove->setColour (Label::textColourId, Colour (0xff266163));
    whiteMove->setColour (TextEditor::textColourId, Colours::black);
    whiteMove->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (blackMove = new Label ("blackMove label",
                                              TRANS("E7E5")));
    blackMove->setFont (Font ("OpenDyslexicAlta", 190.00f, Font::bold));
    blackMove->setJustificationType (Justification::centredLeft);
    blackMove->setEditable (false, false, false);
    blackMove->setColour (Label::textColourId, Colour (0xff266163));
    blackMove->setColour (TextEditor::textColourId, Colours::black);
    blackMove->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (whiteMoveOld = new Label ("whiteMoveOld label",
                                                 TRANS("C2C4\n")));
    whiteMoveOld->setFont (Font ("OpenDyslexicAlta", 120.00f, Font::bold));
    whiteMoveOld->setJustificationType (Justification::centredLeft);
    whiteMoveOld->setEditable (false, false, false);
    whiteMoveOld->setColour (Label::textColourId, Colour (0xff61a5a8));
    whiteMoveOld->setColour (TextEditor::textColourId, Colours::black);
    whiteMoveOld->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (blackMoveOld = new Label ("blackMove label",
                                                 TRANS("E7E5\n")));
    blackMoveOld->setFont (Font ("OpenDyslexicAlta", 120.00f, Font::bold));
    blackMoveOld->setJustificationType (Justification::centredLeft);
    blackMoveOld->setEditable (false, false, false);
    blackMoveOld->setColour (Label::textColourId, Colour (0xff65a4a6));
    blackMoveOld->setColour (TextEditor::textColourId, Colours::black);
    blackMoveOld->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (whitePieceButton = new ImageButton ("white piece button"));
    whitePieceButton->setButtonText (TRANS("white piece"));
    whitePieceButton->addListener (this);

    whitePieceButton->setImages (false, true, true,
                                 ImageCache::getFromMemory (BinaryData::wPawn_png, BinaryData::wPawn_pngSize), 1.000f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (blackPieceButton = new ImageButton ("black piece button"));
    blackPieceButton->setButtonText (TRANS("black piece"));
    blackPieceButton->addListener (this);

    blackPieceButton->setImages (false, true, true,
                                 ImageCache::getFromMemory (BinaryData::bPawn_png, BinaryData::bPawn_pngSize), 1.000f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (boardButton = new ImageButton ("board button"));
    boardButton->addListener (this);

    boardButton->setImages (false, true, false,
                            ImageCache::getFromMemory (showBoard_png, showBoard_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (whiteTakesBlackButton = new ImageButton ("whiteTakesBlack button"));
    whiteTakesBlackButton->setButtonText (TRANS("whiteTakesBlack piece"));
    whiteTakesBlackButton->addListener (this);

    whiteTakesBlackButton->setImages (false, true, true,
                                      Image(), 1.000f, Colour (0x00000000),
                                      Image(), 1.000f, Colour (0x00000000),
                                      Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (blackTakesWhiteButton = new ImageButton ("blackTakesWhite button"));
    blackTakesWhiteButton->setButtonText (TRANS("blackTakesWhite piece"));
    blackTakesWhiteButton->addListener (this);

    blackTakesWhiteButton->setImages (false, true, true,
                                      Image(), 1.000f, Colour (0x00000000),
                                      Image(), 1.000f, Colour (0x00000000),
                                      Image(), 1.000f, Colour (0x00000000));
    drawable1 = Drawable::createFromImageData (BinaryData::human_png, BinaryData::human_pngSize);
    drawable2 = Drawable::createFromImageData (BinaryData::rpi_png, BinaryData::rpi_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 480);


    //[Constructor] You can add your own custom stuff here..
    waitForPromotionChoice = false;
    //[/Constructor]
}

GamePage::~GamePage()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    resetButton = nullptr;
    whiteMove = nullptr;
    blackMove = nullptr;
    whiteMoveOld = nullptr;
    blackMoveOld = nullptr;
    whitePieceButton = nullptr;
    blackPieceButton = nullptr;
    boardButton = nullptr;
    whiteTakesBlackButton = nullptr;
    blackTakesWhiteButton = nullptr;
    drawable1 = nullptr;
    drawable2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GamePage::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff90c9dd));

    g.setGradientFill (ColourGradient (Colour (0xe0ffffff),
                                       static_cast<float> (proportionOfWidth (0.5113f)), static_cast<float> (proportionOfHeight (0.0560f)),
                                       Colour (0x00008000),
                                       static_cast<float> (proportionOfWidth (0.5113f)), static_cast<float> (proportionOfHeight (0.0995f)),
                                       false));
    g.fillRoundedRectangle (static_cast<float> (proportionOfWidth (0.1942f)), static_cast<float> (proportionOfHeight (0.0599f)), static_cast<float> (proportionOfWidth (0.7800f)), static_cast<float> (proportionOfHeight (0.3499f)), 10.000f);

    g.setColour (Colours::white);
    g.drawRoundedRectangle (static_cast<float> (proportionOfWidth (0.1942f)), static_cast<float> (proportionOfHeight (0.0599f)), static_cast<float> (proportionOfWidth (0.7800f)), static_cast<float> (proportionOfHeight (0.3499f)), 10.000f, 5.000f);

    g.setGradientFill (ColourGradient (Colour (0xc0000000),
                                       static_cast<float> (proportionOfWidth (0.5113f)), static_cast<float> (proportionOfHeight (0.4852f)),
                                       Colour (0x00008000),
                                       static_cast<float> (proportionOfWidth (0.5113f)), static_cast<float> (proportionOfHeight (0.5288f)),
                                       false));
    g.fillRoundedRectangle (static_cast<float> (proportionOfWidth (0.1942f)), static_cast<float> (proportionOfHeight (0.4897f)), static_cast<float> (proportionOfWidth (0.7800f)), static_cast<float> (proportionOfHeight (0.3499f)), 10.000f);

    g.setColour (Colours::black);
    g.drawRoundedRectangle (static_cast<float> (proportionOfWidth (0.1942f)), static_cast<float> (proportionOfHeight (0.4897f)), static_cast<float> (proportionOfWidth (0.7800f)), static_cast<float> (proportionOfHeight (0.3499f)), 10.000f, 5.000f);

    g.setColour (Colours::black);
    jassert (drawable1 != 0);
    if (drawable1 != 0)
        drawable1->drawWithin (g, Rectangle<float> (proportionOfWidth (0.0138f), proportionOfHeight (0.1273f), proportionOfWidth (0.1357f), proportionOfHeight (0.2084f)),
                               RectanglePlacement::centred, 1.000f);

    g.setColour (Colours::black);
    jassert (drawable2 != 0);
    if (drawable2 != 0)
        drawable2->drawWithin (g, Rectangle<float> (proportionOfWidth (0.0138f), proportionOfHeight (0.5565f), proportionOfWidth (0.1357f), proportionOfHeight (0.2084f)),
                               RectanglePlacement::centred, 1.000f);

    //[UserPaint] Add your own custom painting code here..
    g.setColour (Colours::lightgreen);
    if (moveError && realPlayerColor == currentPlayerColor) {
        g.setColour (Colours::red);
    }
    if (currentPlayerColor == WHITE) {
        g.drawRoundedRectangle (Rectangle<float> (proportionOfWidth (0.005f), proportionOfHeight (0.02f), proportionOfWidth (0.99f), proportionOfHeight (0.43f)), 6.000f, 10);
    } else {
        g.drawRoundedRectangle (Rectangle<float> (proportionOfWidth (0.005f), proportionOfHeight (0.45f), proportionOfWidth (0.99f), proportionOfHeight (0.43f)), 6.000f, 10);

    }
    //[/UserPaint]
}

void GamePage::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    resetButton->setBounds (proportionOfWidth (0.0039f), proportionOfHeight (0.9946f) - proportionOfHeight (0.0863f), proportionOfWidth (0.0683f), proportionOfHeight (0.0863f));
    whiteMove->setBounds (proportionOfWidth (0.3579f), proportionOfHeight (0.0622f), proportionOfWidth (0.3894f), proportionOfHeight (0.3422f));
    blackMove->setBounds (proportionOfWidth (0.3579f), proportionOfHeight (0.4915f), proportionOfWidth (0.3894f), proportionOfHeight (0.3422f));
    whiteMoveOld->setBounds (proportionOfWidth (0.7500f), proportionOfHeight (0.1431f), proportionOfWidth (0.2227f), proportionOfHeight (0.1967f));
    blackMoveOld->setBounds (proportionOfWidth (0.7500f), proportionOfHeight (0.5537f), proportionOfWidth (0.2188f), proportionOfHeight (0.2100f));
    whitePieceButton->setBounds (proportionOfWidth (0.1962f), proportionOfHeight (0.1120f), proportionOfWidth (0.1500f), proportionOfHeight (0.2364f));
    blackPieceButton->setBounds (proportionOfWidth (0.1967f), proportionOfHeight (0.5474f), proportionOfWidth (0.1500f), proportionOfHeight (0.2302f));
    boardButton->setBounds (proportionOfWidth (0.9243f), proportionOfHeight (0.8958f), proportionOfWidth (0.0669f), proportionOfHeight (0.0933f));
    whiteTakesBlackButton->setBounds (proportionOfWidth (0.2596f), proportionOfHeight (0.2675f), proportionOfWidth (0.0983f), proportionOfHeight (0.1431f));
    blackTakesWhiteButton->setBounds (proportionOfWidth (0.2596f), proportionOfHeight (0.6967f), proportionOfWidth (0.0983f), proportionOfHeight (0.1431f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GamePage::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == resetButton)
    {
        //[UserButtonCode_resetButton] -- add your button handler code here..
        if (this->gameListener != NULL) {
            stopTimer();
            this->gameListener->setup();
        }
        //[/UserButtonCode_resetButton]
    }
    else if (buttonThatWasClicked == whitePieceButton)
    {
        //[UserButtonCode_whitePieceButton] -- add your button handler code here..
        //[/UserButtonCode_whitePieceButton]
    }
    else if (buttonThatWasClicked == blackPieceButton)
    {
        //[UserButtonCode_blackPieceButton] -- add your button handler code here..
        //[/UserButtonCode_blackPieceButton]
    }
    else if (buttonThatWasClicked == boardButton)
    {
        //[UserButtonCode_boardButton] -- add your button handler code here..
         this->gameListener->showBoard(&board);
        //[/UserButtonCode_boardButton]
    }
    else if (buttonThatWasClicked == whiteTakesBlackButton)
    {
        //[UserButtonCode_whiteTakesBlackButton] -- add your button handler code here..
        //[/UserButtonCode_whiteTakesBlackButton]
    }
    else if (buttonThatWasClicked == blackTakesWhiteButton)
    {
        //[UserButtonCode_blackTakesWhiteButton] -- add your button handler code here..
        //[/UserButtonCode_blackTakesWhiteButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

bool GamePage::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...

    if (waitForPromotionChoice) {
        // must be done through the UI
        printf("#GamePage::keyPressed  : Waiting for promotion piece.. Must be done through the UI");
        return false;
    }

    if (key == 'z') {
        this->gameListener->showBoard(&board);
        return true;
    }

    int moveLength = playerCurrentMove.length();
//    printf("Key press : %i / move length : %i \n", key.getKeyCode(), moveLength);

    if (key.getKeyCode() == 8) {
        if (moveLength > 0) {
            playerCurrentMove = playerCurrentMove.substring(0, playerCurrentMove.length() - 1);
            displayPlayerCurrentMove();
            showCurrentMovingPiece(realPlayerColor, playerCurrentMove);
        }
        return true;
    }


    if (moveLength == 0 || moveLength == 2) {
        if (key.getKeyCode() >= 'a' && key.getKeyCode() <= 'h') {
            playerCurrentMove +=  (char) (key.getKeyCode());
        } else if (key.getKeyCode() >= 'a' && key.getKeyCode() <= 'h') {
            playerCurrentMove += (char) (key.getKeyCode() - 'a' + 'A');
        }
    }
    if (moveLength == 1 || moveLength == 3) {
        if (key.getKeyCode() >= '1' && key.getKeyCode() <= '8') {
            playerCurrentMove += (char)key.getKeyCode();
        }
    }

    if (moveLength == playerCurrentMove.length()) {
        return false;
    }

    (*playerMove)->setText(playerCurrentMove, dontSendNotification);
    this->showCurrentMovingPiece(realPlayerColor, playerCurrentMove);

    if (playerCurrentMove.length() >= 4) {

        if (playerCurrentMove.length() == 4 && needsPromotionChoice(playerCurrentMove)) {
            waitForPromotionChoice = true;
            this->gameListener->askForPromotionPiece(realPlayerColor);
        }  else {
            realPlayerMove(playerCurrentMove);
        }
    }

    return true;
    // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


void GamePage::realPlayerMove(String playerCurrentMove) {
    // Here playerCurrentMove must be valid
    stockfish->addMove(playerCurrentMove);
    // Check validity
    // printf("Quick move to check validity: bestmove....\n");
    stockfish->startSearchingBestMoveInMillis(50);
    String bestmove = "";

    while (bestmove.length() == 0) {
        bestmove = stockfish->checkBestMove();
    }
    // printf(">> Quick move to check validity: bestmove : '%s'\n", bestmove.toRawUTF8());

    // Call after player moves to check validity
    if (bestmove == "(none)") {
        // Real player won ? Or slatemate ?
        stopTimer();
        Color winner = (stockfish->getMate() == 0) ? realPlayerColor : NOCOLOR;
        gameListener->gameFinished(winner, realPlayerColor, "");
        return;
    }

    // If stockfish move our color, it means previous move was illegal
    Color validityTest = board.getColor(bestmove);
    if (validityTest == this->currentPlayerColor || validityTest == NOCOLOR) {
        printf("## STOCKFISH MOVE OUR COLOR, LAST MOVE WAS WRONG !!!!!\n");
        stockfish->cancelLastMove();
        playerCurrentMove.clear();
        displayPlayerCurrentMove();
        cleanPieceImages(realPlayerColor);
        // move error must be called here (not before)
        this->setMoveError(true);
        this->repaint();
    } else {
        // Every thing is fine :)
        showEventualTakenPiece(currentPlayerColor, playerCurrentMove);
        board.move(playerCurrentMove);

        // now computer must play
        currentPlayerColor = currentPlayerColor == WHITE ? BLACK : WHITE;
        this->cleanPieceImages(currentPlayerColor);
        stockfish->startSearchingBestMove();
        (*computerMoveOld)->setText((*computerMove)->getText(), dontSendNotification);
        repaint();
    }
}

bool GamePage::needsPromotionChoice(String playerCurrentMove) {
    char numberDest = playerCurrentMove.toRawUTF8()[3];
    return board.getPiece(playerCurrentMove) == PAWN && (numberDest == '1' || numberDest == '8');
}

void GamePage::setPromotionChoice(Piece piece) {
    waitForPromotionChoice = false;
    switch (piece) {
        case QUEEN:
            playerCurrentMove += 'q';
            break;
        case ROCK:
            playerCurrentMove += 'r';
            break;
        case BISHOP:
            playerCurrentMove += 'b';
            break;
        case KNIGHT:
            playerCurrentMove += 'n';
            break;
        default:
            printf("## Cannot promote to %i default to Queen\n", (int)piece);
            playerCurrentMove += 'q';
            break;
    }
    if (playerCurrentMove.length() == 5) {
        printf(">>  setPromotionChoice : player current move promotion : %s\n", playerCurrentMove.toRawUTF8());
        realPlayerMove(playerCurrentMove);
    } else {
        printf("## player current move is wrong after promotion : %s\n", playerCurrentMove.toRawUTF8());
    }
}

void GamePage::displayPlayerCurrentMove() {
    if (playerCurrentMove.length() > 0) {
        (*playerMove)->setText(playerCurrentMove, dontSendNotification);
    } else {
        (*playerMove)->setText("????", dontSendNotification);
    }
}

void GamePage::timerCallback() {
    static int cpt = 0;
    ticTac++;

    if (currentPlayerColor != realPlayerColor) {
        // computer is thinking

        String bestMove = stockfish->checkBestMove();
        if (bestMove.length() > 0) {
#ifdef GP_DEBUG            
            printf(">> GamePage::timerCallback computer moved : %s \n", bestMove.toRawUTF8());
            printf(">> GamePage::getMate : %i \n", stockfish->getMate());
            printf(">> GamePage::getPonder : %s \n", stockfish->getPonder().toRawUTF8());
#endif
            // printf("Ponder >>>>>>>>>> %s \n", stockfish->getPonder().toRawUTF8());
            if (stockfish->getPonder().length() == 0) {
                // Compute wins ?
                if (stockfish->getMate() == 1) {
                    stopTimer();
                    gameListener->gameFinished(currentPlayerColor, realPlayerColor, bestMove + " : ");
                    return;
                } else {
                    // No ponder => means Slatemate
                    stopTimer();
                    gameListener->gameFinished(NOCOLOR, realPlayerColor, bestMove + " : ");
                    return;
                }
            }
            
            // Length 5 means pawn promotion
            if (bestMove.length() == 5) {
                pawnPromotion(bestMove);
            }
            (*computerMove)->setText(bestMove.toLowerCase(), dontSendNotification);

            showCurrentMovingPiece(currentPlayerColor, bestMove.substring(0,2));
            showEventualTakenPiece(currentPlayerColor, bestMove);

            stockfish->addMove(bestMove);
            board.move(bestMove);

            currentPlayerColor = currentPlayerColor == WHITE ? BLACK : WHITE;
            repaint();

            (*playerMoveOld)->setText(playerCurrentMove, dontSendNotification);
            playerCurrentMove.clear();
            displayPlayerCurrentMove();
            cleanPieceImages(currentPlayerColor);

        } else {
            char thinking[5] = {'.', '.', '.', '.', 0};
            thinking[ticTac % 4] = '?';
            (*computerMove)->setText(String::fromUTF8(thinking), dontSendNotification);
        }
    }
}


void GamePage::pawnPromotion(String move) {
    printf(">> GamePage::pawnPromotion\n");
    Piece piece = NOPIECE;
    switch (move[4]) {
        case 'q':
            piece = QUEEN;
            break;
        case 'n':
            piece = KNIGHT;
            break;
        case 'b':
            piece = BISHOP;
            break;
        case 'r':
            piece = ROCK;
            break;
    }
    if (piece == NOPIECE)  {
       printf("# GamePage::pawnPromotion : unknown piece : %s \n", move.toRawUTF8());
    } else  {
        board.promotePawnTo(move, piece);
    }
}


void GamePage::setMoveError(bool error) {
    if (this->moveError != error) {
        repaint();
    }
    this->moveError = error;
}



void GamePage::cleanPieceImages(Color color) {
    ScopedPointer<ImageButton> *imageToUpdate, *imageToUpdate2;
    if (color == WHITE) {
        imageToUpdate = &whitePieceButton;
        imageToUpdate2 = &whiteTakesBlackButton;
    } else {
        imageToUpdate = &blackPieceButton;
        imageToUpdate2 = &blackTakesWhiteButton;
    }
    (*imageToUpdate)->setImages (false, true, true,
                    Image(), 1.000f, Colour (0x00000000),
                    Image(), 1.000f, Colour (0x00000000),
                    Image(), 1.000f, Colour (0x00000000));
    (*imageToUpdate2)->setImages (false, true, true,
                    Image(), 1.000f, Colour (0x00000000),
                    Image(), 1.000f, Colour (0x00000000),
                    Image(), 1.000f, Colour (0x00000000));

}

void GamePage::showEventualTakenPiece(Color color, String move) {
    ScopedPointer<ImageButton> *imageToUpdate;

    if (color == WHITE) {
        imageToUpdate = &whiteTakesBlackButton;
    } else {
        imageToUpdate = &blackTakesWhiteButton;
    }

    if (move.length() >= 4) {
        // Do we take a piece??

        Image movingPiece = board.getPieceImage(move.substring(2,4));
        (*imageToUpdate)->setImages (false, true, true,
                        movingPiece, 0.500f, Colour (0x00000000),
                        Image(), 1.000f, Colour (0x00000000),
                        Image(), 1.000f, Colour (0x00000000));


    }


}

void GamePage::showCurrentMovingPiece(Color color, String move) {
    ScopedPointer<ImageButton> *imageToUpdate;

    if (color == WHITE) {
        imageToUpdate = &whitePieceButton;
    } else {
        imageToUpdate = &blackPieceButton;
    }


    if (move.length() < 2) {
        setMoveError(false);
        (*imageToUpdate)->setImages (false, true, true,
                Image(), 1.000f, Colour (0x00000000),
                Image(), 1.000f, Colour (0x00000000),
                Image(), 1.000f, Colour (0x00000000));

        return;
    }

    if (move.length() == 2) {
        // Display the piece
        if (color == this->currentPlayerColor && board.getColor(move) != this->currentPlayerColor) {
            setMoveError(true);
            playerCurrentMove.clear();
            displayPlayerCurrentMove();
        } else {
            setMoveError(false);
        }

        Image movingPiece = board.getPieceImage(move);
        (*imageToUpdate)->setImages (false, true, true,
                        movingPiece, 1.000f, Colour (0x00000000),
                        Image(), 1.000f, Colour (0x00000000),
                        Image(), 1.000f, Colour (0x00000000));


    }
}


void GamePage::setGameListener(GameListener *gl) {
    this->gameListener = gl;
}

void GamePage::setStockfish(StockfishWrapper *stockfish) {
    this->stockfish = stockfish;
}

void GamePage::start(Color realPlayerColor) {

    // First player is always WHITE
    this->currentPlayerColor = WHITE;
    this->realPlayerColor = realPlayerColor;
    this->stockfish->startGame();

    ticTac = 0;
    startTimer(250);

    if (this->realPlayerColor == BLACK) {
        // Computer starts !!
        stockfish->startSearchingBestMove();
        drawable2 = Drawable::createFromImageData (BinaryData::human_png, BinaryData::human_pngSize);
        drawable1 = Drawable::createFromImageData (BinaryData::rpi_png, BinaryData::rpi_pngSize);
        playerMove = &blackMove;
        playerMoveOld = &blackMoveOld;
        computerMove = &whiteMove;
        computerMoveOld = &whiteMoveOld;
    } else {
        drawable1 = Drawable::createFromImageData (BinaryData::human_png, BinaryData::human_pngSize);
        drawable2 = Drawable::createFromImageData (BinaryData::rpi_png, BinaryData::rpi_pngSize);
        playerMove = &whiteMove;
        playerMoveOld = &whiteMoveOld;
        computerMove = &blackMove;
        computerMoveOld = &blackMoveOld;
    }

    this->showCurrentMovingPiece(WHITE, "");
    this->showCurrentMovingPiece(BLACK, "");

    if (this->stockfish->getStartingFen().length() > 0) {
        board.initWithFen(this->stockfish->getStartingFen());
    } else {
        if (stockfish->getVariant() == RACING_KINGS) {
            board.initRacingKings();
        } else {
            board.init();
        }
    }

    playerCurrentMove.clear();
    displayPlayerCurrentMove();
    if (this->realPlayerColor == BLACK) {
        (*playerMove)->setText("", dontSendNotification);
    }
    (*computerMove)->setText("", dontSendNotification);
    (*playerMoveOld)->setText("", dontSendNotification);
    (*computerMoveOld)->setText("", dontSendNotification);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GamePage" componentName=""
                 parentClasses="public Component, public Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="800" initialHeight="480">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff90c9dd">
    <ROUNDRECT pos="19.42% 5.988% 78% 34.992%" cornerSize="10" fill="linear: 51.131% 5.599%, 51.131% 9.953%, 0=e0ffffff, 1=8000"
               hasStroke="1" stroke="5, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="19.42% 48.966% 78% 34.992%" cornerSize="10" fill="linear: 51.131% 48.523%, 51.131% 52.877%, 0=c0000000, 1=8000"
               hasStroke="1" stroke="5, mitered, butt" strokeColour="solid: ff000000"/>
    <IMAGE pos="1.377% 12.729% 13.569% 20.84%" resource="BinaryData::human_png"
           opacity="1" mode="1"/>
    <IMAGE pos="1.377% 55.653% 13.569% 20.84%" resource="BinaryData::rpi_png"
           opacity="1" mode="1"/>
  </BACKGROUND>
  <IMAGEBUTTON name="reset button" id="34eb5f3819ff3fda" memberName="resetButton"
               virtualName="" explicitFocusOrder="0" pos="0.393% 99.456%r 6.834% 8.631%"
               buttonText="RESET" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="reset_png" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="" opacityDown="1" colourDown="0"/>
  <LABEL name="whiteMove label" id="49edb2e62c665264" memberName="whiteMove"
         virtualName="" explicitFocusOrder="0" pos="35.792% 6.221% 38.938% 34.215%"
         textCol="ff266163" edTextCol="ff000000" edBkgCol="0" labelText="C2C4"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="OpenDyslexicAlta" fontsize="190" bold="1" italic="0"
         justification="33"/>
  <LABEL name="blackMove label" id="4ee3256afca77a83" memberName="blackMove"
         virtualName="" explicitFocusOrder="0" pos="35.792% 49.145% 38.938% 34.215%"
         textCol="ff266163" edTextCol="ff000000" edBkgCol="0" labelText="E7E5"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="OpenDyslexicAlta" fontsize="190" bold="1" italic="0"
         justification="33"/>
  <LABEL name="whiteMoveOld label" id="a1067eed02d5360f" memberName="whiteMoveOld"
         virtualName="" explicitFocusOrder="0" pos="75.025% 14.308% 22.271% 19.673%"
         textCol="ff61a5a8" edTextCol="ff000000" edBkgCol="0" labelText="C2C4&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="OpenDyslexicAlta" fontsize="120" bold="1" italic="0"
         justification="33"/>
  <LABEL name="blackMove label" id="7b9defce5f0efb46" memberName="blackMoveOld"
         virtualName="" explicitFocusOrder="0" pos="75.025% 55.365% 21.878% 20.995%"
         textCol="ff65a4a6" edTextCol="ff000000" edBkgCol="0" labelText="E7E5&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="OpenDyslexicAlta" fontsize="120" bold="1" italic="0"
         justification="33"/>
  <IMAGEBUTTON name="white piece button" id="885cfc3610012de7" memberName="whitePieceButton"
               virtualName="" explicitFocusOrder="0" pos="19.617% 11.198% 14.995% 23.639%"
               buttonText="white piece" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wPawn_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="black piece button" id="110fca52e356decf" memberName="blackPieceButton"
               virtualName="" explicitFocusOrder="0" pos="19.666% 54.743% 14.995% 23.017%"
               buttonText="black piece" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::bPawn_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="board button" id="26ef0dc5c974563e" memberName="boardButton"
               virtualName="" explicitFocusOrder="0" pos="92.429% 89.58% 6.686% 9.331%"
               buttonText="board button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="0" resourceNormal="showBoard_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="whiteTakesBlack button" id="96d88a1472cc9d50" memberName="whiteTakesBlackButton"
               virtualName="" explicitFocusOrder="0" pos="25.959% 26.75% 9.833% 14.308%"
               buttonText="whiteTakesBlack piece" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="blackTakesWhite button" id="33d361b30d19dc35" memberName="blackTakesWhiteButton"
               virtualName="" explicitFocusOrder="0" pos="25.959% 69.673% 9.833% 14.308%"
               buttonText="blackTakesWhite piece" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="" opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: reset_png, 1249, "../../../Pictures/reset.png"
static const unsigned char resource_GamePage_reset_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,167,8,6,0,0,0,84,250,19,17,0,0,0,6,98,75,71,68,0,213,0,241,0,188,206,135,173,
22,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,225,2,27,21,40,16,182,19,62,44,0,0,0,25,116,69,88,116,67,111,109,109,101,110,116,0,67,114,101,97,116,101,100,32,119,105,
116,104,32,71,73,77,80,87,129,14,23,0,0,4,73,73,68,65,84,120,218,237,221,97,110,212,64,12,6,208,77,196,101,218,251,159,101,57,78,249,131,132,132,84,104,179,201,196,159,253,190,3,208,141,61,111,60,19,232,
242,120,136,136,136,28,201,166,4,175,229,231,251,251,199,217,127,230,219,243,169,47,128,192,0,14,32,32,128,3,8,20,176,0,2,5,40,128,128,1,138,140,5,50,9,6,44,128,64,1,11,32,96,128,2,8,24,144,0,2,7,40,128,
64,1,10,32,112,64,2,8,28,2,74,30,16,48,32,1,4,14,80,0,1,3,18,64,224,128,4,16,56,64,1,4,14,25,136,100,3,67,32,249,60,187,246,138,77,45,100,130,152,30,38,9,32,112,64,2,8,24,144,0,2,135,180,71,178,79,132,
41,54,191,242,11,213,244,48,73,0,25,130,227,204,69,208,113,227,72,70,178,193,81,187,225,190,241,113,16,144,228,102,87,104,176,250,53,6,146,218,220,138,141,85,75,64,52,82,109,231,0,73,105,96,250,27,23,
117,14,4,146,208,180,78,127,243,171,222,65,64,52,11,148,244,186,143,4,50,233,87,70,43,67,73,232,195,6,7,36,250,241,121,70,253,194,212,212,239,119,122,123,62,55,223,148,88,104,130,84,220,177,44,16,189,
41,49,65,52,192,20,53,65,66,128,88,12,57,27,89,213,94,237,112,152,36,178,96,130,192,97,146,116,236,91,187,183,88,112,168,87,185,9,82,101,23,210,108,61,52,65,224,104,93,191,106,47,15,124,179,162,216,100,
174,4,82,65,188,198,170,165,9,162,161,106,154,6,228,238,233,161,145,94,24,152,32,98,243,1,68,3,165,230,20,217,19,31,0,14,117,54,65,100,60,146,10,83,100,79,251,224,118,53,49,65,196,20,1,68,163,164,254,
49,203,4,17,155,83,7,32,166,135,68,0,241,31,223,200,164,99,86,196,4,49,61,244,1,16,17,64,196,20,105,12,228,142,179,160,227,149,152,32,34,128,152,30,142,89,199,115,215,155,172,31,218,221,43,157,95,195,
175,120,182,191,241,239,10,47,242,249,58,119,7,17,113,73,23,185,248,136,37,46,208,38,136,136,205,5,16,83,68,226,39,136,38,171,95,133,122,125,9,136,87,188,144,76,173,147,35,22,36,234,227,146,46,114,108,
243,0,196,66,16,64,4,146,99,245,0,196,162,80,7,64,4,146,99,207,15,136,192,1,136,152,34,46,233,2,201,233,207,11,8,36,158,243,85,32,70,178,197,51,245,249,202,78,16,255,254,11,146,10,207,229,136,37,45,145,
156,245,60,128,136,0,34,147,166,200,153,207,1,136,180,66,114,246,231,7,68,218,32,185,226,115,239,221,139,38,51,144,92,245,121,77,16,129,57,21,136,191,11,49,69,238,142,9,34,209,72,174,254,124,128,72,44,
146,21,159,235,219,63,192,255,50,53,55,149,142,188,171,214,132,9,34,38,90,58,16,151,117,71,173,152,75,186,227,14,36,147,126,126,204,17,203,20,129,228,142,159,235,14,34,17,139,245,46,148,128,8,140,93,128,
56,102,89,184,128,8,36,133,16,30,254,225,119,238,230,222,164,205,152,238,21,250,188,107,134,84,92,204,85,54,193,45,121,161,154,36,61,55,175,74,125,117,7,17,23,255,171,128,220,253,48,142,90,22,184,9,178,
224,168,40,53,144,84,196,117,202,7,114,23,145,87,215,69,213,30,238,211,26,33,245,54,174,202,27,220,190,178,16,144,72,218,244,111,245,22,11,146,44,0,9,71,99,175,121,229,22,36,41,247,198,83,63,228,196,223,
89,150,222,105,59,65,28,183,212,168,28,144,106,187,182,5,160,54,165,142,88,85,139,239,184,245,239,254,168,207,112,32,22,193,255,251,162,62,11,129,84,30,225,83,23,194,87,250,1,201,160,75,186,179,247,159,
231,117,223,40,56,65,18,22,99,247,29,243,72,253,77,145,133,64,82,118,236,110,139,226,213,154,67,178,16,72,210,177,38,125,97,156,89,103,72,134,222,65,58,222,79,220,51,194,39,72,226,226,75,216,65,175,174,
233,239,26,108,143,199,227,3,16,72,98,176,172,172,227,244,163,22,32,197,23,77,133,154,77,70,178,252,193,59,158,149,207,94,64,254,37,194,96,32,93,145,124,103,113,57,106,2,2,201,0,232,128,64,34,195,145,
248,178,5,129,164,50,16,72,32,1,4,18,72,66,179,43,182,72,192,4,49,73,76,17,19,68,193,197,4,49,73,76,15,64,32,129,195,91,44,80,100,250,17,56,230,97,33,129,3,16,80,224,0,4,18,48,0,1,5,14,64,32,1,3,16,80,
224,0,4,18,48,192,104,15,4,22,48,0,129,4,12,64,64,1,3,16,80,192,0,4,24,40,0,129,5,10,64,96,129,2,16,9,193,2,5,32,176,64,33,34,34,34,34,34,50,42,191,0,39,27,226,152,11,99,251,124,0,0,0,0,73,69,78,68,174,
66,96,130,0,0};

const char* GamePage::reset_png = (const char*) resource_GamePage_reset_png;
const int GamePage::reset_pngSize = 1249;

// JUCER_RESOURCE: showBoard_png, 2245, "images/ShowBoard.png"
static const unsigned char resource_GamePage_showBoard_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,179,0,0,0,144,8,2,0,0,0,204,78,205,60,0,0,0,9,112,72,89,115,0,0,18,38,0,0,17,254,1,
92,10,120,28,0,0,0,7,116,73,77,69,7,225,3,6,21,29,44,164,94,38,239,0,0,0,25,116,69,88,116,67,111,109,109,101,110,116,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77,80,87,129,14,23,0,0,8,63,
73,68,65,84,120,218,237,221,127,72,83,253,2,199,241,239,247,156,230,218,252,145,57,179,150,226,20,50,179,196,208,212,82,12,49,164,186,65,244,59,82,104,81,82,94,93,4,82,120,255,232,74,81,66,127,212,147,
97,73,89,70,204,39,34,84,48,203,32,19,42,18,20,175,162,145,55,197,44,239,230,205,220,125,220,169,212,230,143,157,185,115,255,56,183,221,120,188,229,242,62,134,95,253,188,254,144,179,237,124,183,195,217,
155,179,157,169,251,210,172,95,10,254,170,223,191,212,95,67,88,240,222,42,228,151,254,218,222,222,30,183,56,192,203,67,193,196,54,127,182,139,77,255,250,109,229,202,149,108,237,103,250,222,106,213,106,
216,216,92,89,159,32,20,20,20,120,42,20,12,109,179,77,20,115,114,114,216,218,207,28,91,155,75,8,209,106,52,108,101,65,8,241,84,40,152,219,207,28,1,64,25,128,50,0,101,0,202,0,148,1,40,3,80,6,160,12,64,
25,128,50,0,101,0,160,12,64,25,128,50,0,101,0,202,0,148,1,40,3,80,6,160,12,64,25,128,50,0,101,0,160,12,64,25,128,50,0,101,0,202,0,148,1,40,3,80,6,160,12,64,25,128,50,0,101,0,160,12,64,25,128,50,0,101,
0,202,0,148,1,40,3,24,42,163,79,16,216,218,226,62,65,176,137,34,91,219,108,19,69,230,246,51,63,188,88,187,38,124,185,151,74,197,74,22,103,141,191,190,248,135,41,64,173,242,224,121,86,178,248,155,229,183,
142,247,125,108,237,103,154,156,113,24,115,133,76,43,70,231,100,225,247,110,249,19,43,155,75,8,241,224,249,0,181,234,47,127,206,100,37,11,66,136,183,90,29,179,60,236,159,127,111,99,107,63,115,152,43,228,
39,96,113,78,22,156,155,0,202,0,148,1,40,3,80,6,160,12,64,25,128,50,0,101,0,202,0,148,1,40,3,0,101,0,202,0,148,1,40,3,80,6,160,12,64,25,128,50,0,101,0,202,0,148,1,40,3,0,101,0,202,0,148,1,40,3,80,6,160,
12,64,25,128,50,0,101,0,202,0,148,1,40,3,0,101,0,202,0,148,1,40,3,80,6,160,12,64,25,192,84,25,152,43,228,39,96,113,78,22,94,177,124,5,230,10,153,238,44,88,156,147,133,102,253,82,128,185,66,166,21,163,
115,178,208,247,86,43,91,147,66,244,9,66,65,65,1,91,147,66,216,68,49,39,39,135,173,253,204,97,174,144,159,128,197,57,89,112,110,2,40,3,80,6,160,140,57,255,252,113,28,199,77,203,147,56,15,59,151,105,146,
36,225,152,1,255,213,220,220,76,41,165,148,202,23,229,229,230,230,102,28,51,230,186,216,216,216,216,216,88,57,17,249,162,235,39,202,152,235,154,154,154,228,163,133,107,25,175,38,128,115,19,248,174,71,
143,30,201,11,53,53,53,56,55,129,255,8,9,9,49,155,205,242,242,230,205,155,117,58,157,201,100,194,49,99,174,187,122,245,170,43,11,153,217,108,190,126,253,58,202,152,235,178,179,179,39,94,153,153,153,137,
87,147,217,207,110,183,215,212,212,84,85,85,121,122,122,238,219,183,111,237,218,181,63,250,89,231,139,23,47,42,43,43,223,190,125,155,144,144,176,117,235,214,224,224,96,28,51,216,54,62,62,78,41,85,42,149,
185,185,185,22,139,165,165,165,37,41,41,137,231,121,74,233,221,187,119,39,29,254,250,245,107,121,229,232,232,104,163,209,40,8,66,101,101,229,138,21,43,40,165,39,78,156,192,49,131,85,38,147,41,52,52,84,
16,4,63,63,191,223,221,212,213,213,21,19,19,147,150,150,102,181,90,191,53,220,207,207,239,227,199,143,187,118,237,42,43,43,155,120,140,49,26,141,60,207,143,143,143,227,152,193,158,208,208,80,73,146,252,
252,252,170,170,170,180,90,45,165,84,173,86,199,197,197,13,12,12,132,133,133,13,13,13,125,248,240,193,223,223,255,91,195,121,158,151,36,169,162,162,130,227,184,162,162,34,157,78,71,41,85,40,20,49,49,49,
162,40,30,56,112,64,20,69,222,189,191,69,69,25,51,43,11,167,211,41,63,193,219,183,111,183,88,44,132,144,145,145,145,230,230,102,95,95,95,74,233,181,107,215,22,46,92,40,73,210,198,141,27,39,14,175,173,
173,237,239,239,39,132,200,175,29,71,143,30,237,233,233,33,132,56,28,142,214,214,86,15,15,15,173,86,203,113,156,40,138,171,86,173,66,25,44,89,191,126,61,165,212,215,215,87,238,99,162,172,172,44,74,169,
195,225,168,169,169,169,173,173,253,250,166,129,129,129,212,212,84,179,217,76,41,237,236,236,252,159,195,45,22,75,80,80,16,199,113,41,41,41,40,131,25,21,21,21,87,174,92,145,159,227,239,175,169,80,40,222,
188,121,147,154,154,90,82,82,34,95,211,208,208,224,227,227,83,94,94,30,18,18,242,253,177,189,189,189,132,144,115,231,206,61,126,252,24,101,176,161,186,186,218,199,199,199,205,149,195,194,194,44,22,75,
70,70,70,100,100,100,114,114,242,186,117,235,154,154,154,246,238,221,235,230,112,111,111,239,198,198,70,156,155,176,97,254,252,249,63,180,190,86,171,149,36,169,173,173,77,190,24,31,31,239,254,88,167,211,
25,20,20,132,99,6,27,210,210,210,58,58,58,126,104,200,210,165,75,229,133,128,128,0,55,135,200,39,38,37,37,37,233,233,233,40,131,13,201,201,201,137,137,137,132,144,83,167,78,185,57,164,175,175,79,94,144,
79,73,220,49,58,58,74,8,201,204,204,84,42,149,40,131,25,59,119,238,28,26,26,58,125,250,244,164,79,219,212,156,57,115,102,222,188,121,37,37,37,239,222,189,195,185,9,75,110,222,188,169,209,104,36,73,26,
29,29,213,233,116,127,236,157,231,231,231,231,229,229,125,250,244,233,246,237,219,129,129,129,40,131,49,118,187,93,126,43,96,50,153,140,70,227,239,110,77,73,73,49,26,141,195,195,195,210,23,242,245,242,
242,224,224,96,113,113,113,82,82,210,196,187,237,234,234,58,121,242,164,213,106,141,136,136,120,246,236,153,59,91,130,50,102,28,167,211,73,41,53,153,76,122,189,94,254,164,252,225,195,135,242,115,255,228,
201,19,189,94,175,82,169,8,33,99,99,99,93,93,93,173,173,173,221,221,221,14,135,67,62,23,61,114,228,72,93,93,157,188,114,121,121,57,33,100,203,150,45,146,36,45,91,182,172,184,184,120,207,158,61,174,183,
38,147,194,89,235,76,36,73,82,122,122,122,125,125,189,201,100,18,190,124,141,204,161,67,135,202,202,202,108,54,219,247,199,46,88,176,64,175,215,23,22,22,238,222,189,219,117,80,241,247,247,47,43,43,123,
250,244,169,251,219,128,99,198,12,117,231,206,29,249,243,239,75,151,46,201,255,78,114,235,214,173,73,179,32,132,12,12,12,92,190,124,153,82,202,113,220,189,123,247,8,33,7,15,30,236,239,239,223,176,97,195,
15,109,0,202,152,185,138,139,139,41,165,57,57,57,132,16,74,233,154,53,107,68,81,148,38,99,179,217,34,34,34,40,165,146,36,237,216,177,131,82,26,25,25,233,250,159,37,247,225,213,100,166,203,200,200,112,
253,126,132,16,226,112,56,58,59,59,27,27,27,235,234,234,186,187,187,5,65,208,104,52,225,225,225,73,73,73,113,113,113,225,225,225,106,181,186,189,189,93,94,121,219,182,109,247,239,223,159,218,227,162,140,
153,43,62,62,222,245,70,225,252,249,243,185,185,185,223,90,243,249,243,231,55,110,220,248,250,154,162,162,162,236,236,236,170,170,42,66,72,105,105,41,202,152,85,134,134,134,108,54,91,96,96,224,196,223,
190,70,69,69,69,69,69,5,6,6,170,213,234,225,225,97,179,217,220,214,214,246,234,213,43,215,10,6,131,193,96,48,44,89,178,164,183,183,215,110,183,163,140,89,165,163,163,195,203,203,75,94,222,191,127,127,
126,126,190,155,127,229,219,211,211,99,48,24,170,171,171,45,22,11,207,243,23,46,92,152,194,163,227,29,232,140,166,80,40,228,207,181,74,75,75,229,44,46,94,188,232,239,239,175,82,169,56,142,163,95,240,60,
175,86,171,3,2,2,228,119,36,193,193,193,15,30,60,144,36,233,243,231,207,83,126,104,148,49,115,25,12,6,187,221,174,82,169,94,190,124,233,138,224,248,241,227,130,32,140,142,142,126,253,205,25,78,167,115,
100,100,164,191,191,255,240,225,195,174,53,205,102,179,167,167,167,36,73,155,54,109,66,25,179,74,104,104,104,94,94,30,165,116,245,234,213,83,24,30,18,18,66,41,45,44,44,140,140,140,68,25,179,205,217,179,
103,7,7,7,53,83,250,198,72,157,78,55,62,62,126,236,216,49,188,154,204,78,222,222,222,86,171,85,146,164,250,250,250,232,232,232,73,215,79,76,76,108,104,104,144,36,201,100,50,253,63,95,225,133,115,19,102,
36,36,36,180,180,180,184,46,142,141,141,13,14,14,218,237,118,165,82,233,227,227,227,225,225,241,199,62,28,202,96,149,82,169,92,180,104,209,244,221,63,94,77,224,27,101,96,174,144,159,128,197,57,89,248,
225,197,90,204,21,50,221,89,176,56,39,203,191,1,139,249,108,139,251,23,157,167,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* GamePage::showBoard_png = (const char*) resource_GamePage_showBoard_png;
const int GamePage::showBoard_pngSize = 2245;


//[EndFile] You can add extra defines here...
//[/EndFile]
