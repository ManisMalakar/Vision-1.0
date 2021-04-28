
// Include Libraries
#include "Arduino.h"
#include "NewPing.h"
#include "Buzzer.h"


// Pin Definitions
#define BUZZER_PIN_SIG  2
#define HCSR04_PIN_TRIG	4
#define HCSR04_PIN_ECHO	3




// Global variables and defines
const int trigPin = 4;
const int echoPin = 3;
const int buzzPin=2;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;

// object initialization
Buzzer buzzer(buzzPin);
NewPing hcsr04(HCSR04_PIN_TRIG,HCSR04_PIN_ECHO);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(ledPin, OUTPUT);
pinMode(buzzPin,OUTPUT);
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
 
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
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


// Calculating the distance
distance= duration / 29 / 2;      


if(distance<=100 && distance>0)   { 
     
  tone(buzzPin,6000,500);
  
  
  digitalWrite(ledPin, HIGH);
  
}else{
    digitalWrite(ledPin, LOW);
}
    
    Serial.print(F("Distance: ")); Serial.print(distance); Serial.println(F("[cm]"));

    }
   





// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
 long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  }   
