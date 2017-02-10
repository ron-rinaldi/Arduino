
#include <Servo.h>

// NOTE: #define  vs  "const int"

// #define tiltservoPin 10

const int tiltservoPin = 10;
const int panservoPin = 9;


Servo tiltservo, panservo;

// Set up initial values and range of motion
float tiltangle = 120;
float tiltmin = 80;
float tiltmax = 125;

float panangle = 90;
float panmin = 40;
float panmax = 160;

// Set up parameters for moving servos.
int pandir = 1;
int tiltdir = 1;
float tiltrate = 1;
float panrate = 1;


void setup() {
  // Attach output pins to servos.
  tiltservo.attach( tiltservoPin);
  panservo.attach( panservoPin);
  // May want to debug our pan, tilt settings.
  Serial.begin( 115200);
}

void printangles() {
  Serial.print( "Tilt:");
  Serial.print( tiltangle);
  Serial.print( "  Pan:");
  Serial.print( panangle);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  printangles();

  // To write microsecond values, use servo.write( us)
  // To write degree values, use servo.write( degr)
  tiltservo.write( (int)tiltangle);
  panservo.write( (int)panangle);

  // Update servo angles based on their current
  // direction and rate
  tiltangle += (tiltdir * tiltrate);
  panangle += (pandir * panrate);

  // Change direction at min or max values
  if (tiltangle >= tiltmax) tiltdir = -1;
  if (tiltangle <= tiltmin) tiltdir = 1;
  
  if (panangle >= panmax) pandir = -1;
  if (panangle <= panmin) pandir = 1;

  // Update servo values at 50 Hz
  delay(20);
}

