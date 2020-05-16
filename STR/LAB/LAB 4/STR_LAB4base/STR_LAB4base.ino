//https://www.tinkercad.com/things/h3S85iQRm9e-str-lab-4/editel?sharecode=cALcYH_ERGAmHnAVeE1C7P88-S-lABlGDJDkDMz1cZM

#define pinEncoderA 2//attach yellow wire from the motor to pin 2 of arduino
#define pinEncoderB 3//attach purple wire from the motor to pin 19 of arduino
#define pinPWM 11
#define pinDir 12
#define pinDirInv 10

#define kp 1.5
#define ki 0.0001
#define kd 0.01

//function prototypes
void ISREncoderA(void);
void ISREncoderB(void);


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
    sei(); // allow interrupts
}  

unsigned long isr_timer1_count=0;
//Timer interrupt each 0.01 s

int setpoint = 0;
float u=0;
signed int ISRCounter=0;//used inside the ISR

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
  isr_timer1_count++;
    if ((isr_timer1_count%200)>100) {
      //u=10;    
        setpoint = 90;
    }      
    else {
      //u=-10;
        setpoint = -90;
    }
    u = PID((float)setpoint-ISRCounter);
    if ( (u>0) && (u<10) )u=10;
    if ( (u>-10) && (u<0) )u=-10;
  //check for motor direction
  if (u>=0)motorDirect();
  else motorInvert();
  
  //check for saturation
  if (u>255.0)u=255.0;
  if (u<-255.0)u=-255.0;

    analogWrite(pinPWM,abs(u));//update output
    Serial.print(setpoint);
    Serial.print(',');
    Serial.println(ISRCounter);
}
//Clockwise
inline void motorDirect(){
    digitalWrite(pinDir,0);
  digitalWrite(pinDirInv,1);
}
//antiClockwise
inline void motorInvert(){
  digitalWrite(pinDir,1);
  digitalWrite(pinDirInv,0);
}

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

int Old, New;
int QEM [16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0};

void ISREncoderB(void){//pinA change
    Old = New;
    New = digitalRead(pinEncoderA)*2 + digitalRead(pinEncoderB);
    ISRCounter -= QEM[Old*4 +New];
}
void ISREncoderA(void){//pinB change
    Old = New;
    New = digitalRead(pinEncoderA)*2 + digitalRead(pinEncoderB);
    ISRCounter -= QEM[Old*4 +New];
}
void loop(){
}
