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
        for (int n = 0; n < 8; n++) {
//            addAndMakeVisible(boardCase[l][n] = new DrawableImage());
            boardCase[l][n] = new DrawableImage();
        }
    }
    //[/UserPreSize]

    setSize (800, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

BoardComponent::~BoardComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    closeButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    for (int l= 0 ; l < 8; l++) {
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
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
            if (((l+n) & 0x1) == 0) {
                g.setColour(Colours::white);
            } else {
                g.setColour(Colours::grey);
            }
            g.fillRoundedRectangle (Rectangle<float> (proportionOfWidth (l * .075f + .2f), proportionOfHeight (n * .1f + .1f), proportionOfWidth (0.075f), proportionOfHeight (0.1f)), 2.000f);
        }
    }
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
            if (chessBoard != NULL) {
//                boardCase[l][n]->setTransformToFit(Rectangle<float>(proportionOfWidth (l * .1f + .1f), proportionOfHeight (n * .1f + .1f), proportionOfWidth (0.1f), proportionOfHeight (0.1f)), RectanglePlacement());
                boardCase[l][n]->drawWithin (g, Rectangle<float> (proportionOfWidth (l * .075f + .2f), proportionOfHeight (0.8f - n * .1f ), proportionOfWidth (0.075f), proportionOfHeight (0.1f)),
                               RectanglePlacement::centred, 1.000f);
            }
        }
    }
    //[/UserPaint]
}

void BoardComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
         //   boardCase[l][n]->setBoundingBox(RelativeParallelogram());
//            boardCase[l][n]->setBounds(proportionOfWidth (l * .1f + .1f), proportionOfHeight (n * .1f + .1f), proportionOfWidth (0.1f), proportionOfHeight (0.1f));
        }
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

void BoardComponent::setChessboard(ChessBoard *chessBoard) {
    this->chessBoard = chessBoard;
    for (int l= 0 ; l < 8; l++) {
        for (int n = 0; n < 8; n++) {
            boardCase[l][n]->setImage(chessBoard->getPieceImage(l, n));
        }
    }
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
