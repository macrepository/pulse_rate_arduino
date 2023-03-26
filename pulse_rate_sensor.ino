#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> // Includes the PulseSensorPlayground Library.
 
// Variables
const int PulseWire = 0; // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.
 
PulseSensorPlayground pulseSensor; // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

void setup() {
  Serial.begin(9600); // For Serial Monitor
   
  // Configure the PulseSensor object, by assigning our variables to it.
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);
   
  if (pulseSensor.begin()) {
    Serial.println("1");
  }
}
 
void loop() {
 
  int myBPM = pulseSensor.getBeatsPerMinute();

  if (pulseSensor.sawStartOfBeat()) {
    Serial.println(myBPM);
  }
  
  delay(20); // considered best practice in a simple sketch.
}
