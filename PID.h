#ifndef PID_h
#define PID_h
#define LIB_VERSION	    0.0.1

#include "Sampler2.h" 

typedef unsigned long ulong;

typedef struct PIDConfig {
  void (*callback)(int);
  int diagLedPin;
  int adcChannel;
  int adcSampleRateHz;
};

class PID
{

  public:     PID(PIDConfig config);
  
  public:  
    void      SetLoopConstants(float, float, float);                   
    void      UpdateLoop(int);								  
    void      SetOutputLimits(double, double);
    void      Enable(bool);							  					
    void      EnableDataUpload( bool );
    double    GetKp();						 
    double    GetKi();
    double    GetKd();	
    int       GetMode();	
    int       GetDirection();
              
  private:
    static void _adcCallbackWrapper(void *, int); 	
        
  private:
    PIDConfig _config;             // PID configuration structure passed to constructor
    bool     _ledState;
    double   _dispKp;		   // * we'll hold on to the tuning parameters in user-entered 
    double   _dispKi;		   //   format for display purposes
    double   _dispKd;		   //
    double   _kp;                  // * (P)roportional Tuning Parameter
    double   _ki;                  // * (I)ntegral Tuning Parameter
    double   _kd;                  // * (D)erivative Tuning Parameter
    int      _controllerDirection;
    double*  _myInput;             // * Pointers to the Input, Output, and Setpoint variables
    double*  _myOutput;            //   This creates a hard link between the variables and the 
    double*  _mySetpoint;          //   PID, freeing the user from having to constantly tell us
                                   //   what these values are.  with pointers we'll just know.
    ulong    _lastTime;
    double*  _ITerm;
    double*  _lastInput;
    ulong    _SampleTime;
    double   _outMin;
    double   _outMax;
    bool     _inAuto;
};
#endif


