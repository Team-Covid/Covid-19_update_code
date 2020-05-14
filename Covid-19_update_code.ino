
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define triger 9 // pulse trigger
#define echo 8  // pulse note
#define led 13 // indicator for the operation of the sanitizer
#define pump A1 // pump signal
#define buzz 7 // alert creation
#define tempPin A0 // LM35 tempvalues


float temp;
float distance = 0;
float tim = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  measure_distance();
  if (distance < 10)
  {
    digitalWrite(led, HIGH);
    digitalWrite(pump, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    digitalWrite(pump, LOW);
    tempData();
    buzzr();
    
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(pump, LOW);
  }
  delay(500);
  

}

void measure_distance()
{
  digitalWrite(triger, LOW);
  delayMicroseconds(2);
  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);
  delayMicroseconds(2);
  tim = pulseIn(echo, HIGH);
  distance = tim * 340 / 20000;
}

void tempData(){
  lcd.clear();
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Serial.print("TEMPERATURE = " );
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  lcd.setCursor(0,1);
  lcd.print("TEMP IS: ");
  lcd.print(temp);
  
  delay(1000);
  
  }
void buzzr(){
  for(int i = 0; i < 9; i++){
    if(temp > 24.0){
    digitalWrite(7,HIGH);
    delay(200);
    digitalWrite(7,LOW);
    delay(200);
    }
   }
  }
