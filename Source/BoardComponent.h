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

#ifndef __JUCE_HEADER_E4DE0C7D386BE276__
#define __JUCE_HEADER_E4DE0C7D386BE276__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "GameListener.h"
#include "ChessBoard.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BoardComponent  : public Component,
                        public ButtonListener
{
public:
    //==============================================================================
    BoardComponent ();
    ~BoardComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setGameListener(GameListener *gl);
    void setChessboard(ChessBoard *chessBoard, String computerMove);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    bool keyPressed (const KeyPress& key) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GameListener *gameListener;
    ChessBoard *chessBoard;
    ScopedPointer<DrawableImage> boardCase[8][8];
    ScopedPointer<Label> letterLabel[8];
    ScopedPointer<Label> numberLabel[8];
    String computerMove;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> closeButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BoardComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E4DE0C7D386BE276__
