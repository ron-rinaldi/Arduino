/*
  Intruder
  From Arduino Project Book by Mark Geddes
*/

#define trigPin 12
#define echoPin 13
#define MAX_DISTANCE 500



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin( 115200);
  pinMode( trigPin, OUTPUT);
  pinMode( echoPin, INPUT);
  
  
}

// the loop function runs over and over again forever
void loop() {
  int duration, distance, i;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  

  duration = pulseIn( echoPin, HIGH);
  distance = (duration / 2)/ 29.1;
  Serial.print( distance);
  Serial.println(" cm");
  
  delay(100);                       // wait for a second
}
