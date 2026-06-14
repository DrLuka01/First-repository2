#include <SoftwareSerial.h>

// Initialize SoftwareSerial for GPS module communication
SoftwareSerial gpsSerial(14, 12); // RX (GPIO14), TX (GPIO12) of ESP8266

void setup() {
  // Start the Serial for debugging (communication with PC)
  Serial.begin(115200);
  
  // Start SoftwareSerial communication with the GPS module
  gpsSerial.begin(9600);
  
  Serial.println("Checking GPS Communication...");
}

void loop() {
  // Check if there's data coming from the GPS module
  if (gpsSerial.available()) {
    // Read and display every byte from the GPS module
    char c = gpsSerial.read();
    Serial.write(c); // Output the raw GPS data to the serial monitor
  }

  // Add a small delay to avoid flooding the Serial Monitor
  delay(100);
}
