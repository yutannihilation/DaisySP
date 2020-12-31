#pragma once
#ifndef DSY_ZOSCILLATOR_H
#define DSY_ZOSCILLATOR_H

#include <stdint.h>
#ifdef __cplusplus

/** @file zoscillator.h */
namespace daisysp
{
/**  
    ZOscillator Module \n 
	Sinewave multiplied by and sync'ed to a carrier. \n
    Ported by Ben Sergentanis, Dec 2020 
    @author Emilie Gillet
    @date 2016
*/
class ZOscillator
{
  public:
    ZOscillator() {}
    ~ZOscillator() {}

	/** Init ZOscillator module
		\param sample_rate Audio engine sample rate.
	*/
    void Init(float sample_rate);

	/** Get next sample
	*/
    float Process();
	
	/** Set the formant osc. freq
		\param freq Frequency in Hz.
	*/
	void SetFormantFreq(float freq);

	/** Set the main frequency
		\param freq Frequency in Hz.
	*/
	void SetCarrierFreq(float freq);

	/** Set the waveshape
		\param shape The waveshape to set
	*/
	void SetShape(float shape);

	/** Set the mode
		\param mode Mode to set
	*/
	void SetMode(float mode);

  private:
    inline float Sine(float phase);
    inline float Z(float c, float d, float f, float shape, float mode);
    inline float ThisBlepSample(float t);
    inline float NextBlepSample(float t);

    float sample_rate_;

    // Oscillator state.
    float carrier_phase_;
    float discontinuity_phase_;
    float formant_phase_;
    float next_sample_;

    // For interpolation of parameters.
    float carrier_frequency_;
    float formant_frequency_;
    float carrier_shape_, shape_new_;
    float mode_, mode_new_;
};
} // namespace daisysp
#endif
#endif