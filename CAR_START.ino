
#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','S'},
  {'4','5','6','M'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; 
byte colPins[COLS] = {7, 6, 5, 4}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
 long long a=0;
 int str=0;
 int drunk=0;
void setup(){
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
  
int start_car(long long x, int drunk=0)
{
  while(millis()-a<5000)
  {
    if(analogRead(A0)>500)
    {
      drunk=1;
      break;
    }
    
  }
  if(drunk==1)
  {
    Serial.println("DRIVER IS DRUNK. CAR WILL NOT START");
    return 0;
  }
  else if(drunk==0)
  {
    Serial.println("CAR STARTED");
    return 1;
  }
  
}
void move_car()
{
  Serial.println("CAR MOVING");
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(5000);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  Serial.println("CAR STOPPED");
  }
void loop(){
  char customKey = customKeypad.getKey();
  if(customKey)
 {
  Serial.println(customKey);
  if(customKey=='S')
  {
    Serial.println("ATTEMPTING TO START CAR");
    a=millis();
    drunk=0;
    str=start_car(a,drunk);
  }
  else if(customKey='M' && str==1)
  {
    move_car();
  }
  else if(customKey='M' && str==0)
  {
    Serial.println("CAR NOT STARTED!");
  }
 }
}


