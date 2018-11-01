/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "Util.h"

//==============================================================================
/**
*/
class AnotherDelayAudioProcessor : public AudioProcessor, public AudioProcessorValueTreeState::Listener
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

	//float AnotherDelayAudioProcessor::linInterp(float x1, float x2, float y1, float y2, float x);

	//float AnotherDelayAudioProcessor::cubicInterp(int channel, float delayTimeInSamples, float delayTimeFloor, float floorValue0, float floorValue, float floorValue1, float floorValue2);

	double AnotherDelayAudioProcessor::updateOscillator(int channel);

	static String paramDelayTime;
	static String paramGain;
	static String paramFeedback;
	static String paramWetDry;
	static String paramCutOff;
	static String paramCutOffHi;
	static String paramFlutterFreq;
	static String paramFlutterDepth;
	static String paramWowFreq;
	static String paramWowDepth;

private:

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

	ScopedPointer<AudioProcessorValueTreeState> mState;
	ScopedPointer<UndoManager>	mUndoManager;

	Atomic<float> delayTime;
	Atomic<float> gain;
	Atomic <float> feedback;
	Atomic <float> mix;
	Atomic <double> flutterfreq;
	Atomic <double> flutterdepth;
	Atomic <double> wowfreq;
	Atomic <double> wowdepth;

	float lastInputGain;
	float lastFeedbackGain;
	float lastWetDry;

	dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> lowPassFilter;
	IIRFilter lowPassFilter0; /* channel 0 */
	IIRFilter lowPassFilter1; /* channel 1 */
	IIRFilter hiPassFilter0; /* channel 0 */
	IIRFilter hiPassFilter1; /* channel 1 */
	IIRFilter hiShelfFilter0;
	IIRFilter hiShelfFilter1;
	IIRFilter hiShelfFilter2;
	IIRFilter hiShelfFilter3;
	IIRFilter lowPassFilter2;
	IIRFilter lowPassFilter3;
	IIRFilter allPassFilter0;
	IIRFilter allPassFilter1;

	Oscillator oscFlutterL;
	Oscillator oscFlutterR;
	Oscillator oscWowL;
	Oscillator oscWowR;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AnotherDelayAudioProcessor)
};