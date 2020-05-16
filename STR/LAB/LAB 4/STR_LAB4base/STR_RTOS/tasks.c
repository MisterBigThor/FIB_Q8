#ifndef _TASKS
#define _TASKS

#define pinEncoderA 2//attach yellow wire from the motor to pin 2 of arduino
#define pinEncoderB 3//attach purple wire from the motor to pin 19 of arduino
#define pinPWM 11
#define pinDir 12
#define pinDirInv 10

#define kp 1.5
#define ki 0.0001
#define kd 0.01

//ENCODER LOGIC:int setpoint = 0;
float u=0;
unsigned long isr_timer1_count=0;
//PID logic:
float integral = 0;
float previousTime = 0;
float lastError = 0;
float PID(float error){
  
    float currentTime = isr_timer1_count*0.01;
    float elapsedT = (float)(currentTime - previousTime);
    float derivate = (error - lastError)/elapsedT;
    integral += (error * elapsedT);
  
    lastError = error;
    previousTime = elapsedT;
    return (kp * error) + (ki * integral) + (kd * derivate);
}


//motor logic:
inline void motorDirect(){
    digitalWrite(pinDir,0);
  digitalWrite(pinDirInv,1);
}

inline void motorInvert(){
  digitalWrite(pinDir,1);
  digitalWrite(pinDirInv,0);
}

#endif
