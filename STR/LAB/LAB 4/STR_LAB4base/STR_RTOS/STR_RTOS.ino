#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#include <isrEncoder.c>

#define pinEncoderA 2//attach yellow wire from the motor to pin 2 of arduino
#define pinEncoderB 3//attach purple wire from the motor to pin 19 of arduino
#define pinPWM 11
#define pinDir 12
#define pinDirInv 10

#define kp 1.5
#define ki 0.0001
#define kd 0.01

TaskHandle_t taskPIDhandler;
TaskHandle_t taskUpdateMotor;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LED_BUILTIN,OUTPUT);
    
    pinMode(pinEncoderA, INPUT_PULLUP);
    pinMode(pinEncoderB, INPUT_PULLUP);
    
    pinMode(pinDir, OUTPUT);
    pinMode(pinDirInv, OUTPUT);
    pinMode(pinPWM, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(pinEncoderA), ISREncoderA, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pinEncoderB), ISREncoderB, CHANGE);
    
    Serial.begin(115200);
    // TIMER 1 for interrupt frequency 100 Hz:
    cli(); // stop interrupts
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0; // initialize counter value to 0
    OCR1A = 19999; // = 16000000 / (8 * 100) - 1 (must be <65536)
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);
    TIMSK1 |= (1 << OCIE1A);
    
    
    //function, name, stack_size, parameters, priority, handler
    xTaskCreate(taskPID, "PID", 128, NULL, 0, &taskPIDhandler);



    sei(); // allow interrupts
}

void loop() {
    

}

void taskPID(void * params){
   for (;;) {
    
      //https://www.freertos.org/vtaskdelayuntil.html
   }
   
}
