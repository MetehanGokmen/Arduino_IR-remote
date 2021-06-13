#include <IRremote.h>
#define IR_RECEIVE_PIN 5
IRrecv IRrecv(IR_RECEIVE_PIN);
void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  Serial.begin(9600);
  pinMode(IR_RECEIVE_PIN, INPUT);
 
}

void loop() {
   delay(100);
  if (IrReceiver.decode()) {
     
     
     Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.resume();

  }
}
