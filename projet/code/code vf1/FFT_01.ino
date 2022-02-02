

#include "arduinoFFT.h"

#define SAMPLES 128
#define SAMPLING_FREQUENCY 2048

arduinoFFT FFT = arduinoFFT(); 


unsigned int samplingPeriod;
unsigned long microSeconds;


double vReal[SAMPLES];
double vImag[SAMPLES];


void setup()
{
  Serial.begin(115200);
  samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY));
}

void loop()
{
  
  for (int i = 0; i < SAMPLES; i++)
  {
    microSeconds = micros();
    vReal[i] = analogRead(0);
    vImag[i] = 0; 
  }
  /* Print the results of the simulated sampling according to time */
  
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);	/* Weigh data */
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD); /* Compute FFT */
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES); /* Compute magnitudes */
  
  double x = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
  Serial.println(x);
  //while(1); /* Run Once */
  delay(5000); /* Repeat after delay */
}
