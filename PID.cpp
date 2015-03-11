/**********************************************************************************************
 * Arduino PID Library - Version 0.0.1
 * by Walid Hosseini <caasjj@gmail.com> walidhosseini.com
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/
#include "Arduino.h"
#include "PID.h"

/********************************************************************************************* 
 *
 * PID Constructure
 *
 *********************************************************************************************/ 
PID::PID(PIDConfig config)
{
  _config = config;
  
  pinMode(_config.diagLedPin, OUTPUT);
  digitalWrite(_config.diagLedPin, LOW);  
  
  Sampler_setup(_config.adcChannel, _config.adcSampleRateHz, this, PID::_adcCallbackWrapper); 

}
 
/********************************************************************************************* 
 *
 * Class wrapper to allow ADC ISR to call back the UpdateLoop method of PID object
 * passed in pidPtr
 *
 *********************************************************************************************/ 
void PID::_adcCallbackWrapper(void *pidPtr, int adcValue) {
  PID* mySelf = (PID*) pidPtr;
  mySelf->UpdateLoop(adcValue);
}

/********************************************************************************************* 
 *
 * SetLoopConstants
 *
 *********************************************************************************************/ 
void PID::SetLoopConstants(float Kp, float Ki, float Kd)
{
   
}

/********************************************************************************************* 
 *
 * UpdateLoop
 *
 *********************************************************************************************/ 
void PID::UpdateLoop(int adcValue)
{
  _ledState = ~_ledState;
  digitalWrite(_config.diagLedPin, _ledState);
  
  _config.callback(adcValue);

}
  
/********************************************************************************************* 
 *
 * SetOutputLimits
 *
 *********************************************************************************************/ 
void PID::SetOutputLimits(double Min, double Max)
{
   
}

/********************************************************************************************* 
 *
 * Enable
 *
 *********************************************************************************************/ 
void PID::Enable(bool enabled)
{
    
}

 /********************************************************************************************* 
 *
 * EnableData
 *
 *********************************************************************************************/ 
void PID::EnableDataUpload( bool enabled )
{
    
}

/********************************************************************************************* 
 *
 * Getters - DEBUG only!
 *
 *********************************************************************************************/ 
double PID::GetKp(){ return  _dispKp; }
double PID::GetKi(){ return  _dispKi;}
double PID::GetKd(){ return  _dispKd;}

int PID::GetMode(){ return  _inAuto; }
int PID::GetDirection(){ return _controllerDirection;}









