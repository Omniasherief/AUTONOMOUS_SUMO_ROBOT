#define red_led A5
#define blue_led A4
#define echo_1 5
#define echo_2 2
#define echo_3 7
#define echo_4 8
#define trig_1 4
#define trig_2 3
#define trig_3 6
#define trig_4 9
int Distance_1 ;
int Distance_2 ;
int Distance_3 ;
int Distance_4 ;
long Duration_1 ;
long Duration_2 ;
long Duration_3 ;
long Duration_4 ;
#define IR_1 12
#define IR_2 13
#define IR_3 10
#define IR_4 11
#define Motor_1 A0  //left motor pin 1
#define Motor_2 A1  //left motor pin 2
#define Motor_3 A2 //right motor pin 1
#define Motor_4 A3 //right motor pin 2


void setup() {
  // put your setup code here, to run once:
 
  pinMode(echo_1, INPUT);
  pinMode(echo_2, INPUT);
  pinMode(echo_3, INPUT);
  pinMode(echo_4, INPUT);
  pinMode(trig_1, OUTPUT);
  pinMode(trig_2, OUTPUT);
  pinMode(trig_3, OUTPUT);
  pinMode(trig_4, OUTPUT);
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
  pinMode(Motor_1, OUTPUT);
  pinMode(Motor_2, OUTPUT);
  pinMode(Motor_3, OUTPUT);
  pinMode(Motor_4, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  digitalWrite(red_led, HIGH);
  delay(5000);
  digitalWrite(red_led, LOW);
  Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:
  //calculating front distance
  //start:
  digitalWrite(blue_led,HIGH);
  digitalWrite(trig_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_1, LOW);
  Duration_1 = pulseIn(echo_1, HIGH);
  Distance_1 = Duration_1*0.034/2;

  //calculating back distance
  digitalWrite(trig_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_2, LOW);
  Duration_2 = pulseIn(echo_2, HIGH);
  Distance_2 = Duration_2*0.034/2; 

  //calculating right distance
  digitalWrite(trig_3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_3, LOW);
  Duration_3 = pulseIn(echo_3, HIGH);
  Distance_3 = Duration_3*0.034/2;
 
  //calculating left distance
  digitalWrite(trig_4, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_4, LOW);
  Duration_4 = pulseIn(echo_4, HIGH);
  Distance_4 = Duration_4*0.034/2;

  int sensorValue_1 = digitalRead(IR_1); //back left
  int sensorValue_2 = digitalRead(IR_2); //back right
  int sensorValue_3 = digitalRead(IR_3); //front right
  int sensorValue_4 = digitalRead(IR_4); //front left
  
 if (Distance_1<=15 && Distance_1>0 ||Distance_2<=15 && Distance_2>0)
  { 
    ultraSonicCheck();
  }
  else
  {
  if(sensorValue_1==LOW||sensorValue_2==LOW||sensorValue_3==LOW||sensorValue_4==LOW) //ir
  {
  if(sensorValue_1==LOW&&sensorValue_4==LOW)
    {
    move90Right();
    moveForward();
    ultraSonicCheck();
    }
    else if(sensorValue_3==LOW&&sensorValue_2==LOW)
    {
    move90Left();
    moveForward();
    ultraSonicCheck();
    }
    else if(sensorValue_4==LOW&&sensorValue_3==LOW)
    {
    moveBackward();
    move180Left();
    ultraSonicCheck();
    }
   else if(sensorValue_1==LOW&&sensorValue_2==LOW)  
   {
    moveForward();
    ultraSonicCheck();
   }
   else if(sensorValue_1==LOW)
   {
    moveForwardAlittle();
    ultraSonicCheck();
   }
    else if(sensorValue_2==LOW)
   {
     moveForwardAlittle();
     ultraSonicCheck(); 
   }
   else if(sensorValue_3==LOW)
   {
    moveBackwardAlittle();
    move90Left();
    ultraSonicCheck(); 
   }
   else if(sensorValue_4==LOW)
   {
    moveBackwardAlittle();
    move90Right();
    ultraSonicCheck();
   } 
  }
   else 
   {
    //default move if there's no obstacle + checking ultrasonic sensors after each move
      

    ultraSonicCheck();
    /*delay(50);
    move45Right();     
    ultraSonicCheck();
    delay(50);
    move45Left();   
    ultraSonicCheck();
    delay(50);
   move45Left();     
    ultraSonicCheck();
    move45Right();    
    ultraSonicCheck();
    moveForwardAlittle();    
    ultraSonicCheck();*/
 }
}
}

void moveForward()
{
  unsigned long now = 0;
  now = millis();
  while(millis()<  now+2000)
  {
  digitalWrite(Motor_1,LOW);
  digitalWrite(Motor_2,HIGH);
  digitalWrite(Motor_3,LOW);
  digitalWrite(Motor_4,HIGH); 
  if(millis()>=now +2000)
  {
  break;
  }
    }
}
void moveForwardAlittle()
{
  unsigned long now = 0;

  now = millis();
  while(millis()< now+1000){
  digitalWrite(Motor_1,LOW);
  digitalWrite(Motor_2,HIGH);
  digitalWrite(Motor_3,LOW);
  digitalWrite(Motor_4,HIGH);
  //check forward}
  if(millis()>=now +1000)
  {
  break;
  }
}
}
void moveBackward()
{unsigned long now = 0;
  now = millis();
  while(millis()<  now+2000)
 { digitalWrite(Motor_1,HIGH);
  digitalWrite(Motor_2,LOW);
  digitalWrite(Motor_3,HIGH);
  digitalWrite(Motor_4,LOW);
  if(millis()>=now +2000)
  {
  break;
  }
 } //check backward
}
void moveBackwardAlittle()
{
  unsigned long now = 0;
  now = millis();
  while(millis()<  now+1000)
  {
  digitalWrite(Motor_1,HIGH);
  digitalWrite(Motor_2,LOW);
  digitalWrite(Motor_3,HIGH);
  digitalWrite(Motor_4,LOW);
   //check backward
   if(millis()>=now +1000)
   {
  break;
  }
}
}
void move45Right()
{
  unsigned long now = 0;
  now = millis();
  while(millis()<  now+550)
  {
  digitalWrite(Motor_1,HIGH);
  digitalWrite(Motor_2,LOW);
  digitalWrite(Motor_3,LOW);
  digitalWrite(Motor_4,HIGH);
   //check 45 right
   if(millis()>=now +550)
  {
  break;
  }
  }
}
void move45Left()
{unsigned long now = 0;
  now = millis();
  while(millis()<  now+550){
  digitalWrite(Motor_1,LOW);
  digitalWrite(Motor_2,HIGH);
  digitalWrite(Motor_3,HIGH);
  digitalWrite(Motor_4,LOW);
  if(millis()>=now +550)
  {
  break;
  }
   //check 45 left
  }
}
void move90Right()
{
  unsigned long now = 0;
  now = millis();
  while(millis()<  now+1100){
  digitalWrite(Motor_1,HIGH);
  digitalWrite(Motor_2,LOW);
  digitalWrite(Motor_3,LOW);
  digitalWrite(Motor_4,HIGH);
  if(millis()>=now +1100)
{
  break;
  } //check 90 right
}}
void move90Left()
{
  unsigned long now = 0;
  now = millis();
  while(millis()<  now +1100){
  digitalWrite(Motor_1,LOW);
  digitalWrite(Motor_2,HIGH);
  digitalWrite(Motor_3,HIGH);
  digitalWrite(Motor_4,LOW);
   //check 90 left
   if(millis()>=now +1100)
{
  break;
  }
}
}
void stop()
{ unsigned long now = 0;
  now = millis();
  while(millis()<  now +50){
    digitalWrite(Motor_1, LOW);
    digitalWrite(Motor_2, LOW);
    digitalWrite(Motor_3, LOW);
    digitalWrite(Motor_4, LOW);
    if(millis()>=now +50)
{
  break;
  }
}
}
void stopfr()
{
    digitalWrite(Motor_1, LOW);
    digitalWrite(Motor_2, LOW);
    digitalWrite(Motor_3, LOW);
    digitalWrite(Motor_4, LOW);
  //  delay(50);check stop
}
void move180Left()
{unsigned long now = 0;
  now = millis();
  while(millis()<  now+2200){
  digitalWrite(Motor_1,LOW);
  digitalWrite(Motor_2,HIGH);
  digitalWrite(Motor_3,HIGH);
  digitalWrite(Motor_4,LOW);
  if(millis()>=now +2200)
{
  break;
  }
  //check 180 left
}
}
void move360Left()
{
  unsigned long now = 0;
  now = millis();
  while(millis()< now +4400){
  digitalWrite(Motor_1,LOW);
  digitalWrite(Motor_2,HIGH);
  digitalWrite(Motor_3,HIGH);
  digitalWrite(Motor_4,LOW);
//check 360 left 4400
if(millis()>=now +4400)
{
  break;
  }
}

}
void ultraSonicCheck()
{
    ultrasonic:

  
  if(Distance_1<=57 && Distance_1>0||Distance_2<=57 && Distance_2>0||Distance_3<=57 && Distance_3>0||Distance_4<=57 && Distance_4>0)
    {
      
    if(Distance_1<=57&&Distance_1>0)
    {
      moveForwardAlittle();
    }
   else if (Distance_2<=57&&Distance_2>0)
    {
      move180Left();
      moveForwardAlittle();
     //moveBackwardAlittle();
    }
     else if (Distance_3<=57&&Distance_3>0)
    {
      move90Left(); 
      moveForwardAlittle();
    }
     else if (Distance_4<=57&&Distance_4>0)
    {
      move90Right();
      moveForwardAlittle();
    }
   

      
    }
    
     else
     {

      moveForwardAlittle();
      
     /*move45Right();
      if(Distance_1<=40 && Distance_1>0||Distance_2<=40 && Distance_2>0||Distance_3<=40 && Distance_3>0||Distance_4<=40 && Distance_4>0)
     {
      goto ultrasonic;
      delay(50);*/

     }
     /*move90Left();
      if(Distance_1<=40 && Distance_1>0||Distance_2<=40 && Distance_2>0||Distance_3<=40 && Distance_3>0||Distance_4<=40 && Distance_4>0)
     {
       goto ultrasonic;
     }
     move45Right();
      if(Distance_1<=40 && Distance_1>0||Distance_2<=40 && Distance_2>0||Distance_3<=40 && Distance_3>0||Distance_4<=40 && Distance_4>0)
     {
       goto ultrasonic;
     }*/
     }   
