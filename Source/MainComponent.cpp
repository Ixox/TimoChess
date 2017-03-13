/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (1024, 768);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff649ac3));

    g.setFont (Font (20));
    g.setColour (Colours::white);
    g.drawText ("Hello Tim!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
