/*
  Intruder
  From Arduino Project Book by Mark Geddes

  Note: Looing at the BACK of the ultrasonic distance sensor the pinouts are: 
     GND  ECHO  TRIG  5V
     
*/
const int trigPin = 12;
const int echoPin = 13;
const int led1Pin = 5;
const int led2Pin = 6;
const int led3Pin = 7;

const int use_serial = 0;

const int leddistance1 = 15;
const int leddistance2 = 30;
const int leddistance3 = 60;

void setup() {
  if (use_serial) Serial.begin( 115200);
  // Set up the ultrasonic sensor pins
  pinMode( trigPin, OUTPUT);
  pinMode( echoPin, INPUT);
  // Set up the LED pin
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

int measure() {
  // Trigger the ultrasonic range finder, and
  // return distance in cm.
  int duration, distance;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  

  duration = pulseIn( echoPin, HIGH);
  distance = (duration / 2)/ 29.1;
  return distance;
}

void set_led( int pin, int distance, int trigdistance) {
  if (distance < trigdistance) digitalWrite( pin, HIGH);
  else                         digitalWrite( pin, LOW);
}


void printdistance( int distance) {
  Serial.print( distance);
  Serial.println(" cm");
}


void loop() {

  int distance = measure();

  if (use_serial) printdistance( distance);

  set_led( led1Pin, distance, leddistance1);
  set_led( led2Pin, distance, leddistance2);
  set_led( led3Pin, distance, leddistance3);

  delay(100); 
}
