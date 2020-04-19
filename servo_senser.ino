#define trigPin D1 // trigger pin for Ultrasonic HC-SR04
#define echoPin D2 // echo pin for Ultrasonic HC-SR04

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo myservo;
long duration;
int distance;

char auth[] = "WzWq-JT4U6tGvBIPF4lWQoRfh75l8Nr3";
char ssid[] = "MSI";
char pass[] = "0631467311";

void setup() {
  Serial.begin(9600);
   Blynk.begin(auth,ssid,pass);
myservo.attach(D3); //ต่อขา3
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
 
}
void loop(){
{
  Blynk.run();
  }

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
if (distance <= 10)
{

myservo.write(150);
delay(500);

}
else {
myservo.write(0);
delay(250);
}

       
}
