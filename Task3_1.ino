int led1 = A5; 
int led2 = D7; 

int photoTrans = A0;
int analogValue;

void setup(){

    Serial.begin(9600);
    
      pinMode(led1, OUTPUT);
      pinMode(led2, OUTPUT);
      pinMode(photoTrans ,  INPUT);
      
}

void loop(){
    
    analogValue = analogRead(photoTrans);
    
    if(analogValue > 15){
        digitalWrite(led1,LOW);
        digitalWrite(led2, LOW);
    } else {
        digitalWrite(led1 , HIGH);
        digitalWrite(led2 , HIGH);
    }
    
    String light = String(analogValue);
    Particle.publish("Light", light, PRIVATE);
    Serial.printlnf("The Photo-Transistor reading is: %d ",analogValue);
    
    delay(1000*30);
    
    
}
