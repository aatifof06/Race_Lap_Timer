/*
Created By: Er.AATHIF AHMED O F 
On ‎Sunday, ‎July ‎13, ‎2014, ‏‎7:13:49 PM

For MMSC Team 36 Racer Er.A.Shankar Guru.

*/



#include <LiquidCrystal.h>

#define blinkval 100 
#define delayval 60000 //Based On Race Circuit

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

int buzzer = 4;// buzzer
int blinking_led    = 3;
int button_trig = 7;    //tripping input
int rf_trig = 6;
float count, rcount, scount, prcount; //Vadiable clocks
float bcount = 999;

void setup(){
  
  Serial.begin(9600);          //Serial communication
  pinMode(button_trig,INPUT);     //button_trig as input
  pinMode(rf_trig,INPUT);     //button_trig as input
  pinMode(buzzer,OUTPUT);
  pinMode(blinking_led,OUTPUT);
  lcd.begin(16,2);  
  lcd.setCursor(0,0);
  lcd.print("HI! Shankar Guru");
  lcd.setCursor(0,1);
  lcd.print("HAVE A SAFE RIDE");

  do_buzzer(); 
  
  delay(delayval); // To Avoide Debounce
}

void loop(){
  count = millis();
    
  int button_trig_val =digitalRead(button_trig);
  int rf_trig_val =digitalRead(button_trig); 
  
  if (button_trig_val == HIGH || rf_trig_val == HIGH ) {
    rcount = (count - scount)/1000;    //Resultant count to print
    bcount = min(bcount,rcount);
    Serial.println(rcount, DEC);
    
    lcd.setCursor(0,0);
    lcd.print("NOW = "); 
    lcd.print(rcount);
    lcd.print(" sec     ");
    lcd.setCursor(0,1);
    lcd.print("Best= "); 
    lcd.print(bcount);
    lcd.print(" sec    "); 
    
    scount = count;                  //save count to subract
    do_buzzer();
    delay(delayval);
  }
}


void do_buzzer(){
  digitalWrite(buzzer,HIGH);
  digitalWrite(blinking_led,HIGH);
  delay(blinkval);
  digitalWrite(buzzer,LOW);
  digitalWrite(blinking_led,LOW);
  delay(blinkval);
  digitalWrite(buzzer,HIGH);
  digitalWrite(blinking_led,HIGH);
  delay(blinkval);
  digitalWrite(buzzer,LOW);
  digitalWrite(blinking_led,LOW);
  delay(blinkval);
  digitalWrite(buzzer,HIGH);
  digitalWrite(blinking_led,HIGH);
  delay(blinkval);
  digitalWrite(buzzer,LOW);
  digitalWrite(blinking_led,LOW);
  delay(blinkval);  
}
