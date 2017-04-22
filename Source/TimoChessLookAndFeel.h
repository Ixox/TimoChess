/*
  ==============================================================================

    TimoChessLookAndFeel.h
    Created: 22 Apr 2017 11:10:34am
    Author:  xavier

  ==============================================================================
*/

#ifndef TIMOCHESSLOOKANDFEEL_H_INCLUDED
#define TIMOCHESSLOOKANDFEEL_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"

class TimoChessLookAndFeel : public LookAndFeel_V3
{
public:
    TimoChessLookAndFeel()
    {
        setDefaultSansSerifTypefaceName("OpenDyslexicAlta");
        setColour (TextButton::textColourOnId, Colours::white); 
        setColour (TextButton::textColourOffId, Colours::white); 
    }
    
    void drawToggleButton (Graphics& g, ToggleButton& button,
                                       bool isMouseOverButton, bool isButtonDown)
    {
        float fontSize = 30;
        const float tickWidth = fontSize * 1.1f;

        drawTickBox (g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
                    tickWidth, tickWidth,
                    button.getToggleState(),
                    button.isEnabled(),
                    isMouseOverButton,
                    isButtonDown);

        g.setColour (button.findColour (ToggleButton::textColourId));
        g.setFont (fontSize);

        if (! button.isEnabled())
            g.setOpacity (0.5f);

        const int textX = (int) tickWidth + 5;

        g.drawFittedText (button.getButtonText(),
                        textX, 0,
                        button.getWidth() - textX - 2, button.getHeight(),
                        Justification::centredLeft, 10);
    }


    void drawButtonBackground (Graphics& g,
                                Button& button,
                                const Colour& backgroundColour,
                                bool isMouseOverButton,
                                bool isButtonDown)
    {
        const int width = button.getWidth();
        const int height = button.getHeight();

        const float outlineThickness = 0.2f;
        const float halfThickness = 0.1f;

        g.setColour(Colour::fromRGBA(0, 200, 150, 160));
        g.drawRoundedRectangle (width * .1f, height * .1f, width * .8f, height * .8f, 6, 3);
        g.setColour(Colour::fromRGBA(30, 200, 30, 80));
        g.fillRoundedRectangle (width * .1f, height * .1f, width * .8f, height * .8f, 6);

    }

    Font getTextButtonFont (TextButton&, int buttonHeight)
    {
        return Font (jmin (26.0f, buttonHeight * 0.6f));
    }

    Label* createSliderTextBox (Slider& slider)
    {
        Label* const l = new Label();

        l->setFont (Font(36));
        l->setJustificationType (Justification::centred);
        l->setKeyboardType (TextInputTarget::decimalKeyboard);

        l->setColour (Label::textColourId, Colours::white);
        l->setColour (Label::backgroundColourId,  Colours::transparentBlack);
        l->setColour (Label::outlineColourId, Colours::transparentBlack);
        l->setColour (TextEditor::textColourId, Colours::white);
        l->setColour (TextEditor::backgroundColourId,   Colours::transparentBlack);
        l->setColour (TextEditor::outlineColourId, Colours::red);
        l->setColour (TextEditor::highlightColourId, Colours::transparentBlack);

        return l;
    }

};



#endif  // TIMOCHESSLOOKANDFEEL_H_INCLUDED
