/**********************************************************************************************
 * Arduino PID Controller Example - Version 0.0.1
 * by Walid Hosseini <caasjj@gmail.com> walidhosseini.com
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/
#include "Arduino.h"
#include "pid_controller.h"

void onUpdate(int value) {
  Serial.write(value>>8);
  Serial.write(value & 0xFF);
}

void setup() {
  
  PIDConfig config;
 
  config.diagLedPin       = DIAG_LED_PIN;
  config.adcChannel       = ADC_CHANNEL;
  config.adcSampleRateHz  = ADC_SAMPLE_RATE_HZ; 
  config.callback         = &onUpdate;
  
  PID* pid = new PID( config );

  Serial.begin( SERIAL_BAUD_RATE );
}

void loop() {

}
