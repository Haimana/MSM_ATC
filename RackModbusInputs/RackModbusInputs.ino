#include <ModbusRTUSlave.h>

// size of data which will be read and written
#define DATA_SIZE 100
// data array which will be read and written
u16 _D[DATA_SIZE];

// address (kind of name) of above data, may be anything
#define VIRTUAL_ADDRESS 0x0000

#define OUR_ID_AS_A_SLAVE 2
#define PIN_CONNECTED_TO_BOTH_DE_AND_RE 13

ModbusRTUSlave rtu(OUR_ID_AS_A_SLAVE, &Serial, PIN_CONNECTED_TO_BOTH_DE_AND_RE);

void setup()
{ 
  rtu.addWordArea(VIRTUAL_ADDRESS, _D, DATA_SIZE);
  rtu.begin(9600);

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
  pinMode(A0, INPUT_PULLUP);  // set pull-up on analog pin 0 

  //Serial.begin(9600); // not needed, for logging purpose only

}

void loop()
{
  // set some value in data array to test if master can read and modify it
  _D[0] = digitalRead(2);
  _D[1] = digitalRead(3);
  _D[2] = digitalRead(4);
  _D[3] = digitalRead(5);
  _D[4] = digitalRead(6);
  _D[5] = digitalRead(7);
  _D[6] = digitalRead(8);
  _D[7] = digitalRead(9);
  _D[8] = digitalRead(10);
  _D[9] = digitalRead(11);
  _D[10] = analogRead(A0);

  // waiting for requests from master
  // reading and writing _D according to requests from master happens here
  rtu.process();
}
