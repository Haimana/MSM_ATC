#include <ModbusRTUSlave.h>

// size of data which will be read and written
#define DATA_SIZE 100
// data array which will be read and written
u16 _D[DATA_SIZE];

// address (kind of name) of above data, may be anything
#define VIRTUAL_ADDRESS 0x0000

#define SLAVE_ID 2
#define DE_RE_PIN 13

ModbusRTUSlave rtu(SLAVE_ID, &Serial1, DE_RE_PIN);

void setup()
{ 
  rtu.addWordArea(VIRTUAL_ADDRESS, _D, DATA_SIZE);
  rtu.begin(9600);

  pinMode(A0, INPUT_PULLUP);  // set pull-up on analog pin 0 
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  Serial.begin(9600); // not needed, for logging purpose only

}

void loop()
{
  // set some value in data array to test if master can read and modify it
  _D[0] = analogRead(A0);
    delay(10);
  _D[1] = digitalRead(2);
    delay(10);
  _D[2] = digitalRead(3);
    delay(10);
  _D[3] = digitalRead(4);
    delay(10);
  _D[4] = digitalRead(5);
    delay(10);
  _D[5] = digitalRead(6);
    delay(10);
  _D[6] = digitalRead(7);
    delay(10);
  _D[7] = digitalRead(8);
    delay(10);
  _D[8] = digitalRead(9);
    delay(10);
  _D[9] = digitalRead(10);
    delay(10);
  _D[10] = digitalRead(11);
    delay(10);

  for (int i = 0; i <= 10; i++) {  
  Serial.print(_D[i]);
  if (i==0) {Serial.print(" - ");} else {Serial.print(" ");}
}
  Serial.println("");
  
  // waiting for requests from master
  // reading and writing _D according to requests from master happens here
  rtu.process();
    delay(10);
}
