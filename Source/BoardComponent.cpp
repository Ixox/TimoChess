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

#include "BoardComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
BoardComponent::BoardComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (closeButton = new TextButton ("close button"));
    closeButton->setButtonText (TRANS("Close"));
    closeButton->addListener (this);
    closeButton->setColour (TextButton::buttonColourId, Colour (0xff8ec7c9));


    //[UserPreSize]
    for (int l = 0 ; l < 8; l++) {
       
        const char letter[2] = { (char)('A' + l), 0};
        const char number[2] = { (char)('1' + l), 0 };

        addAndMakeVisible (numberLabel[l] = new Label("Number" + (char)('1'+ l), number));
        numberLabel[l]->setFont (Font ("OpenDyslexicAlta", 50.00f, Font::bold));
        numberLabel[l]->setJustificationType (Justification::centredTop);
        numberLabel[l]->setEditable (false, false, false);
        numberLabel[l]->setColour (Label::textColourId, Colour (0xffffffff));
        numberLabel[l]->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

        addAndMakeVisible (letterLabel[l] = new Label("Letter" + (char)('A'+ l), letter));
        letterLabel[l]->setFont (Font ("OpenDyslexicAlta", 50.00f, Font::bold));
        letterLabel[l]->setJustificationType (Justification::centredTop);
        letterLabel[l]->setEditable (false, false, false);
        letterLabel[l]->setColour (Label::textColourId, Colour (0xffffffff));
        letterLabel[l]->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

        for (int n = 0; n < 8; n++) {
//            addAndMakeVisible(boardCase[l][n] = new DrawableImage());
            boardCase[l][n] = new DrawableImage();
        }
    }
    //[/UserPreSize]

    setSize (800, 480);


    //[Constructor] You can add your own custom stuff here..
    computerMove = "";
    //[/Constructor]
}

BoardComponent::~BoardComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    closeButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    for (int l= 0 ; l < 8; l++) {
        letterLabel[l] = nullptr;
        numberLabel[l] = nullptr;
        for (int n = 0; n < 8; n++) {
            boardCase[l][n] = nullptr;
        }
    }
    //[/Destructor]
}

//==============================================================================
void BoardComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1f5557));

    //[UserPaint] Add your own custom painting code here..

    float caseHeight = .1125f;
    float caseWidth = .08f;
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
            char currentCaseString[3];
            currentCaseString[0] = (char)('a' + l);
            currentCaseString[1] = (char)('8' - n);
            currentCaseString[2] = '\0';

            if (computerMove.contains(currentCaseString)) {
                g.setColour(Colours::red);
            } else if (((l+n) & 0x1) == 0) {
                g.setColour(Colours::white);
            } else {
                g.setColour(Colours::grey);
            }
            g.fillRoundedRectangle (Rectangle<float> (proportionOfWidth (l *  caseWidth + .12f), proportionOfHeight (.02f + n * caseHeight ), proportionOfWidth ( caseWidth), proportionOfHeight (caseHeight)), 2.000f);
        }
    }
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
            if (chessBoard != NULL) {
                boardCase[l][n]->drawWithin (g, Rectangle<float> (proportionOfWidth (l *  caseWidth + .12f), proportionOfHeight (.02f + (7.0f * caseHeight) - caseHeight *  n ), proportionOfWidth ( caseWidth), proportionOfHeight (caseHeight)),
                               RectanglePlacement::centred, 1.000f);
            }
        }
    }
    //[/UserPaint]
}

void BoardComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    float caseHeight = .1125f;
    float caseWidth = .08f;
    for (int n = 0; n < 8; n++) {
        numberLabel[n]->setBounds(proportionOfWidth (.048f), proportionOfHeight (.03f + (7.0f * caseHeight) - caseHeight *  n ), proportionOfWidth (caseWidth), proportionOfHeight (caseHeight));
    }
    for (int l= 0 ; l < 8; l++) {
        letterLabel[l]->setBounds(proportionOfWidth (l *  caseWidth + .12f), proportionOfHeight (.905f ), proportionOfWidth ( caseWidth), proportionOfHeight (caseHeight));
    }
    //[/UserPreResize]

    closeButton->setBounds (proportionOfWidth (0.8732f), proportionOfHeight (0.8212f), proportionOfWidth (0.1062f), proportionOfHeight (0.1617f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void BoardComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == closeButton)
    {
        //[UserButtonCode_closeButton] -- add your button handler code here..
        gameListener->resumeGame();
        //[/UserButtonCode_closeButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

bool BoardComponent::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
    if (key == 'z') {
        gameListener->resumeGame();
    }

    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void BoardComponent::setGameListener(GameListener *gl) {
    this->gameListener = gl;
}

void BoardComponent::setChessboard(ChessBoard *chessBoard, String computerMove) {
    this->chessBoard = chessBoard;
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
            boardCase[l][n]->setImage(chessBoard->getPieceImage(l, n));
        }
    }
    this->computerMove = computerMove;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="BoardComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="480">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff1f5557"/>
  <TEXTBUTTON name="close button" id="e04b78e940ac28c6" memberName="closeButton"
              virtualName="" explicitFocusOrder="0" pos="87.316% 82.115% 10.619% 16.174%"
              bgColOff="ff8ec7c9" buttonText="Close" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
