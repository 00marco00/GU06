
#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

#include "arduinoFFT.h"

#define SAMPLES 128
#define SAMPLING_FREQUENCY 750

const uint16_t samples = SAMPLES; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = SAMPLING_FREQUENCY;

arduinoFFT FFT = arduinoFFT(); 


unsigned long samplingPeriod;
unsigned long microSeconds;
unsigned long previous_time;


double vReal[SAMPLES];
double vImag[SAMPLES];


void setup()
{
  Serial.begin(115200);
  samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY));
  Serial.print("period"); Serial.println(samplingPeriod);
}

void loop()
{
  for (int i = 0; i < SAMPLES; i++)
    vImag[i] = 0; 
  previous_time=0;
  for (int i = 0; i < SAMPLES; i++)
  {
    while(micros()<previous_time+samplingPeriod);
    //microSeconds = micros();
    vReal[i] = analogRead(0);
    previous_time=micros();
    //Serial.println((previous_time));
  }
  /* Print the results of the simulated sampling according to time */
  
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);	/* Weigh data */
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD); /* Compute FFT */
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES); /* Compute magnitudes */
    Serial.println("Computed magnitudes:");
  PrintVector(vReal, (samples >> 1), SCL_FREQUENCY);
  double x = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
 
    Serial.println(x);
    //while(1); /* Run Once */
    delay(3000); /* Repeat after delay */
    
  
}


void PrintVector(double *vData, uint16_t bufferSize, uint8_t scaleType)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    double abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
  break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
  break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
  break;
    }
    Serial.print(abscissa, 6);
    if(scaleType==SCL_FREQUENCY)
      Serial.print("Hz");
    Serial.print(" ");
    Serial.println(vData[i], 4);
  }
  Serial.println();
}
