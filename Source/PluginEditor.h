/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AnotherDelayAudioProcessorEditor : public AudioProcessorEditor
{
public:
    AnotherDelayAudioProcessorEditor (AnotherDelayAudioProcessor&);
    ~AnotherDelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AnotherDelayAudioProcessor& processor;

	ScopedPointer<Slider> delayTimeSlider;
	ScopedPointer<Slider> gainSlider;
	ScopedPointer<Slider> feedbackSlider;
	ScopedPointer<Slider> wetDrySlider;
	ScopedPointer<Slider> filterCutOffSlider;
	ScopedPointer<Slider> filterCutOffSliderHi;
	ScopedPointer<Slider> flutterFreqSlider;
	ScopedPointer<Slider> flutterDepthSlider;
	ScopedPointer<Slider> wowFreqSlider;
	ScopedPointer<Slider> wowDepthSlider;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> delayTimeAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> wetDryAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutOffAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutOffHiAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> flutterFreqAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> flutterDepthAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> wowFreqAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> wowDepthAttachment;
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnotherDelayAudioProcessorEditor)
};
