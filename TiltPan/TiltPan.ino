
#include <Servo.h>

const int tiltservoPin = 10;
const int panservoPin = 9;

Servo tiltservo, panservo;

// Set up initial values and range of motion
float tiltangle = 90;
float tiltmin = 80;
float tiltmax = 125;

float panangle = 90;
float panmin = 60;
float panmax = 120;

// Set up parameters for moving servos.
int pandir = 0;
int tiltdir = 1;
float tiltrate = 0.5;
float panrate = 0.5;


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
  //printangles();

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
  delay (20);
}

