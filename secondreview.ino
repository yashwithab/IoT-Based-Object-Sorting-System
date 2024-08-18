#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TCS34725.h>
#include<ThingSpeak.h>
Servo pickServo;
Servo dropServo;
const int s0 = 19;  
const int s1 = 18;  
const int s2 = 2;  
const int s3 = 4;  
const int out = 15;   
int red,blu,grn,white,yellow,pink;
int r=0;
int w=0;
int b=0;
int g=0;
int y=0;
int p=0;
int CLOSE_ANGLE = 90;
int OPEN_ANGLE = 0; 
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
  pickServo.attach(13);
  dropServo.attach(21);
  pickServo.write(90);
  dropServo.write(180);
}

void loop() 
{  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2,LOW);
  digitalWrite(s3, HIGH);  
  blu = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  digitalWrite(s3,HIGH);
  grn = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2,HIGH);
  digitalWrite(s3, LOW);  
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);   
  Serial.print(" G Intensity: ");  
  Serial.print(grn, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blu, DEC); 
  Serial.println();
  delay(1000);
  (red>20 && red<25  && grn>38 && grn<45 && blu>13 && blu<15){
    dropServo.write(120);
    delay(100);
    r++;
    Serial.print("red:");
    Serial.println(r);  
    open1();
    delay(1000);
    close1();
  }
 (red>24 && red<27  && grn>35 && grn<40 && blu>12 && blu<15)
  {
    dropServo.write(145);
    delay(1000);
    g++;
    Serial.print("green :");
    Serial.println(g);
    open1();
    delay(2000);
    close1();
  }
 (red>24 && red<28  && grn>36 && grn<38 && blu>12  && blu<15)
  {
    dropServo.write(155);
    delay(1000);
    b++;
    Serial.print("blue :");
    Serial.println(b);
    open1();
    delay(1000);
    close1();
  }
if(red>18  && red<21   && grn>30  && grn<33 && blu>9  && blu<13)
  {
    dropServo.write(165);
    delay(1000);
    y++;
    Serial.print("yellow:");
    Serial.println(y);
    open1();
    delay(1000);
    close1();
  } 
  if(red>10  && red<14   && grn>14  && grn<18  && blu>5  && blu<8)
  {
   dropServo.write(175);
    delay(1000);
    w++;
    Serial.print("white:");
    Serial.println(w);
    open1();
    delay(1000);
    close1();
  }
  if(red>16 && red<19 && grn>30 && grn<34 && blu>9 && blu<13)
  {
    dropServo.write(185);
    delay(1000);
    p++;
    Serial.print("pink:");
    Serial.println(p);
    open1();
    delay(1000);
    close1();
  } 
  else 
  {
    Serial.print("NO OBJECT PLACED"); 
    dropServo.write(180);

  }
  Serial.println();  
 // delay(3000); 
} 
void open1(){ 
  pickServo.write(OPEN_ANGLE);
  //delay(3000);
}
void close1(){ 
  pickServo.write(CLOSE_ANGLE);
}
