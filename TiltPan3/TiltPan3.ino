
#include <Servo.h>
#include <math.h>

Servo tiltservo, panservo;

// Set up initial values and range of motion.  Use microseconds
float tiltpulse = 1700;
float tiltmin = 1300;
float tiltmax = 1800;

float panpulse = 1500;
float panmin = 1000;
float panmax = 2000;

// Set up parameters for moving servos.
int pandir = 0;
int tiltdir = 1;
float tiltrate = 10;
float panrate = 2.5;

int tiltsteps = (int)((tiltmax - tiltmin) / tiltrate);
int tiltstep = 0;
int pansteps = (int)((panmax - panmin) / panrate);
int panstep = 0;

void setup() {
  // Attach output pins to servos.
  tiltservo.attach(10);
  panservo.attach(9);
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

float rate( int nsteps, int n) {
  float f = (float)nsteps / 3.14159;
  return sin( (float)n / f);  
}

void loop() {
  // put your main code here, to run repeatedly:
  //printangles();
  tiltstep += 1;
  panstep += 1;

  // To write microsecond values, use servo.write( us)
  // To write degree values, use servo.write( degr)
  tiltservo.write( (int)tiltpulse);
  panservo.write( (int)panpulse);

  // Update servo angles based on their current
  // direction and rate
  tiltpulse += (tiltdir * rate( tiltsteps, tiltstep) * tiltrate);
  panpulse += (pandir * rate( pansteps, panstep) * panrate);

  // Change direction at min or max values
  if (tiltpulse >= tiltmax) { tiltdir = -1; tiltstep = 0; }
  if (tiltpulse <= tiltmin) { tiltdir = 1; tiltstep = 0; }
  
  if (panpulse >= panmax) { pandir = -1; panstep = 0; }
  if (panpulse <= panmin) { pandir = 1;  panstep = 0; }

  // Update servo values at 50 Hz
  delay (20);
}

