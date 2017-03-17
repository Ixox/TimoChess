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
#include "GameListener.h"
#include "ChessBoard.h"
//[/Headers]

#include "PawnPromotion.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PawnPromotion::PawnPromotion ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (queenButton = new ImageButton ("queen button"));
    queenButton->addListener (this);

    queenButton->setImages (false, true, true,
                            ImageCache::getFromMemory (BinaryData::wQueen_png, BinaryData::wQueen_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (rockButton = new ImageButton ("rock button"));
    rockButton->addListener (this);

    rockButton->setImages (false, true, true,
                           ImageCache::getFromMemory (BinaryData::wRock_png, BinaryData::wRock_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (bishopButton = new ImageButton ("bishop button"));
    bishopButton->addListener (this);

    bishopButton->setImages (false, true, true,
                             ImageCache::getFromMemory (BinaryData::wBishop_png, BinaryData::wBishop_pngSize), 1.000f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (knightButton = new ImageButton ("knight button"));
    knightButton->addListener (this);

    knightButton->setImages (false, true, true,
                             ImageCache::getFromMemory (BinaryData::wKnight_png, BinaryData::wKnight_pngSize), 1.000f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (promotionLabel = new Label ("promotion label",
                                                   TRANS("Promotion du pion")));
    promotionLabel->setFont (Font ("OpenDyslexicAlta", 80.00f, Font::bold));
    promotionLabel->setJustificationType (Justification::centred);
    promotionLabel->setEditable (false, false, false);
    promotionLabel->setColour (TextEditor::textColourId, Colours::black);
    promotionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (aLetter = new Label ("A label",
                                            TRANS("a")));
    aLetter->setFont (Font (120.00f, Font::plain));
    aLetter->setJustificationType (Justification::centred);
    aLetter->setEditable (false, false, false);
    aLetter->setColour (TextEditor::textColourId, Colours::black);
    aLetter->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bLetter = new Label ("B label",
                                            TRANS("b")));
    bLetter->setFont (Font (120.00f, Font::plain));
    bLetter->setJustificationType (Justification::centred);
    bLetter->setEditable (false, false, false);
    bLetter->setColour (TextEditor::textColourId, Colours::black);
    bLetter->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (cLetter = new Label ("C label",
                                            TRANS("c")));
    cLetter->setFont (Font (120.00f, Font::plain));
    cLetter->setJustificationType (Justification::centred);
    cLetter->setEditable (false, false, false);
    cLetter->setColour (TextEditor::textColourId, Colours::black);
    cLetter->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (dLetter = new Label ("D label",
                                            TRANS("d")));
    dLetter->setFont (Font (120.00f, Font::plain));
    dLetter->setJustificationType (Justification::centred);
    dLetter->setEditable (false, false, false);
    dLetter->setColour (TextEditor::textColourId, Colours::black);
    dLetter->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PawnPromotion::~PawnPromotion()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    queenButton = nullptr;
    rockButton = nullptr;
    bishopButton = nullptr;
    knightButton = nullptr;
    promotionLabel = nullptr;
    aLetter = nullptr;
    bLetter = nullptr;
    cLetter = nullptr;
    dLetter = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PawnPromotion::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffceffc9));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PawnPromotion::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    queenButton->setBounds (proportionOfWidth (0.2056f), proportionOfHeight (0.1500f), proportionOfWidth (0.2323f), proportionOfHeight (0.3500f));
    rockButton->setBounds (proportionOfWidth (0.6444f), proportionOfHeight (0.1504f), proportionOfWidth (0.2323f), proportionOfHeight (0.3504f));
    bishopButton->setBounds (proportionOfWidth (0.1976f), proportionOfHeight (0.5700f), proportionOfWidth (0.2321f), proportionOfHeight (0.3500f));
    knightButton->setBounds (proportionOfWidth (0.6372f), proportionOfHeight (0.5703f), proportionOfWidth (0.2323f), proportionOfHeight (0.3504f));
    promotionLabel->setBounds (proportionOfWidth (0.0039f), proportionOfHeight (0.0000f), proportionOfWidth (0.9912f), proportionOfHeight (0.1182f));
    aLetter->setBounds (proportionOfWidth (0.0247f), proportionOfHeight (0.1500f), proportionOfWidth (0.1480f), proportionOfHeight (0.3500f));
    bLetter->setBounds (proportionOfWidth (0.4604f), proportionOfHeight (0.1504f), proportionOfWidth (0.1480f), proportionOfHeight (0.3504f));
    cLetter->setBounds (proportionOfWidth (0.0226f), proportionOfHeight (0.5719f), proportionOfWidth (0.1480f), proportionOfHeight (0.3504f));
    dLetter->setBounds (proportionOfWidth (0.4584f), proportionOfHeight (0.5719f), proportionOfWidth (0.1480f), proportionOfHeight (0.3504f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PawnPromotion::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == queenButton)
    {
        //[UserButtonCode_queenButton] -- add your button handler code here..
        gameListener->answerPromotionPiece(QUEEN);
        //[/UserButtonCode_queenButton]
    }
    else if (buttonThatWasClicked == rockButton)
    {
        //[UserButtonCode_rockButton] -- add your button handler code here..
        gameListener->answerPromotionPiece(ROCK);
        //[/UserButtonCode_rockButton]
    }
    else if (buttonThatWasClicked == bishopButton)
    {
        //[UserButtonCode_bishopButton] -- add your button handler code here..
        gameListener->answerPromotionPiece(BISHOP);
        //[/UserButtonCode_bishopButton]
    }
    else if (buttonThatWasClicked == knightButton)
    {
        //[UserButtonCode_knightButton] -- add your button handler code here..
        gameListener->answerPromotionPiece(KNIGHT);
        //[/UserButtonCode_knightButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

bool PawnPromotion::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
    if ( key == 'a' ) {
        gameListener->answerPromotionPiece(QUEEN);
        return true;
    } else if ( key == 'b' ) {
        gameListener->answerPromotionPiece(ROCK);
        return true;
    } else if ( key == 'c' ) {
        gameListener->answerPromotionPiece(BISHOP);
        return true;
    } else if ( key == 'd' ) {
        gameListener->answerPromotionPiece(KNIGHT);
        return true;
    }

    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PawnPromotion::setGameListener(GameListener *gl) {
    this->gameListener = gl;
}

void PawnPromotion::setColor(Color color) {
    if ( color == WHITE) {
        queenButton->setImages (false, true, true,
                            ImageCache::getFromMemory (BinaryData::wQueen_png, BinaryData::wQueen_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
        rockButton->setImages (false, true, true,
                            ImageCache::getFromMemory (BinaryData::wRock_png, BinaryData::wRock_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
        bishopButton->setImages (false, true, true,
                                ImageCache::getFromMemory (BinaryData::wBishop_png, BinaryData::wBishop_pngSize), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));
        knightButton->setImages (false, true, true,
                                ImageCache::getFromMemory (BinaryData::wKnight_png, BinaryData::wKnight_pngSize), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));
    } else {
        queenButton->setImages (false, true, true,
                            ImageCache::getFromMemory (BinaryData::bQueen_png, BinaryData::bQueen_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
        rockButton->setImages (false, true, true,
                            ImageCache::getFromMemory (BinaryData::bRock_png, BinaryData::bRock_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
        bishopButton->setImages (false, true, true,
                                ImageCache::getFromMemory (BinaryData::bBishop_png, BinaryData::bBishop_pngSize), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));
        knightButton->setImages (false, true, true,
                                ImageCache::getFromMemory (BinaryData::bKnight_png, BinaryData::bKnight_pngSize), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));        
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PawnPromotion" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="480">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffceffc9"/>
  <IMAGEBUTTON name="queen button" id="c96350b8d3587e48" memberName="queenButton"
               virtualName="" explicitFocusOrder="0" pos="20.555% 15.041% 23.227% 35.041%"
               buttonText="queen button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wQueen_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="rock button" id="accf8664291942cb" memberName="rockButton"
               virtualName="" explicitFocusOrder="0" pos="64.44% 15.041% 23.227% 35.041%"
               buttonText="rock button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wRock_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="bishop button" id="625b3c19bbbb2318" memberName="bishopButton"
               virtualName="" explicitFocusOrder="0" pos="19.733% 57.025% 23.227% 35.041%"
               buttonText="bishop button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wBishop_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="knight button" id="fb32f3c1c8c6841b" memberName="knightButton"
               virtualName="" explicitFocusOrder="0" pos="63.72% 57.025% 23.227% 35.041%"
               buttonText="knight button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wKnight_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <LABEL name="promotion label" id="238eb13ab338f419" memberName="promotionLabel"
         virtualName="" explicitFocusOrder="0" pos="0.411% 0% 99.075% 11.901%"
         edTextCol="ff000000" edBkgCol="0" labelText="Promotion du pion"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="OpenDyslexicAlta" fontsize="80" bold="1" italic="0"
         justification="36"/>
  <LABEL name="A label" id="f41d2ff5a7a47481" memberName="aLetter" virtualName=""
         explicitFocusOrder="0" pos="2.467% 15.041% 14.8% 35.041%" edTextCol="ff000000"
         edBkgCol="0" labelText="a" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="120"
         bold="0" italic="0" justification="36"/>
  <LABEL name="B label" id="325dd06d9a50b276" memberName="bLetter" virtualName=""
         explicitFocusOrder="0" pos="46.043% 15.041% 14.8% 35.041%" edTextCol="ff000000"
         edBkgCol="0" labelText="b" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="120"
         bold="0" italic="0" justification="36"/>
  <LABEL name="C label" id="139c547475121ca3" memberName="cLetter" virtualName=""
         explicitFocusOrder="0" pos="2.261% 57.19% 14.8% 35.041%" edTextCol="ff000000"
         edBkgCol="0" labelText="c" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="120"
         bold="0" italic="0" justification="36"/>
  <LABEL name="D label" id="1d3d9d5dcd9a23c9" memberName="dLetter" virtualName=""
         explicitFocusOrder="0" pos="45.838% 57.19% 14.8% 35.041%" edTextCol="ff000000"
         edBkgCol="0" labelText="d" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="120"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
