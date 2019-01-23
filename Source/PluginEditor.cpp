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
	delayTimeSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	gainSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	feedbackSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	wetDrySlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	filterCutOffSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	filterCutOffSliderHi = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	flutterFreqSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	flutterDepthSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	wowFreqSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	wowDepthSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	roomSizeSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	dampingSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	widthSlider = new Slider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow);
	reverbEnabledButton = new TextButton("Enabled");

	delayTimeLabel = new Label("", "Delay Time");
	gainLabel = new Label("", "Gain (dB)");
	feedbackLabel = new Label("", "Feedback (dB)");
	wetDryLabel = new Label("", "Mix");
	filterCutOffLabel = new Label("", "Low Pass");
	filterCutOffLabelHi = new Label("", "High Pass");
	flutterFreqLabel = new Label("", "Flutter Freq");
	flutterDepthLabel = new Label("", "Flutter Depth");
	wowFreqLabel = new Label("", "Wow Freq");
	wowDepthLabel = new Label("", "Wow Depth");
	roomSizeLabel = new Label("", "Room Size");
	dampingLabel = new Label("", "Damping");
	widthLabel = new Label("", "Width");

	addAndMakeVisible(delayTimeSlider);
	delayTimeSlider->setRange(1, 4);

	addAndMakeVisible(delayTimeLabel);
	delayTimeLabel->setJustificationType(Justification::centred);
	delayTimeLabel->attachToComponent(delayTimeSlider, false);

	addAndMakeVisible(gainSlider);
	gainSlider->setRange(0.0f, 1.0f);
	gainLabel->setJustificationType(Justification::centred);
	gainLabel->attachToComponent(gainSlider, false);

	addAndMakeVisible(feedbackSlider);
	feedbackSlider->setRange(-45.0, -12.0);
	feedbackLabel->setJustificationType(Justification::centred);
	feedbackLabel->attachToComponent(feedbackSlider, false);

	addAndMakeVisible(wetDrySlider);
	wetDrySlider->setRange(0.0f, 1.0f);
	wetDryLabel->setJustificationType(Justification::centred);
	wetDryLabel->attachToComponent(wetDrySlider, false);

	addAndMakeVisible(filterCutOffSlider);
	filterCutOffSlider->setRange(400.0f, 21000.0f);
	filterCutOffSlider->setSkewFactorFromMidPoint(600);
	filterCutOffLabel->setJustificationType(Justification::centred);
	filterCutOffLabel->attachToComponent(filterCutOffSlider, false);

	addAndMakeVisible(filterCutOffSliderHi);
	filterCutOffSliderHi->setRange(400.0f, 21000.0f);
	filterCutOffSliderHi->setSkewFactorFromMidPoint(600);
	filterCutOffLabelHi->setJustificationType(Justification::centred);
	filterCutOffLabelHi->attachToComponent(filterCutOffSliderHi, false);

	addAndMakeVisible(flutterFreqSlider);
	flutterFreqSlider->setRange(2.5f, 5.0f);
	flutterFreqLabel->setJustificationType(Justification::centred);
	flutterFreqLabel->attachToComponent(flutterFreqSlider, false);

	addAndMakeVisible(flutterDepthSlider);
	flutterDepthSlider->setRange(-0.2f, 0.2f);
	flutterDepthLabel->setJustificationType(Justification::centred);
	flutterDepthLabel->attachToComponent(flutterDepthSlider, false);

	addAndMakeVisible(wowFreqSlider);
	wowFreqSlider->setRange(0.0f, 2.5f);
	wowFreqLabel->setJustificationType(Justification::centred);
	wowFreqLabel->attachToComponent(wowFreqSlider, false);

	addAndMakeVisible(wowDepthSlider);
	wowDepthSlider->setRange(-0.2f, 0.2f);
	wowDepthLabel->setJustificationType(Justification::centred);
	wowDepthLabel->attachToComponent(wowDepthSlider, false);

	addAndMakeVisible(roomSizeSlider);
	roomSizeSlider->setRange(0.f, 1.f);
	roomSizeLabel->setJustificationType(Justification::centred);
	roomSizeLabel->attachToComponent(roomSizeSlider, false);

	addAndMakeVisible(dampingSlider);
	dampingSlider->setRange(0.f, 1.f);
	dampingLabel->setJustificationType(Justification::centred);
	dampingLabel->attachToComponent(dampingSlider, false);

	addAndMakeVisible(widthSlider);
	widthSlider->setRange(0.f, 1.f);
	widthLabel->setJustificationType(Justification::centred);
	widthLabel->attachToComponent(widthSlider, false);

	addAndMakeVisible(reverbEnabledButton);
	reverbEnabledButton->setClickingTogglesState(true);
	reverbEnabledButton->setToggleState(true, true);


	delayTimeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::delaytime.toString(), *delayTimeSlider);
	gainAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::gain.toString() , *gainSlider);
	feedbackAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::feedback.toString(), *feedbackSlider);
	wetDryAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::mix.toString(), *wetDrySlider);
	filterCutOffAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::lowpass.toString(), *filterCutOffSlider);
	filterCutOffHiAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::highpass.toString(), *filterCutOffSliderHi);
	flutterFreqAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::flutterfreq.toString(), *flutterFreqSlider);
	flutterDepthAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::flutterdepth.toString(), *flutterDepthSlider);
	wowFreqAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::wowfreq.toString(), *wowFreqSlider);
	wowDepthAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::wowdepth.toString(), *wowDepthSlider);
	reverbEnabledAttachment = new AudioProcessorValueTreeState::ButtonAttachment(p.getValueTreeState(), Parameters::reverbenabled.toString(), *reverbEnabledButton);
	roomSizeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::roomsize.toString(), *roomSizeSlider);
	dampingAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::damping.toString(), *dampingSlider);
	widthAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getValueTreeState(), Parameters::width.toString(), *widthSlider);

	setSize(900, 300);
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
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	g.setColour(Colours::silver);
	g.setFont(Font::Font(Font::getDefaultSansSerifFontName(), 18.f, 3));
	//g.setFont(18.0f);

	g.drawRoundedRectangle(delayRectangle.toFloat(), 5, 1);
	g.drawRoundedRectangle(filterRectangle.toFloat(), 5, 1);
	g.drawRoundedRectangle(modRectangle.toFloat(), 5, 1);
	g.drawRoundedRectangle(reverbRectangle.toFloat(), 5, 1);

	g.setColour(Colours::darkgoldenrod);
	g.drawFittedText("Delay", delayRectangle.reduced(3), Justification::topRight, 1);
	g.drawFittedText("EQ", filterRectangle.reduced(3), Justification::topRight, 1);
	g.drawFittedText("Flutter & Wow", modRectangle.reduced(3), Justification::topRight, 1);
	g.drawFittedText("Reverb", reverbRectangle.reduced(3), Justification::topRight, 1);
	
}

void AnotherDelayAudioProcessorEditor::resized()
{
	delayRectangle = getLocalBounds().reduced(180, 5);
	delayRectangle.reduce(150, 5);
	delayRectangle.translate(-315, 0);

	filterRectangle = getLocalBounds().reduced(200, 5);
	filterRectangle.reduce(180, 5);
	filterRectangle.translate(-90, 0);

	modRectangle = getLocalBounds().reduced(180, 5);
	modRectangle.reduce(150, 5);
	modRectangle.translate(135, 0);

	reverbRectangle = getLocalBounds().reduced(200, 5);
	reverbRectangle.reduce(180, 5);
	reverbRectangle.translate(360, 0);
		
	gainSlider->setBounds(delayRectangle.reduced(82, 90).translated(-65, -45));
	delayTimeSlider->setBounds(delayRectangle.reduced(82, 90).translated(65, -45));
	feedbackSlider->setBounds(delayRectangle.reduced(82, 90).translated(-65, 85));
	wetDrySlider->setBounds(delayRectangle.reduced(82, 90).translated(65, 85));

	filterCutOffSlider->setBounds(filterRectangle.reduced(32, 89).translated(0, -45));
	filterCutOffSliderHi->setBounds(filterRectangle.reduced(32, 89).translated(0, 85));
	
	flutterFreqSlider->setBounds(modRectangle.reduced(82, 90).translated(-65, -45));
	flutterDepthSlider->setBounds(modRectangle.reduced(82, 90).translated(65, -45));
	wowFreqSlider->setBounds(modRectangle.reduced(82, 90).translated(-65, 85));
	wowDepthSlider->setBounds(modRectangle.reduced(82, 90).translated(65, 85));

	reverbEnabledButton->setBounds(reverbRectangle.reduced(25, 128).translated(0, -100));
	roomSizeSlider->setBounds(reverbRectangle.reduced(40, 99).translated(0, -20));
	dampingSlider->setBounds(reverbRectangle.reduced(40, 99).translated(-35, 95));
	widthSlider->setBounds(reverbRectangle.reduced(40, 99).translated(35, 95));

}


