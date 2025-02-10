#include <Servo.h> 
float distance1,distance2; 
int i,j,dist_c,dist_an,pos=0; 
int trigPin=12; 
int echoPin=13; 
int table[20][2]; 
int pinTravelTime; 
int z =0 ; 
Servo myservo; 
void setup() { 
// put your setup code here, to run once: 
myservo.attach(10); 
pinMode(trigPin,OUTPUT); 
pinMode(echoPin,INPUT); 
Serial.begin(9600); 
} 
void loop()  
{ 
if (z==0){ 
// put your main code here, to run repeatedly: 
i=1; 
for (pos = 0; pos <= 180; pos += 1) 
{  myservo.write(pos);      
distance1=ultrasonic(); 
delay(0.5); 
distance2=ultrasonic(); 
dist_c=(distance1+distance2)/2; 
dist_c=round(dist_c); 
i++; 
Serial.println(dist_c); 
Serial.println(i);                          
} 
j=1; 
for (pos = 180; pos >= 0; pos -= 1)  
{ 
myservo.write(pos);      
distance1=ultrasonic(); 
delay(0.5); 
distance2=ultrasonic(); 
dist_an=(distance1+distance2)/2; 
dist_an=round(dist_c); 
j++;                    
Serial.println(dist_an); 
Serial.println(j);      
} 
z=1; 
} 
} 
float ultrasonic() 
{ 
digitalWrite(trigPin,LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin,HIGH); 
delayMicroseconds(2); 
digitalWrite(trigPin,LOW); 
pinTravelTime=pulseIn(echoPin,HIGH); 
Serial.println(pinTravelTime*0.0034); 
pinTravelTime=pulseIn(echoPin,LOW); 
return pinTravelTime*0.0034; 
} 