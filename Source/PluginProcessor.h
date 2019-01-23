/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <map>;
#include "Oscillator.h"
#include "Util.h"

//==============================================================================
/**
*/

namespace Parameters
{
	static const Identifier gain { "gain" };
	static const Identifier delaytime{ "delay time" };
	static const Identifier feedback{ "feedback" };
	static const Identifier mix{ "mix" };
	static const Identifier lowpass{ "lowpass" };
	static const Identifier highpass{ "highpass" };
	static const Identifier flutterfreq{ "flutter frequency" };
	static const Identifier flutterdepth{ "flutter depth" };
	static const Identifier wowfreq{ "wow frequency" };
	static const Identifier wowdepth{ "wow depth" };
	static const Identifier reverbenabled{ "reverb enabled" };
	static const Identifier roomsize{ "room size" };
	static const Identifier damping{ "damping" };
	static const Identifier width{ "width" };

	struct ParameterInfo
	{
		String labelName;
		float defaultValue;
		float lowerLimit;
		float upperLimit;
		float interval;
	};

	static std::map<Identifier, ParameterInfo> parameterInfoMap
	{
		{ gain, { "Gain", -9.0f, -30.0f, 0.0f, 0.3f}},
		{ delaytime, {"Delay Time", 2, 1, 4, 1}},
		{feedback, {"Feedback", -30.0f,-45.0f, -12.0f, 0.3f}},
		{mix, {"Mix", 0.5f, 0.0f, 1.0f, 0.1f}},
		{lowpass, {"Lowpass", 15000.0f, 400.0f, 21000.0f, 0.01f}},
		{highpass, {"Highpass", 300.0f, 1.0f, 3000.0f, 0.01f}},
		{flutterfreq, {"Flutter Frequency", 2.5f, 2.5f, 5.0f, 0.01f}},
		{flutterdepth, {"Flutter Depth", 0.0f, -0.2f, 0.2f, 0.01f}},
		{wowfreq, {"Wow Frequency",0.0f, 0.0f, 2.5f, 0.01}},
		{wowdepth, {"Wow Depth",0.0f, -0.2f, 0.2f, 0.01f}},
		{reverbenabled, {"Reverb Enabled", 1.f, 0.f, 1.f, 1}},
		{roomsize, {"Room Size", 0.5f, 0.f, 1.f, 0.01f}},
		{damping, {"Damping", 0.5f, 0.f, 1.f, 0.01f}},
		{width, {"Width", 0.5f, 0.f, 1.f, 0.01f}},
	};
}

class AnotherDelayAudioProcessor : public AudioProcessor,
								   private AudioProcessorValueTreeState::Listener
								   
{
public:
	//==============================================================================
	AnotherDelayAudioProcessor();
	~AnotherDelayAudioProcessor();

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	AudioProcessorValueTreeState& getValueTreeState();

	void parameterChanged(const String & parameterID, float newValue);

	void fillBuffer(int channel, const int bufferLength, const int delayBufferLength, const float* bufferReadPtr,
		int dBWritePosition, float startGain, float endGain);

	void fetchDelay(AudioBuffer<float>& buffer, int channel, const int feedbackBufferLength,
		const int delayBufferLength, const float* feedbackBufferPtr, const float* delayBufferPtr, float startGain, float endGain);

	void sendFeedback(AudioBuffer<float>& buffer, int channel, const int feedbackBufferLength, const int delayBufferLength, float* feedbackBufferWrite,
		float startGain, float endGain);

	void AnotherDelayAudioProcessor::updateFilter();

	float AnotherDelayAudioProcessor::calcWriteValue(int channel, AudioBuffer<float>& buffer, int k, int i, int delayBufferLength, float delayTimeInSamples, float mod);

	double AnotherDelayAudioProcessor::updateOscillator(int channel);

	void updateProcessing();

private:

	void addParameterListeners();

	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	AudioSampleBuffer delayBuffer;
	AudioSampleBuffer wetBuffer;
	int dBWritePositionL{ 0 };
	int dBWritePositionR{ 0 };
	int mSampleRate{ 44100 };
	int flangePosition{ 0 };
	double oscLPosition = 0.0;
	double oscRPosition = 0.0;
	double oscWowLPosition = 0.0;
	double oscWowRPosition = 0.0;
	double mod{ 0 };

	AudioProcessorValueTreeState state;

	AudioParameterFloat* gain;
	AudioParameterFloat* delaytime;
	AudioParameterFloat* feedback;
	AudioParameterFloat* mix;
	AudioParameterFloat* lowpass;
	AudioParameterFloat* highpass;
	AudioParameterFloat* flutterfreq;
	AudioParameterFloat* flutterdepth;
	AudioParameterFloat* wowfreq;
	AudioParameterFloat* wowdepth;
	AudioParameterFloat* roomsize;
	AudioParameterFloat* damping;
	AudioParameterFloat* width;
	AudioParameterFloat* reverbenabled;

	Reverb reverbL;
	Reverb reverbR;
	Reverb::Parameters reverbLParameters;
	Reverb::Parameters reverbRParameters;

	float lastInputGain;
	float lastFeedbackGain;
	float lastWetDry;

	dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> lowPassFilter;
	IIRFilter lowPassFilter0; /* channel 0 */
	IIRFilter lowPassFilter1; /* channel 1 */
	IIRFilter hiPassFilter0; /* channel 0 */
	IIRFilter hiPassFilter1; /* channel 1 */

	Oscillator oscFlutterL;
	Oscillator oscFlutterR;
	Oscillator oscWowL;
	Oscillator oscWowR;

	struct delayEngine
	{
		float gainInput, delayTimeInput, feedbackInput, mixInput;
	};

	delayEngine theDelayEngine;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AnotherDelayAudioProcessor)
};