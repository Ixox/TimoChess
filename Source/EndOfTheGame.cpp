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

#include "EndOfTheGame.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EndOfTheGame::EndOfTheGame ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (message = new Label ("message label",
                                            TRANS("Bravo")));
    message->setFont (Font ("OpenDyslexicAlta", 140.00f, Font::bold));
    message->setJustificationType (Justification::centred);
    message->setEditable (false, false, false);
    message->setColour (TextEditor::textColourId, Colours::black);
    message->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (backButton = new ImageButton ("back button"));
    backButton->addListener (this);

    backButton->setImages (false, true, true,
                           ImageCache::getFromMemory (BinaryData::reset_png, BinaryData::reset_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000));
    drawable1 = Drawable::createFromImageData (BinaryData::wking_png, BinaryData::wking_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EndOfTheGame::~EndOfTheGame()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    message = nullptr;
    backButton = nullptr;
    drawable1 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EndOfTheGame::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    g.fillAll(fillColour);
    //[/UserPrePaint]

    g.setColour (Colours::black);
    jassert (drawable1 != 0);
    if (drawable1 != 0)
        drawable1->drawWithin (g, Rectangle<float> (proportionOfWidth (0.3000f), proportionOfHeight (0.3390f), proportionOfWidth (0.4000f), proportionOfHeight (0.4510f)),
                               RectanglePlacement::centred, 1.000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EndOfTheGame::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    message->setBounds (proportionOfWidth (0.0590f), proportionOfHeight (0.0124f), proportionOfWidth (0.9002f), proportionOfHeight (0.2737f));
    backButton->setBounds (proportionOfWidth (0.0197f), proportionOfHeight (0.8025f), proportionOfWidth (0.1091f), proportionOfHeight (0.1742f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EndOfTheGame::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == backButton)
    {
        //[UserButtonCode_backButton] -- add your button handler code here..
        gameListener->setup();
        //[/UserButtonCode_backButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void EndOfTheGame::setGameListener(GameListener *gl) {
    this->gameListener = gl;
}

void EndOfTheGame::theWinnerIs(Color winner, Color realPlayerColor, String additionalText) {
    if (winner == NOCOLOR) {
        fillColour = Colour(0xff909090);
        message->setText(additionalText + "Partie nulle", dontSendNotification);
        drawable1 = Drawable::createFromImageData (BinaryData::slatemate_png, BinaryData::slatemate_pngSize);
    } else {
        if (winner == BLACK) {
            drawable1 = Drawable::createFromImageData (BinaryData::bKing_png, BinaryData::bKing_pngSize);
        } else {
            drawable1 = Drawable::createFromImageData (BinaryData::wking_png, BinaryData::wking_pngSize);
        }

        if (winner == realPlayerColor) {
            fillColour = Colour(0xff90ddc9);
            message->setText("Victoire !", dontSendNotification);
        } else {
            fillColour = Colour(0xffdd9090);
            message->setText(additionalText + "Defaite !", dontSendNotification);
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

<JUCER_COMPONENT documentType="Component" className="EndOfTheGame" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="480">
  <BACKGROUND backgroundColour="adf0d9">
    <IMAGE pos="30% 33.904% 40% 45.101%" resource="BinaryData::wking_png"
           opacity="1" mode="1"/>
  </BACKGROUND>
  <LABEL name="message label" id="9a24453319033a00" memberName="message"
         virtualName="" explicitFocusOrder="0" pos="5.9% 1.244% 90.02% 27.372%"
         edTextCol="ff000000" edBkgCol="0" labelText="Bravo" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="OpenDyslexicAlta"
         fontsize="140" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="back button" id="b765d87bc9c30441" memberName="backButton"
               virtualName="" explicitFocusOrder="0" pos="1.967% 80.249% 10.914% 17.418%"
               buttonText="back button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::reset_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
