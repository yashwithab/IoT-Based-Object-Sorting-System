
#include <ESP32Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TCS34725.h>
#include<Wire.h>
Servo pickServo;
Servo dropServo;
const int s0 = 4;  
const int s1 = 2;  
const int s2 = 5;  
const int s3 = 19;  
const int out = 18;   
int red = 0;  
int green = 0;  
int blue = 0; 
int color=0;
int r=0;
int y=0;
int o=0;
int g=0;
int CLOSE_ANGLE = 30;
int OPEN_ANGLE = 10; 
void setup()   
{  
  Serial.begin(115200); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  pickServo.attach(21);
  dropServo.attach(13);
  pickServo.write(30);
  dropServo.write(73);
}

void loop() 
{  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  if(red<39 & red>29 & green<93 & green>83 &blue<78 & blue>69){
    dropServo.write(73);
    delay(700);
    r++;
    Serial.print("Red:");
    Serial.print(r);  
    open1();
    delay(200);
    close1();
  }
  if(green<75 & green>65 & blue<68 &blue>60){
    dropServo.write(107);
    delay(700);
    o++;
    Serial.print("Orange:");
    Serial.print(o);
    open1();
    delay(200);
    close1();
  }
  if(red<46 & red>36 & green<46 & green>37){
    dropServo.write(132);
    delay(700);
    g++;
    Serial.print("Green:");
    Serial.print(g);
    open1();
    delay(200);
    close1();
  }
  if(red<34 & red>25 & green<37 & green>28 & blue<53 & blue>43){
    dropServo.write(162);
    delay(700);
    y++;
    Serial.print("Yellow:");
    Serial.print(y);
    open1();
    delay(200);
    close1();
  } 
  Serial.println();  
 // delay(1000); 
} 
void open1(){ 
  pickServo.write(OPEN_ANGLE);
}
void close1(){ 
  pickServo.write(CLOSE_ANGLE);
}
