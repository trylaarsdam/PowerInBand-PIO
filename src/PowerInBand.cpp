#include "PowerInBand.h"

namespace PowerInBand 
{
	double Compute(double *samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq)
	{
		return Compute(samples, len, sampling_freq, lower_freq, upper_freq, FFT_WIN_TYP_WELCH);
	}

	double Compute(double *samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq, FFTWindow window_method)
	{
		return Compute(samples, len, sampling_freq, lower_freq, upper_freq, window_method, false);
	}

	double Compute(double *samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq, FFTWindow window_method, bool use_SDRAM)
	{
		double* vReal;
		double* vImag;
		// SDRAM only compatible with Portenta H7's M7 core
		#ifdef CORE_CM7
		if(use_SDRAM)
		{
			SDRAM.begin();
			vReal = (double*)SDRAM.malloc(len * sizeof(double));
			vImag = (double*)SDRAM.malloc(len * sizeof(double));
		}
		else
		{
			vReal = (double*)malloc(len * sizeof(double));
			vImag = (double*)malloc(len * sizeof(double));
		}
		#else
		// Force use of SRAM on non-M7 core
		vReal = (double*)malloc(len * sizeof(double));
		vImag = (double*)malloc(len * sizeof(double));
		#endif

		// initialize FFT
		arduinoFFT FFT = arduinoFFT(vReal, vImag, len, sampling_freq);

		// copy the samples into the real part of the FFT input
		for (unsigned long i = 0; i < len; i++)
		{
			vReal[i] = samples[i];
		}

		// Window the data using Welch's method
		FFT.Windowing(window_method, FFT_FORWARD);
		// Compute FFT
		FFT.Compute(FFT_FORWARD);
		// Convert to magnitude
		FFT.ComplexToMagnitude();

		return 0.0;
	}
}