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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


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

    queenButton->setBounds (proportionOfWidth (0.1809f), proportionOfHeight (0.1555f), proportionOfWidth (0.2321f), proportionOfHeight (0.3546f));
    rockButton->setBounds (proportionOfWidth (0.5624f), proportionOfHeight (0.1555f), proportionOfWidth (0.2321f), proportionOfHeight (0.3546f));
    bishopButton->setBounds (proportionOfWidth (0.1976f), proportionOfHeight (0.5731f), proportionOfWidth (0.2321f), proportionOfHeight (0.3546f));
    knightButton->setBounds (proportionOfWidth (0.5629f), proportionOfHeight (0.5731f), proportionOfWidth (0.2321f), proportionOfHeight (0.3546f));
    promotionLabel->setBounds (proportionOfWidth (0.0039f), proportionOfHeight (0.0000f), proportionOfWidth (0.9912f), proportionOfHeight (0.1182f));
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
        //[/UserButtonCode_queenButton]
    }
    else if (buttonThatWasClicked == rockButton)
    {
        //[UserButtonCode_rockButton] -- add your button handler code here..
        //[/UserButtonCode_rockButton]
    }
    else if (buttonThatWasClicked == bishopButton)
    {
        //[UserButtonCode_bishopButton] -- add your button handler code here..
        //[/UserButtonCode_bishopButton]
    }
    else if (buttonThatWasClicked == knightButton)
    {
        //[UserButtonCode_knightButton] -- add your button handler code here..
        //[/UserButtonCode_knightButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
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
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffceffc9"/>
  <IMAGEBUTTON name="queen button" id="c96350b8d3587e48" memberName="queenButton"
               virtualName="" explicitFocusOrder="0" pos="18.092% 15.552% 23.206% 35.459%"
               buttonText="queen button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wQueen_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="rock button" id="accf8664291942cb" memberName="rockButton"
               virtualName="" explicitFocusOrder="0" pos="56.244% 15.552% 23.206% 35.459%"
               buttonText="rock button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wRock_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="bishop button" id="625b3c19bbbb2318" memberName="bishopButton"
               virtualName="" explicitFocusOrder="0" pos="19.764% 57.309% 23.206% 35.459%"
               buttonText="bishop button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wBishop_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="knight button" id="fb32f3c1c8c6841b" memberName="knightButton"
               virtualName="" explicitFocusOrder="0" pos="56.293% 57.309% 23.206% 35.459%"
               buttonText="knight button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::wKnight_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <LABEL name="promotion label" id="238eb13ab338f419" memberName="promotionLabel"
         virtualName="" explicitFocusOrder="0" pos="0.393% 0% 99.115% 11.82%"
         edTextCol="ff000000" edBkgCol="0" labelText="Promotion du pion"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="OpenDyslexicAlta" fontsize="80" bold="1" italic="0"
         justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
