#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53

void setup() {
  pinMode(X_STEP_PIN,OUTPUT);
  pinMode(X_DIR_PIN,OUTPUT);
  pinMode(X_ENABLE_PIN,OUTPUT);
  pinMode(X_CS_PIN,OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(X_CS_PIN, LOW);
}

void loop() {
  digitalWrite(X_DIR_PIN, LOW);
  for(int i=0;i<11378;i++)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(100);   
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(100);
    
  }

  digitalWrite(X_ENABLE_PIN, HIGH);
 
  
  

}
