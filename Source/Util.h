/*
  ==============================================================================

    Util.h
    Created: 25 Oct 2018 8:06:19pm
    Author:  daryl

  ==============================================================================
*/
#include <string>

#include <iostream>
#include <sstream>
#pragma once
#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

inline float linInterp(float x1, float x2, float y1, float y2, float x)
{
	float denom = x2 - x1;
	if (denom == 0)
		return y1; // should not ever happen

	// calculate decimal position of x
	float dx = (x - x1) / (x2 - x1);

	// use weighted sum method of interpolating
	float result = dx * y2 + (1 - dx) * y1;

	return result;
}

inline float cubicInterp(int channel, float delayTimeInSamples, float floorValue0, float floorValue, float floorValue1, float floorValue2, float mod)
{
	float fraction = (delayTimeInSamples + mod) - floor(delayTimeInSamples + mod);
	float fractionSqrt = fraction * fraction;
	float fractionCube = fractionSqrt * fraction;

	float a0 = -0.5f * floorValue0 + 1.5f * floorValue - 1.5f * floorValue1 + 0.5f * floorValue2;
	float a1 = floorValue0 - 2.5f * floorValue + 2.0f * floorValue1 - 0.5f * floorValue2;
	float a2 = -0.5f * floorValue0 + 0.5f * floorValue1;
	float a3 = floorValue;
	return a0 * fractionCube + a1 * fractionSqrt + a2 * fraction + a3;
}

inline float interpolate(float y0, float y1, float y2, float y3, float delayTimeInSamples, float mod)
{
	float y = floor(delayTimeInSamples);
	float x = y - mod;
	float x1 = (floor)(x);
	float frac = x - x1;
	float ym1py2 = y0 + y3;
	float c0 = y1;
	float c1 = (3.f / 2.f) * y2 - (1.f / 2.f) * (y1 + ym1py2);
	float c2 = 1.f / 2.f * (ym1py2 - y1 - y2);

	return (c2 * frac + c1) *frac + c0;
}

//float delaySampleTop = (int) (delaySampleFloor + 1.f) % delayBufferLength;
//topValue = delayBuffer.getSample(channel, (int)(k + i - delaySampleTop + delayBufferLength + 1) % delayBufferLength);
//writeValue[3] = linInterp(0, 1, floorValue, topValue, delayTimeInSamples - delaySampleFloor);