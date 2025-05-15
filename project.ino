#include <Servo.h>
Servo sg90;
int initial_position = 90;
int LDR1=A0;
int LDR2=A1;
int error =2;
int servopin=9;
int led1=10;
int fan1=5;
int state = 0;
int state1 = 0;

void setup()
{
sg90.attach (servopin);
pinMode (LDR1, INPUT);
pinMode (LDR2, INPUT);
pinMode (led1, OUTPUT);
pinMode (fan1, OUTPUT);
sg90.write(initial_position);
delay(200);
}
void loop()
{{
  int R1= analogRead(LDR1);
  int R2 =analogRead(LDR2);
  int diff1=abs(R1- R2);
  int diff2=abs(R2- R1);
  if((diff1 <= error) || (diff2 <= error))
  {
  } else { 
    if(R1 > R2)
    initial_position= --initial_position;
  }
  if(R1 < R2)
{

initial_position = ++initial_position;

}

sg90.write(initial_position);

delay(100);
}
{
   if(Serial.available() > 0){ // Checks whether data is coming from the serial port
        state = Serial.read(); // Reads the data from the serial port
    }

   
   if (state == '0') {
        digitalWrite(led1, LOW); // Turn LED OFF
        state = 0;
    }
    else if (state == '1') {
        digitalWrite(led1, HIGH);
        state=0;
    }

}

}