
#include <Servo.h>
#include <math.h>

const int tiltservoPin = 10;
const int panservoPin = 9;

Servo tiltservo, panservo;

// Set up initial values and range of motion.  Use microseconds
float tiltpulse = 1750;
float tiltmin = 1300;
float tiltmax = 1800;

float panpulse = 1500;
float panmin = 1000;
float panmax = 2000;

// Set up parameters for moving servos.
int pandir = 1;
int tiltdir = 0;
float tiltrate = 5;
float panrate = 5;
float tiltaccel = 5.0;
float panaccel = 4.0;


void setup() {
  // Attach output pins to servos.
  tiltservo.attach( tiltservoPin);
  panservo.attach( panservoPin);
  // May want to debug our pan, tilt settings.
  Serial.begin( 115200);
}

void printangles() {
  Serial.print( "Tilt:");
  Serial.print( tiltpulse);
  Serial.print( "  Pan:");
  Serial.print( panpulse);
  Serial.println();
}


float rate( float pct, float accel) {
  if (pct >= 0.5) {
    pct = 1.0 - pct;
  } 
  if (pct < 0.02) pct = 0.02;
  return pct * accel;
}


void loop() {
  // put your main code here, to run repeatedly:
  //printangles();

  // To write microsecond values, use servo.write( us)
  // To write degree values, use servo.write( degr)
  tiltservo.write( (int)tiltpulse);
  panservo.write( (int)panpulse);

  // Update servo angles based on their current
  // direction and rate
  tiltpulse +=  tiltdir * tiltrate *
                rate((tiltpulse-tiltmin)/(tiltmax-tiltmin), tiltaccel);
  panpulse +=   pandir * panrate * 
                rate((panpulse-panmin)/(panmax-panmin), panaccel);

  // Change direction at min or max values
  if (tiltpulse >= tiltmax) tiltdir = -1;
  if (tiltpulse <= tiltmin) tiltdir = 1;
  
  if (panpulse >= panmax)  pandir = -1;
  if (panpulse <= panmin)  pandir = 1;

  // Update servo values at 50 Hz
  delay (20);
}

