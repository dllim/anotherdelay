/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AnotherDelayAudioProcessorEditor::AnotherDelayAudioProcessorEditor (AnotherDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	delayTimeSlider = new Slider;
	gainSlider = new Slider;
	feedbackSlider = new Slider;
	wetDrySlider = new Slider;
	filterCutOffSlider = new Slider;
	filterCutOffSliderHi = new Slider;
	flutterFreqSlider = new Slider;
	flutterDepthSlider = new Slider;
	wowFreqSlider = new Slider;
	wowDepthSlider = new Slider;

	addAndMakeVisible(delayTimeSlider);
	addAndMakeVisible(gainSlider);
	addAndMakeVisible(feedbackSlider);
	addAndMakeVisible(wetDrySlider);
	addAndMakeVisible(filterCutOffSlider);
	addAndMakeVisible(filterCutOffSliderHi);
	addAndMakeVisible(flutterFreqSlider);
	addAndMakeVisible(flutterDepthSlider);
	addAndMakeVisible(wowFreqSlider);
	addAndMakeVisible(wowDepthSlider);

	delayTimeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramDelayTime, *delayTimeSlider);
	gainAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramGain, *gainSlider);
	feedbackAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramFeedback, *feedbackSlider);
	wetDryAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramWetDry, *wetDrySlider);
	filterCutOffAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramCutOff, *filterCutOffSlider);
	filterCutOffHiAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramCutOffHi, *filterCutOffSliderHi);
	flutterFreqAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramFlutterFreq, *flutterFreqSlider);
	flutterDepthAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramFlutterDepth, *flutterDepthSlider);
	wowFreqAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramWowFreq, *wowFreqSlider);
	wowDepthAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), AnotherDelayAudioProcessor::paramWowDepth, *wowDepthSlider);
	setSize(800, 500);
}

AnotherDelayAudioProcessorEditor::~AnotherDelayAudioProcessorEditor()
{
	delayTimeAttachment = nullptr;
	delayTimeSlider = nullptr;
	gainAttachment = nullptr;
	gainSlider = nullptr;
	feedbackAttachment = nullptr;
	feedbackSlider = nullptr;
	wetDryAttachment = nullptr;
	wetDrySlider = nullptr;

}

//==============================================================================
void AnotherDelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colours::darkgoldenrod);

	g.setColour(Colours::silver);
	g.setFont(24.0f);
	Rectangle<int> box(getX(), getBottom() - 40, getWidth() / 6, 40);
	g.drawFittedText(TRANS("Gain"), box, Justification::centred, 1);
	box.setX(box.getRight());
	g.drawFittedText(TRANS("Delay Time (ms)"), box, Justification::centred, 1);
	box.setX(box.getRight());
	g.drawFittedText(TRANS("Feedback"), box, Justification::centred, 1);
	box.setX(box.getRight());
	g.drawFittedText(TRANS("Wet/Dry"), box, Justification::centred, 1);
	box.setX(box.getRight());
	g.drawFittedText(TRANS("Low-Pass"), box, Justification::centred, 1);
	box.setX(box.getRight());
	g.drawFittedText(TRANS("High-Pass"), box, Justification::centred, 1);
}

void AnotherDelayAudioProcessorEditor::resized()
{
	Rectangle<int> box(getLocalBounds());
	box.setWidth(getWidth() / 6);
	box.setHeight(getHeight() - 40);
	gainSlider->setBounds(box);
	box.setX(box.getRight());
	delayTimeSlider->setBounds(box);
	box.setX(box.getRight());
	feedbackSlider->setBounds(box);
	box.setX(box.getRight());
	wetDrySlider->setBounds(box);
	box.setX(box.getRight());
	filterCutOffSlider->setBounds(box);
	box.setX(box.getRight());
	filterCutOffSliderHi->setBounds(box);
}
