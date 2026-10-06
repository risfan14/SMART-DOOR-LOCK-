#include <Keypad.h>
#include <Servo.h>

Servo myservo;

byte bunyi = 12;

//unsigned long t_benar  = millis();
//bool pass_benar = false;

const byte ROWS = 4; 
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char data;
String kata = "";
String password = "145B";

byte push = 11;


void setup() {
  Serial.begin(9600);

  myservo.attach(10);
  
  kata = "";
  kata.reserve(20);

  pinMode(push, INPUT_PULLUP); 
  pinMode(bunyi, OUTPUT);
}

void loop() {
  data = keypad.getKey();

  if(data){
    if(data == '*'){
      kata = "";
      Serial.print("kalimat : ");
      Serial.println(kata);
    }else if(data == '#'){
      if(kata == password){
        Serial.println("password benar");
        digitalWrite(bunyi, HIGH);
        delay(200);
        digitalWrite(bunyi, LOW);
        myservo.write(0);
        delay(9000);
        myservo.write(110);
//         pass_benar = true; 
      }else{
        Serial.println("password salah");
        digitalWrite(bunyi, HIGH);
        delay(500);
        digitalWrite(bunyi, LOW);
      }

      kata = "";
    }else{
      kata += data;
      Serial.println(kata);
      }
  }
  
  if(digitalRead(push) == LOW){
    Serial.println("password benar");
    digitalWrite(bunyi, HIGH);
    delay(200);
    digitalWrite(bunyi, LOW);
     myservo.write(0);
     delay(9000);
     myservo.write(110);
  }
//  if(pass_benar){
//    digitalWrite(bunyi, HIGH); 
//    delay(500);
////    if(millis() - t_benar >= 500){
////      t_benar = millis();
//      digitalWrite(bunyi, LOW);
//      pass_benar = false; 
////    }   
//  }
}
