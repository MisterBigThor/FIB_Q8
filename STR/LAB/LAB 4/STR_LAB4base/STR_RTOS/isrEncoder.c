#ifndef _isr_encoder
#define _isr_encoder

signed int ISRCounter=0;//used inside the ISR

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
#endif
