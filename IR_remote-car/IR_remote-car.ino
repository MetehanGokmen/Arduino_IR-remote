//First of all we import the IRremote library
//ilk olarak IRremote kütüphanesini içe aktarıyoruz
#include <IRremote.h>

//we tell that our arduino 5th pin is Ir remote receiver pin
//arduino içinde 5. pini alıcının gireceği data pini olarak belirliyoruz

#define IR_RECEIVE_PIN 5

//we tell that our arduino these pins are motor driver pins
//arduino içinde bu pinleri motor sürücü olarak belirliyoruz
#define MotorR1 6
#define MotorR2 7
#define MotorRE 9
#define MotorL1 4
#define MotorL2 3
#define MotorLE 2

//we tell that our arduino these are buttons names. IF you do not know your IR remote buttons name you can look other .ino file in this file. I write these codes for this mission.
//arduino içinde bu isimleri kumandanın tuşları olarak belirliyoruz. eğer kendş Ir kumandanızın tuşlarını bilmiyorsanız diğer .ino dosyasını kullnarank öğrenebilirsiniz.
#define forward 0xED120820
#define backward  0xEC130820
#define left   0xEB140820
#define right   0xE9160820
#define stand   0xEA150820




IRrecv IRrecv(IR_RECEIVE_PIN);

void setup() {
  //we start the serial port and IR receiver
  //seri portu ve IR alıcıyı başlatıyoruz

  IrReceiver.begin(IR_RECEIVE_PIN);
  Serial.begin(9600);
  
   
   //we set our pins. Receiver pin is input others are output.
  //pinlerimizi ayarlıyoruz. Alıcı pinini input diğerlerini output olarak ayarlıyoruz.
  pinMode(IR_RECEIVE_PIN,INPUT);
  pinMode(MotorR1, OUTPUT); 
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE,OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE,OUTPUT);
 
}



void loop() {
    //we add a delay function to block the overlapping. ıf you eant, you can increase the value or decrease it.
    //delay komutunu kumanda kodları üst üste binmesin diye koyuyoruz. isterseniz artırabilir ya da azaltabilirsiniz.
    delay(100);


    //we write if blocks to explain our arduino what does it do when press a spesific button.
    //belirli bir tuşa bastığımızda ne yapmasını gerektiğini anlatmak için arduinomuza if bolkları yazıyoruz
    if (IrReceiver.decode()) {
    if ((IrReceiver.decodedIRData.decodedRawData == forward)){
        ileri();
        
      } 
    }
      if (IrReceiver.decode()) {
    if ((IrReceiver.decodedIRData.decodedRawData == backward)) {
         geri();
         
      } 
    }
      if (IrReceiver.decode()) {
    if ((IrReceiver.decodedIRData.decodedRawData == left) ) {
         sol();
       
      } 
    }
      if (IrReceiver.decode()) {
    if ((IrReceiver.decodedIRData.decodedRawData == right)) {
         sag();
         
      } }
      if (IrReceiver.decode()) {
    if ((IrReceiver.decodedIRData.decodedRawData == stand)) {
         dur();
         
    }}
    
IrReceiver.resume();

}
//we write motion functions to dacrease the complexity
//karmaşıklığı azaltmak için haraket fonksiyonlarını yazıyoruz


void ileri() { 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 150); 
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 150); 
  
}
void geri() { 
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, 150); 
  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, 150); 

}
void sag() { 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0); 
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 150); 
 
}
void sol() { 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 150); 
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 0); // 
  
}
void dur() { 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
   analogWrite(MotorRE, 0);
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
   analogWrite(MotorLE, 0); 
   
}
