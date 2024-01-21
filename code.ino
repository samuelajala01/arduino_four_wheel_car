/*
Author: Samuel Ajala
*/
char state = 0;
//FRONT WHEELS

//set up wheel 1
const int MTR1FRONT = 7;
const int MTR1BACK = 8;

//set up wheel 2
const int MTR2FRONT = 9;
const int MTR2BACK = 10;

//set up wheel 3
const int MTR3FRONT = 11;
const int MTR3BACK = 12;

//set up wheel 4
const int MTR4FRONT = 13;
const int MTR4BACK = 14;

void setup() {
    Serial.begin(9600); //to set up the serial monitor
    // Set each pins to output
  
    pinMode(MTR1FRONT, OUTPUT);
    pinMode(MTR1BACK, OUTPUT);
    pinMode(MTR2FRONT, OUTPUT);
    pinMode(MTR2BACK, OUTPUT);
    pinMode(MTR3FRONT, OUTPUT);
    pinMode(MTR3BACK, OUTPUT);
    pinMode(MTR4FRONT, OUTPUT);
    pinMode(MTR4BACK, OUTPUT);
    
    digitalWrite(MTR1FRONT, LOW);
    digitalWrite(MTR1BACK, LOW);
    digitalWrite(MTR2FRONT, LOW);
    digitalWrite(MTR2BACK, LOW);
    digitalWrite(MTR3FRONT, LOW);
    digitalWrite(MTR3BACK, LOW);
    digitalWrite(MTR4FRONT, LOW);
    digitalWrite(MTR4BACK, LOW);
    
}

void goForward(){
  digitalWrite(MTR1FRONT, HIGH);
  digitalWrite(MTR2FRONT, HIGH);
  digitalWrite(MTR3FRONT, HIGH);
  digitalWrite(MTR4FRONT, HIGH);
}
void goBackward(){
  digitalWrite(MTR1BACK, HIGH);
  digitalWrite(MTR2BACK, HIGH);
  digitalWrite(MTR3BACK, HIGH);
  digitalWrite(MTR4BACK, HIGH);
}

void goRight(){
  digitalWrite(MTR1FRONT, HIGH);
  digitalWrite(MTR3FRONT, HIGH);
   digitalWrite(MTR2FRONT, LOW);
  digitalWrite(MTR4FRONT, LOW);
}
void goLeft(){
  digitalWrite(MTR2FRONT, HIGH);
  digitalWrite(MTR4FRONT, HIGH);
   digitalWrite(MTR1FRONT, LOW);
  digitalWrite(MTR3FRONT, LOW);
}

void loop() {
    if(Serial.available() > 0){
       state = Serial.read();
       Serial.print(state);
        if(state = "F"){
          digitalWrite(13, HIGH);
          goForward();
        } else if (state == "B"){
          goBackward();
        } else if (state == "L"){
          goLeft();
        }else if (state == "R"){
          goRight();
        }
        else{
          digitalWrite(MTR1FRONT, LOW);
           digitalWrite(MTR1BACK, LOW);
        }

    }
}
