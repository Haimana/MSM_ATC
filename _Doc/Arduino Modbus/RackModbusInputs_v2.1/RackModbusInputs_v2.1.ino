#include <ModbusRTUSlave.h>

//v2.1 - increasing data size from 100 to 128
//      - removing delays
//      - increasing serial speed from 9600 to 38400 (max VFD can handle)
//      - adding jumer config for modbus speed

// size of data which will be read and written
#define DATA_SIZE 48
// data array which will be read and written
u16 _D[DATA_SIZE];

// address (kind of name) of above data, may be anything
#define VIRTUAL_ADDRESS 0x0000

#define SLAVE_ID 2
#define DE_RE_PIN 2

ModbusRTUSlave rtu(SLAVE_ID, &Serial1, DE_RE_PIN);

void setup()
{
  Serial.begin(115200); // not needed, for logging purpose only

  rtu.addWordArea(VIRTUAL_ADDRESS, _D, DATA_SIZE);

// modbus_speed jumpers config
  pinMode(52, INPUT_PULLUP);
  pinMode(53, INPUT_PULLUP);
  bool pinJ1 = digitalRead(52);
  bool pinJ2 = digitalRead(53);
  long modbus_speed = 9600;
  if (pinJ1 == HIGH && pinJ2 == HIGH) {modbus_speed = 9600;}
  if (pinJ1 == LOW && pinJ2 == HIGH) {modbus_speed = 19200;}
  if (pinJ1 == HIGH && pinJ2 == LOW) {modbus_speed = 38400;}
  if (pinJ1 == LOW && pinJ2 == LOW) {modbus_speed = 57600;}
  rtu.begin(modbus_speed);

  Serial.println(modbus_speed);

  pinMode(A0, INPUT_PULLUP);  // set pull-up on analog pin 0
  
  pinMode(A1, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A2, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A3, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A4, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A5, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A6, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A7, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A8, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A9, INPUT_PULLUP);  // set pull-up on analog pin 0
  pinMode(A10, INPUT_PULLUP);  // set pull-up on analog pin 0
  
  //  pinMode(2, INPUT_PULLUP);
  //  pinMode(3, INPUT_PULLUP);
  //  pinMode(4, INPUT_PULLUP);
  //  pinMode(5, INPUT_PULLUP);
  //  pinMode(6, INPUT_PULLUP);
  //  pinMode(7, INPUT_PULLUP);
  //  pinMode(8, INPUT_PULLUP);
  //  pinMode(9, INPUT_PULLUP);
  //  pinMode(10, INPUT_PULLUP);
  //  pinMode(11, INPUT_PULLUP);


}

void loop()
{
  // set some value in data array to test if master can read and modify it
  _D[0] = analogRead(A1);
//      delay(10);
  _D[1] = analogRead(A2);
//      delay(10);
  _D[2] = analogRead(A3);
//      delay(10);
  _D[3] = analogRead(A4);
//      delay(10);
  _D[4] = analogRead(A5);
//      delay(10);
  _D[5] = analogRead(A6);
//      delay(10);
  _D[6] = analogRead(A7);
//      delay(10);
  _D[7] = analogRead(A8);
//      delay(10);
  _D[8] = analogRead(A9);
//      delay(10);
  _D[9] = analogRead(A10);
//      delay(10);

  _D[10] = analogRead(A0);
//      delay(10);

  for (int i = 0; i <= 10; i++) {

    if (i < 10) {
      if (_D[i] > 400) {
        _D[i] = 1;
      } else {
        _D[i] = 0;
      }
      //    delay(10);
    }

//    if (i == 10) {
//      Serial.print(" - ");
//    } else {
//      Serial.print(" ");
//    }
//    Serial.print(_D[i]);
//        delay(10);
  }
//  Serial.println("");

  // waiting for requests from master
  // reading and writing _D according to requests from master happens here
  rtu.process();
//      delay(10);
}
