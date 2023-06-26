# Power in Band Calculator
This library provides an easy API to calculate the power in a given frequency band of a signal. 

## Attribution
This library uses the [arduinoFFT](https://github.com/kosme/arduinoFFT) library by kosme to compute the FFT of the signal.

## Usage
The library provides a single namespace, `PowerInBand`, which can be used to calculate the power in a given frequency band of a signal.

### `PowerInBand::Compute`
This function allows you to compute the power in band of a signal. It has 3 overloads:
```cpp
/// @brief Computers the power in band of the given sample buffer using the default of Welch's method for windowing, and SRAM
/// @param samples Pointer to the raw data
/// @param len Amount of data to be computed - this *must* be a power of 2
/// @param sampling_freq Sampling frequency of the data
/// @param lower_freq Lower frequency of the band
/// @param upper_freq Upper frequency of the band
/// @return The power in band of the specified frequency range
float Compute(float* signal, uint16_t signalLength, float sampleRate, float lowerBound, float upperBound);
```
```cpp
/// @brief Computers the power in band of the given sample buffer in SRAM
/// @param samples Pointer to the raw data
/// @param len Amount of data to be computed - this *must* be a power of 2
/// @param sampling_freq Sampling frequency of the data
/// @param lower_freq Lower frequency of the band
/// @param upper_freq Upper frequency of the band
/// @param window_method Windowing method to use
/// @return The power in band of the specified frequency range
double Compute(double *samples, unsigned long len, double sampling_freq, double lower_freq, double upper_freq, FFTWindow window_method);
```
```cpp
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
```

All of these functions return a double representing the power in band of the specified frequency range, which is computed using a midpoint Riemann sum.