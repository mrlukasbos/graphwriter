#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


/////////////////////////////
// Analog signal graph writer
// write six analog signal values at 20Hz to softserial port at 9600Bps
// every value preceeded by A, B, C, X, Y or Z

String opticalmessage, sonarmessage; 
int pins[] = {
  A0, A1, A2, A3, A4, A5
}; // fill in the number of pins to send
char headers[] = {
  'A', 'B', 'C', 'D', 'E', 'F'
}; //the headers
unsigned long time; //this is going to be huge

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); //open a serial connection

}
void loop() {

  //let's do this code every 50 milliseconds (20Hz)
  if (millis() > time + 49) { // more acurate than delay(50);
    time = millis(); // reset the clock to zero.

//    opticalmessage = headers[0] +String((2500000 / analogRead(pins[0]) - 4500)/10);
    //Serial.println(opticalmessage);
   // sonarmessage = headers[1] + String(sonar.ping_cm());
  //  Serial.println(sonarmessage);

    for (int i = 0; i<2; i++) {
      Serial.println(headers[i] + String(analogRead(pins[i])));
    }
  }
}


