
#include <Servo.h>

Servo tilt, pan;

int pandir = 1;
int tiltdir = 1;
int tiltus = 1500;
int panus = 1500;
int tiltrate = 12;
int panrate = 2;

void setup() {
  // put your setup code here, to run once:
  tilt.attach(10);
  pan.attach(9);
  Serial.begin( 115200);
}

void printangles() {
  Serial.print( "Tilt:");
  Serial.print( tiltus);
  Serial.print( "  Pan:");
  Serial.print( panus);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  //printangles();
  tilt.write( tiltus);
  pan.write( panus);

  tiltus += (tiltdir * tiltrate);
  if (tiltus >= 2050) tiltdir = -1;
  if (tiltus <= 1500) tiltdir = 1;
  
  panus += (pandir * panrate);
  if (panus >= 2200) pandir = -1;
  if (panus <= 800) pandir = 1;

  delay (20);
}

