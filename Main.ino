#include<Servo.h>
#include<NewPing.h>
int a = 10; 
int a1 = 9;
int a2 = 8;
int b1 = 7; 
int b2 = 6; 
int b = 5; 
int R = A3;
int L = A0;
#define echopin 2
#define trigpin 3
float durationMicroSec;
float time;
int  Right_Value = digitalRead(R);
int Left_Value  = digitalRead(L);

NewPing sonar(trigpin, echopin);

void setup() {
pinMode(b1, OUTPUT);
pinMode(b2, OUTPUT);
pinMode(a1, OUTPUT);
pinMode(a2, OUTPUT);
pinMode(b, OUTPUT);
pinMode(a, OUTPUT);

pinMode(L, INPUT);
pinMode(R, INPUT);

delay(200);

  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin,  INPUT);
  sonar.ping_cm() == NO_ECHO;
}

void loop() {
unsigned int distance = read_cm();

int  Right_Value = digitalRead(R);
int Left_Value  = digitalRead(L);

Serial.print("R=  ");
Serial.print(Right_Value);
Serial.print(" L= ");
Serial.print(Left_Value);
Serial.print("  D= ");
Serial.println(distance);


if((Right_Value==1) && (distance>=10  && distance<30)&&(Left_Value==1))
{Forward();}

if((Right_Value==1) && (distance>30) && (Left_Value==1))
{Stop();}

if((Right_Value==0) && (distance>=10  && distance<30)&&(Left_Value==0))
{Forward();}

if((Right_Value==0) && (Left_Value==1))
{TurnRight();}

if((Right_Value==1) && (Left_Value==0))
{TurnLeft();}

if(distance > 5 && distance < 10)
{Stop();}

if((distance > 5 && distance < 10) && (Right_Value==0) && (Left_Value==0))
{Stop();}

if(distance < 5)
{Backward();}

if((Right_Value==0) && (distance < 5) && (Left_Value==0)){Backward();}
delay(50);
}

long read_cm(){
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);
  durationMicroSec = pulseIn(echopin, HIGH);
  time = 0.017*durationMicroSec;
  return time;
}
void Forward(){
analogWrite(a, 120); 
analogWrite(b, 120);
digitalWrite(a1, LOW);
digitalWrite(a2, HIGH);
digitalWrite(b1, HIGH);
digitalWrite(b2, LOW);  
}


void TurnLeft(){
analogWrite(a, 120); 
analogWrite(b, 120);
digitalWrite(a1, HIGH);
digitalWrite(a2, LOW);
digitalWrite(b1, HIGH);
digitalWrite(b2, LOW);  
}

void TurnRight(){
analogWrite(a, 120); 
analogWrite(b, 120);
digitalWrite(a1, LOW);
digitalWrite(a2, HIGH);
digitalWrite(b1, LOW);
digitalWrite(b2, HIGH);
}

void Stop(){
digitalWrite(a1, LOW);
digitalWrite(a2, LOW);
digitalWrite(b1, LOW);
digitalWrite(b2, LOW);
}
void Backward(){
analogWrite(a, 120); 
analogWrite(b, 120);
digitalWrite(a1,HIGH);
digitalWrite(a2,LOW);
digitalWrite(b1,LOW);
digitalWrite(b2,HIGH);
}
