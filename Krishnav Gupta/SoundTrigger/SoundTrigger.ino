byte soundSensor=2;
byte Light=13;
byte PIR=3;
int sensorState,sensorState1,sensorState2;
boolean lightState=0;
boolean PIRState=0;
void setup() {
  pinMode(Light,OUTPUT);
  pinMode(soundSensor, INPUT);
  pinMode(PIR, INPUT);
  Serial.begin(115200);
  digitalWrite(Light, LOW);
}

void loop() {
  sensorState1=digitalRead(soundSensor);
  
  delay(100);
  sensorState2=digitalRead(soundSensor);
  PIRState=digitalRead(PIR);
  sensorState=0;
  if(sensorState1==1 && sensorState2==1)
  {
    sensorState=1;
  }
  /*if(sensorState==1)
  {
    lightState=!lightState;
  }

  if(lightState)
  {
    digitalWrite(Light, HIGH);
  }
  if(!lightState)
  {
    digitalWrite(Light, LOW);
  }
 */

 if(sensorState==0 && PIRState== 0)// Turn off the Light No matter what
 {
    //digitalWrite(Light, LOW);
   // Serial.
   if(lightState)
    {
      digitalWrite(Light, HIGH);
    }
    if(!lightState)
    {
      digitalWrite(Light, LOW);
    }
 }

 if(sensorState==0 && PIRState== 1) // Sound not detected, person detected, keep light on for 10 seconds
 {
  digitalWrite(Light, HIGH);
  delay(10000);
  digitalWrite(Light, LOW);
  
 }
 if(sensorState==1 && PIRState== 0) // Sound Detected, No motion detected, change Light state
 {
    
    lightState=!lightState;
    
  
    if(lightState)
    {
      digitalWrite(Light, HIGH);
    }
    if(!lightState)
    {
      digitalWrite(Light, LOW);
    }
 }
 if(sensorState==1 && PIRState== 1) //Sound detected, person detected, keep light on for 10 seconds
 {
    digitalWrite(Light, HIGH);
    delay(10000);
    digitalWrite(Light, LOW);
 }

 
}


