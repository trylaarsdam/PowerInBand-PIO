#pragma once
#include "arduinoFFT.h"
#ifdef CORE_CM7 
#include "SDRAM.h"
#endif

namespace PowerInBand
{
	/// @brief Computers the power in band of the given sample buffer using the default of Welch's method for windowing, and SRAM
	/// @param samples Pointer to the raw data
	/// @param len Amount of data to be computed - this *must* be a power of 2
	/// @param sampling_freq Sampling frequency of the data
	/// @param lower_freq Lower frequency of the band
	/// @param upper_freq Upper frequency of the band
	/// @return The power in band of the specified frequency range
	double Compute(double* samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq);

	/// @brief Computers the power in band of the given sample buffer in SRAM
	/// @param samples Pointer to the raw data
	/// @param len Amount of data to be computed - this *must* be a power of 2
	/// @param sampling_freq Sampling frequency of the data
	/// @param lower_freq Lower frequency of the band
	/// @param upper_freq Upper frequency of the band
	/// @param window_method Windowing method to use
	/// @return The power in band of the specified frequency range
	double Compute(double *samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq, FFTWindow window_method);

	/// @brief Computers the power in band of the given sample buffer with the option to use SDRAM
	/// @param samples Pointer to the raw data
	/// @param len Amount of data to be computed - this *must* be a power of 2
	/// @param sampling_freq Sampling frequency of the data
	/// @param lower_freq Lower frequency of the band
	/// @param upper_freq Upper frequency of the band
	/// @param window_method Windowing method to use
	/// @param use_SDRAM Whether or not to use SDRAM for the FFT
	/// @return The power in band of the specified frequency range
	double Compute(double *samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq, FFTWindow window_method, bool use_SDRAM);
}