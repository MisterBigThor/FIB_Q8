#include <Arduino_FreeRTOS.h>

//#define _DEBUG 1

#define pinEncoderA 2
#define pinEncoderB 3
#define pinPWM 11
#define pinDir 12
#define pinDirInv 10

void ISREncoderA(void);
void ISREncoderB(void);

static unsigned long isr_timer1_count=0;
int setpoint = 0;
float u=0;
int Old, New;
int QEM [16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0};
signed int ISRCounter=0;//used inside the ISR

float integral = 0;
float previousTime = 0;
float lastError = 0;
#define kp 1.5
#define ki 0.0001
#define kd 0.01


TaskHandle_t taskUpdateMotorHandle;

inline void setupRTOS(){
    xTaskCreate(TaskUpdateMotor, "upMotor", 128, NULL, 0, NULL);

}
void setup() {
    
    pinMode(pinEncoderA, INPUT_PULLUP);
    pinMode(pinEncoderB, INPUT_PULLUP);
    pinMode(pinDir, OUTPUT);
    pinMode(pinDirInv, OUTPUT);
    pinMode(pinPWM, OUTPUT);
    //attachInterrupt(digitalPinToInterrupt(pinEncoderA), ISREncoderA, CHANGE);
    //attachInterrupt(digitalPinToInterrupt(pinEncoderB), ISREncoderB, CHANGE);
    #ifdef _DEBUG
    Serial.begin(115200);
    #endif
    // TIMER 1 for interrupt frequency 100 Hz:
    cli();
    //FreeRTOS inits:
    setupRTOS();
    sei(); 

}

void loop() {

}

//This task must run every 100Hz (0.01s = 10ms)
//one tick is portTICK_PERIOD_MS ms
#define msTASK 10
void TaskUpdateMotor(void * params){   
    pinMode(LED_BUILTIN,OUTPUT);
    const TickType_t xDelay = msTASK/ portTICK_PERIOD_MS; 
    for(;;){
        vTaskDelay(xDelay);
        isr_timer1_count++;
        if ((isr_timer1_count%200)>100) {
          setpoint = 90;
          digitalWrite(LED_BUILTIN, LOW);
        }
        else {
          setpoint = -90;
          digitalWrite(LED_BUILTIN, HIGH);
        }
        u = PID((float)setpoint-ISRCounter);
        if ( (u>0) && (u<10) )u=10;
        if ( (u>-10) && (u<0) )u=-10;
        
        if (u>=0)motorDirect();
        else motorInvert();
        
        if (u>255.0)u=255.0;
        if (u<-255.0)u=-255.0;
        
        analogWrite(pinPWM,abs(u));
        #ifdef _DEBUG
          Serial.print(setpoint);
          Serial.print(',');
          Serial.println(ISRCounter);
        #endif
    }
}

float PID(float error){
  
    float currentTime = isr_timer1_count*0.01;
    float elapsedT = (float)(currentTime - previousTime);
    float derivate = (error - lastError)/elapsedT;
    integral += (error * elapsedT);
  
    lastError = error;
    previousTime = elapsedT;
    return (kp * error) + (ki * integral) + (kd * derivate);
}
void ISREncoderB(void){//pinA change
    Old = New;
    New = digitalRead(pinEncoderA)*2 + digitalRead(pinEncoderB);
    ISRCounter -= QEM[Old*4 +New];
    #ifdef _DEBUG
          Serial.println("ISREncoderB");
    #endif
}
void ISREncoderA(void){//pinB change
    Old = New;
    New = digitalRead(pinEncoderA)*2 + digitalRead(pinEncoderB);
    ISRCounter -= QEM[Old*4 +New];
    #ifdef _DEBUG
          Serial.println("ISREncoderA");
    #endif
}
inline void motorDirect(){
    digitalWrite(pinDir,0);
  digitalWrite(pinDirInv,1);
}
inline void motorInvert(){
  digitalWrite(pinDir,1);
  digitalWrite(pinDirInv,0);
}
