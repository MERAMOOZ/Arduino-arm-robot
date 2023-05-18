// MOTORS PIN 
const byte dcpin1=10;
const byte dcpin2=11;
const byte dcpin3=12;
const byte dcpin4=13;
// SERVO
#include <Servo.h>
// S1
Servo myservo1; 
int ang1=0;

//S2
Servo myservo2;
int ang2=0;
 
//S3
Servo myservo3; 
int ang3=0;

//S4
Servo myservo4; 
int ang4=0;

//ULTRA PIN 
const byte Trigger=3;
const byte Echo=2;
float distance;
float duration;

//  buzzer
const byte buz= 4;

// rtc 
#include <Wire.h>
#include "RTClib.h"

DS1307 rtc;


void setup() {
   Serial.begin(57600);
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
Serial.begin (9600);
//OTORS DIFF 
pinMode(dcpin1,OUTPUT);
pinMode(dcpin2,OUTPUT);
pinMode(dcpin3,OUTPUT);
pinMode(dcpin4,OUTPUT);
//SERVO DEFF
  myservo1.attach(9);
  myservo2.attach(8);
  myservo3.attach(7);
  myservo4.attach(6);

// ULTRA DIFF
pinMode(Trigger,OUTPUT);
pinMode(Echo,INPUT);
//buzzer 
pinMode(buz,OUTPUT);

}




void loop() {
     DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");

    if (now.second()== 30){
      tone (buz,2000);
      delay(500);
      tone (buz,1000);
      delay(1000);
      }
      else if (now.hour()==07&&now.minute()==00&&now.second()==00) {
      tone (buz,2000);
      delay(500);
      tone (buz,1000);
      delay(1000);
        }
     else if (now.hour()==04&&now.minute()==30&&now.second()==00) {
      tone (buz,2000);
      delay(500);
      tone (buz,1000);
      delay(1000);
        }
     else if (now.hour()==10&&now.minute()==45&&now.second()==30) {
      tone (buz,2000);
      delay(500);
      tone (buz,1000);
      delay(1000);
        }
    
  int currentdistance ;
  currentdistance= ultra( );
  // BELTOOTH WORK ON 
  if (Serial.available()){
 char x= Serial.read();
 if (distance<20){
       digitalWrite (buz,HIGH);
  }
  else if (distance<5){
 digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
    } 
   if (x=='1'){
    Serial.print("f");
digitalWrite(dcpin1,HIGH);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,HIGH);
digitalWrite(dcpin4,LOW);
 if (distance<20){
       digitalWrite (buz,HIGH);
  }
  else if (distance<5){
 digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
    } 
}
else if (x=='2'){
  Serial.print("b");
  
digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,HIGH);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,HIGH);
 if (distance<20){
       digitalWrite (buz,HIGH);
  }
  else if (distance<5){
 digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
    } 
}
  else if (x=='3'){
    Serial.print("r");
digitalWrite(dcpin1,HIGH);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
 if (distance<20){
       digitalWrite (buz,HIGH);
  }
  else if (distance<5){
 digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
    } 
  }
  else if (x=='4'){
  Serial.print("l");
digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,HIGH);
digitalWrite(dcpin4,LOW);
 if (distance<20){
       digitalWrite (buz,HIGH);
  }
  else if (distance<5){
 digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
    } 
}

else if (x=='5'){
  for (ang1=0;ang1<=180;ang1++){
    myservo1.write(ang1);
    delay(10);
 }
 }
 else if (x=='6'){
 for (ang1=180;ang1>=0;ang1--){
  myservo1.write(ang1);
  delay(10); 
 }
 }
else if (x=='7'){
  for (ang2=0;ang2<=180;ang2++){
    myservo2.write(ang2);
    delay(10);
 }
 }
 else if (x=='8'){
 for (ang2=180;ang2>=0;ang2--){
  myservo2.write(ang2);
  delay(10); 
 }
 }
 else if (x=='9'){
  for (ang3=0;ang3<=180;ang3++){
    myservo3.write(ang3);
    delay(10);
 }
 }
 else if (x=='0'){
 for (ang3=180;ang3>=0;ang3--){
  myservo3.write(ang3);
  delay(10); 
 }
 }
 else if (x=='A'){
  for (ang4=0;ang4<=180;ang4++){
    myservo4.write(ang4);
    delay(10);
 }
 }
 else if (x=='B'){
 for (ang4=180;ang4>=0;ang4--){
  myservo4.write(ang4);
  delay(10); 
  
 }
 }
 else {
  Serial.print("s");
digitalWrite(dcpin1,LOW);
digitalWrite(dcpin2,LOW);
digitalWrite(dcpin3,LOW);
digitalWrite(dcpin4,LOW);
}
 }
  }
  
  long ultra ( ){
float distanse;
float periode ;
  digitalWrite (Trigger,LOW);
  delayMicroseconds (2);
  digitalWrite (Trigger,HIGH);
  delayMicroseconds (5);
  digitalWrite (Trigger,LOW);

periode = pulseIn (Echo,HIGH );

distanse = periode  / 58.8 ;

Serial.print (distanse );
Serial.println (" ");
delay (100);
return distanse ;
}
