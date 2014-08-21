long distance;
long time;

int button=8;        
int led=13;            
int pinEcho = 7;
int pinTrigger =5;

void setup(){
  Serial.begin(9600);
  
  pinMode(pinEcho, OUTPUT); 
  pinMode(pinTrigger, INPUT); 

  pinMode(led,OUTPUT);
  pinMode(button,OUTPUT);
}

void loop(){
  digitalWrite(pinEcho,LOW); 
  delayMicroseconds(5);
  digitalWrite(pinEcho, HIGH); 
  delayMicroseconds(10);
  time=pulseIn(pinTrigger, HIGH); 
  distance= int(0.017*time); 
  



  if(distance<20 || digitalRead(button)==HIGH){
    Serial.println("ON");
    digitalWrite(led,HIGH);
    delay(6000); 
  }

  else{
    Serial.println("OFF");
    digitalWrite(led,LOW);
  }


  delay(1000);
}


