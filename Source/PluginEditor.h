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
	bool getReverbToggleState() { reverbEnabledButton->getToggleState(); };

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
	
	ScopedPointer<TextButton> reverbEnabledButton;
	ScopedPointer<Slider> roomSizeSlider;
	ScopedPointer<Slider> dampingSlider;
	ScopedPointer<Slider> widthSlider;

	ScopedPointer<Label> delayTimeLabel;
	ScopedPointer<Label> gainLabel;
	ScopedPointer<Label> feedbackLabel;
	ScopedPointer<Label> wetDryLabel;
	ScopedPointer<Label> filterCutOffLabel;
	ScopedPointer<Label> filterCutOffLabelHi;
	ScopedPointer<Label> flutterFreqLabel;
	ScopedPointer<Label> flutterDepthLabel;
	ScopedPointer<Label> wowFreqLabel;
	ScopedPointer<Label> wowDepthLabel;
	ScopedPointer<Label> roomSizeLabel;
	ScopedPointer<Label> dampingLabel;
	ScopedPointer<Label> widthLabel;

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
	
	ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> reverbEnabledAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> roomSizeAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> dampingAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> widthAttachment;

	juce::Rectangle<int> delayRectangle;
	juce::Rectangle<int> filterRectangle;
	juce::Rectangle<int> modRectangle;
	juce::Rectangle<int> reverbRectangle;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnotherDelayAudioProcessorEditor)
};
