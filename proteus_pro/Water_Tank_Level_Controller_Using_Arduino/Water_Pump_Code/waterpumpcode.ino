// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

// defines pins numbers
const int trigPin = 5;
const int echoPin = 6;

const int Motor_Pin = 7;

// defines variables
long duration;
int distance;

bool Motor; //Make a bool Function for Motor ON/OFF

void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(Motor_Pin, OUTPUT); // Sets the Motor Pin as an Output
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2); //LCD order 
}
void loop() 
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance in cm
  distance = duration*0.034/2;
  int Level = map(distance, 0,1106, 0,100);

  // Prints the distance on the LCD
  lcd.setCursor(0,0); 
  lcd.print("Water: "); 
  lcd.print(Level);
  lcd.print("%     ");

  if(Level < 30)  //if Water Level is Less than 30%
  {
    Motor = true;  //Make The Bool True
  }
  if(Level >= 100)  //if Water Level is Greater than or Equal to 100%
  {
    Motor = false;  //Make The Bool False
  }

  if(Motor) //if Bool is True
  {
    digitalWrite(Motor_Pin, HIGH);
    lcd.setCursor(0,1); 
    lcd.print("Pump: ON      ");
  }
  else //if Bool is False
  {
    digitalWrite(Motor_Pin, LOW);
    lcd.setCursor(0,1); 
    lcd.print("Pump: OFF       ");
  } 
}




