#include <Arduino.h>

const int TrigPin=21;
const int EchoPin=19;

const int BuzzerPin=23;

const int LedGreen_1=14;
const int LedGreen_2=5;
const int LedYellow_1=25;
const int LedYellow_2=26;
const int LedRed_1=32;
const int LedRed_2=22;

const int Distanta_1=60;
const int Distanta_2=50;
const int Distanta_3=40;
const int Distanta_4=30;
const int Distanta_5=20;
const int Distanta_6=10;

const long Interval = 10;

void setup(){
pinMode(LedRed_1, OUTPUT);
pinMode(LedRed_2, OUTPUT);
pinMode(LedYellow_1, OUTPUT);
pinMode(LedYellow_2, OUTPUT);
pinMode(LedGreen_1, OUTPUT);
pinMode(LedGreen_2, OUTPUT);
pinMode(BuzzerPin, OUTPUT);
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);

Serial.begin(115200);

}

void loop(){

 digitalWrite(TrigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(TrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(TrigPin, LOW);

 long durata = pulseIn(EchoPin, HIGH);

 int distanta = durata * 0.034/2;

 if(distanta > 400){
   Serial.println("Obiect in afara razei de detectie");
   distanta = -1;
   }


 if(distanta != -1){

  Serial.print("Distanta este: ");
  Serial.println(distanta);
  Serial.println(" cm");
 
 if(distanta <= Distanta_6){
   digitalWrite(LedRed_1, HIGH);
   digitalWrite(LedRed_2, HIGH);
   digitalWrite(LedYellow_1, HIGH);
   digitalWrite(LedYellow_2, HIGH);
   digitalWrite(LedGreen_1, HIGH);
   digitalWrite(LedGreen_2, HIGH);
   analogWrite(BuzzerPin, 255);
   
   

  } else if(distanta <= Distanta_5){
   digitalWrite(LedRed_1, HIGH);
   digitalWrite(LedRed_2, LOW);
   digitalWrite(LedYellow_1, HIGH);
   digitalWrite(LedYellow_2, HIGH);
   digitalWrite(LedGreen_1, HIGH);
   digitalWrite(LedGreen_2, HIGH);
   analogWrite(BuzzerPin, 200);
  

  } else if (distanta <= Distanta_4){
   digitalWrite(LedRed_1, LOW);
   digitalWrite(LedRed_2, LOW);
   digitalWrite(LedYellow_1, HIGH);
   digitalWrite(LedYellow_2, HIGH);
   digitalWrite(LedGreen_1, HIGH);
   digitalWrite(LedGreen_2, HIGH);
   analogWrite(BuzzerPin, 170);
   delay(500);
   analogWrite(BuzzerPin, LOW);

  } else if(distanta <= Distanta_3){
   digitalWrite(LedRed_1, LOW);
   digitalWrite(LedRed_2, LOW);
   digitalWrite(LedYellow_1, HIGH);
   digitalWrite(LedYellow_2, LOW);
   digitalWrite(LedGreen_1, HIGH);
   digitalWrite(LedGreen_2, HIGH);
   analogWrite(BuzzerPin, 110);
   delay(500);
   analogWrite(BuzzerPin, LOW);

  } else if (distanta <= Distanta_2){
   digitalWrite(LedRed_1, LOW);
   digitalWrite(LedRed_2, LOW);
   digitalWrite(LedYellow_1, LOW);
   digitalWrite(LedYellow_2, LOW);
   digitalWrite(LedGreen_1, HIGH);
   digitalWrite(LedGreen_2, HIGH);
   analogWrite(BuzzerPin, 85);
   delay(500);
   analogWrite(BuzzerPin, LOW);

  } else if (distanta <= Distanta_1){
   digitalWrite(LedRed_1, LOW);
   digitalWrite(LedRed_2, LOW);
   digitalWrite(LedYellow_1, LOW);
   digitalWrite(LedYellow_2, LOW);
   digitalWrite(LedGreen_1, HIGH);
   digitalWrite(LedGreen_2, LOW);
   analogWrite(BuzzerPin, 50);
   delay(500);
   analogWrite(BuzzerPin, LOW);
 } else {
   digitalWrite(LedRed_1, LOW);
   digitalWrite(LedRed_2, LOW);
   digitalWrite(LedYellow_1, LOW);
   digitalWrite(LedYellow_2, LOW);
   digitalWrite(LedGreen_1, LOW);
   digitalWrite(LedGreen_2, LOW);
   analogWrite(BuzzerPin, 0);
 }
 }
 delay(Interval);

}

