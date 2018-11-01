/*
  ==============================================================================

    Oscillator.h
    Created: 19 Oct 2018 9:56:31am
    Author:  daryl

  ==============================================================================
*/

#pragma once

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include <iostream>
#include <math.h>

class Oscillator {
private:
	const double mPI;
	const double twoPI;
	bool isMuted;
	double mFrequency;
	double mPhase;
	double mSampleRate;
	int mOvertoneLimit;
	double mPhaseIncrement;
	void updateIncrement();

public:
	void setFrequency(double frequency);
	void setSampleRate(double sampleRate);
	//void generate(double* buffer, int nFrames);
	inline void setMuted(bool muted) { isMuted = muted; }
	double nextSample(double frequency);
	Oscillator() :
		mPI(2 * acos(0.0)),
		twoPI(2 * mPI),
		isMuted(false),
		mFrequency(1.0),
		mPhase(0.0),
		mSampleRate(44100.0) {
		updateIncrement();
	};
};

#endif  // OSCILLATOR_H_INCLUDED