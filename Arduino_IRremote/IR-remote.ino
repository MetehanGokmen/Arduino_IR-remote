#include <IRremote.h>
//First of all we must import the IRremote library to use in our codes
//İlk olarak IRremote kütüphanesini kodlarımızda kullanmak için içeri aktarmalıyız

#define IR_RECEIVE_PIN 5
//We define our receiver pin
//Alıcı pinimizi tanımlıyoruz
IRrecv IRrecv(IR_RECEIVE_PIN);

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  //We start the IrReceiver
  //IR alıcıyı başlatıyoruz
  
  Serial.begin(9600);
  //We start the serial port
  //Seri portumuzu başlatıyoruz
  pinMode(IR_RECEIVE_PIN, INPUT);
  //We say that we will receive data over this pin.
  //bu pin üzerinden veri alacağımızı söylüyoruz.
 
}

void loop() {
   delay(100);
  //We add the delay function to reduce clutter.
  //Delay fonksiyonunu dağınıklığı azatmak için ekliyouz
  if (IrReceiver.decode()) {
     
     
     Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    
     IrReceiver.resume();

  }
  //This code part tell us if arduino can decode the ır receiver message, it write the serial port screen.
  // bu kod parçası bize eğer ardino IR alıcımızın kodunu deşifre edebilirse seri port ekranına yazdırmasını söylüyor
  
}
