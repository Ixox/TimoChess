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

#ifndef __JUCE_HEADER_11D8D89CF380EFE__
#define __JUCE_HEADER_11D8D89CF380EFE__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "GameListener.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class EndOfTheGame  : public Component,
                      public ButtonListener
{
public:
    //==============================================================================
    EndOfTheGame ();
    ~EndOfTheGame();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setGameListener(GameListener *gl);
    void theWinnerIs(Color color, Color realPlayerColor, String additionalText);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GameListener *gameListener;
    Colour fillColour;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> message;
    ScopedPointer<ImageButton> backButton;
    ScopedPointer<Drawable> drawable1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EndOfTheGame)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_11D8D89CF380EFE__
