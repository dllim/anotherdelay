/*
  ==============================================================================

    Oscillator.cpp
    Created: 19 Oct 2018 9:56:09am
    Author:  daryl

  ==============================================================================
*/

#include "Oscillator.h"

void Oscillator::setFrequency(double frequency) {
	mFrequency = frequency;
	updateIncrement();
}

void Oscillator::setSampleRate(double sampleRate) {
	mSampleRate = sampleRate;
	updateIncrement();
}

void Oscillator::updateIncrement() {
	mPhaseIncrement = mFrequency / mSampleRate;
}

double Oscillator::nextSample(double frequency) {
	//	float value = 0.0;
	//	if (isMuted) return value;

	mPhaseIncrement = frequency / 44100.0;

	mPhase += mPhaseIncrement;
	while (mPhase > 1.0) {
		mPhase -= 1.0;
	}
	return 0.5 + 0.5 * sin(mPhase * 4.0 * acos(0.0));
}