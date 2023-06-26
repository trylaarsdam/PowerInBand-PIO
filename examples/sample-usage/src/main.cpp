#include <Arduino.h>
#include "PowerInBand.h"

#define WINDOW_METHOD FFT_WIN_TYP_WELCH
#define USE_SDRAM false

const uint16_t samples = 2048; //This value MUST ALWAYS be a power of 2
const double signalFrequency = 1000; //Frequency to be generated in our signal
const double samplingFrequency = 5000;
const uint8_t amplitude = 100;

void setup() {
	double vReal[samples];
  double cycles = (((samples-1) * signalFrequency) / samplingFrequency); //Number of signal cycles that the sampling will read
  for (uint16_t i = 0; i < samples; i++)
  {
    vReal[i] = int8_t((amplitude * (sin((i * (twoPi * cycles)) / samples))) / 2.0);/* Build data with positive and negative values*/
  }

	// Should be a very high number, as the band contains 1000Hz, which is the signal frequency we are generating.
	// If you were to change the band to 100Hz - 200Hz for example, it would be much lower.
	// In this case, we are using Welch's method for windowing, and not using SDRAM, as defined on lines 4 and 5
	double power = PowerInBand::Compute(vReal, samples, samplingFrequency, 900, 1100, WINDOW_METHOD, USE_SDRAM);

	// Log output to serial
	Serial.begin(9600);
	while(!Serial);
	Serial.print("Power: ");
	Serial.println(power);
}

void loop() {}
