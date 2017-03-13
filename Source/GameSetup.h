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

#ifndef __JUCE_HEADER_6F02AED76A156E2A__
#define __JUCE_HEADER_6F02AED76A156E2A__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "GameListener.h"
#include "ChessBoard.h"
#include "StockfishWrapper.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GameSetup  : public Component,
                   public ButtonListener,
                   public SliderListener
{
public:
    //==============================================================================
    GameSetup ();
    ~GameSetup();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setGameListener(GameListener *gl);
    Color getRealPlayerColor() { return realPlayerColor; }
    int  getLevel() { return level; }
    Variant getVariant() { return variant; }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void childrenChanged() override;

    // Binary resources:
    static const char* white_png;
    static const int white_pngSize;
    static const char* black_png;
    static const int black_pngSize;
    static const char* whiteChecked_png;
    static const int whiteChecked_pngSize;
    static const char* blackChecked_png;
    static const int blackChecked_pngSize;
    static const char* start_png;
    static const int start_pngSize;
    static const char* vChess_png;
    static const int vChess_pngSize;
    static const char* vRacingKings_png;
    static const int vRacingKings_pngSize;
    static const char* vAtomic_png;
    static const int vAtomic_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GameListener *gameListener;
    Color realPlayerColor;
    int level;
    Variant variant;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> whiteButton;
    ScopedPointer<ImageButton> blackButton;
    ScopedPointer<ImageButton> playButton;
    ScopedPointer<Slider> slider;
    ScopedPointer<Label> title;
    ScopedPointer<ImageButton> vChess;
    ScopedPointer<ImageButton> vRacingKings;
    ScopedPointer<ImageButton> vAtomic;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GameSetup)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_6F02AED76A156E2A__
