// --- Pin Definitions --- 
#define CLAP_SENSOR 3 
#define RELAY_PIN 2 
// --- Variables --- 
bool ledState = false; 
int sensorValue = 0; 
unsigned long lastClapTime = 0; 
const unsigned long debounceDelay = 300; // Minimum time between claps (ms) 
void setup() { 
pinMode(CLAP_SENSOR, INPUT); 
pinMode(RELAY_PIN, OUTPUT); 
digitalWrite(RELAY_PIN, LOW); // LED/Relay initially OFF 
Serial.begin(9600); 
} 
void loop() { 
sensorValue = digitalRead(CLAP_SENSOR); 
if (sensorValue == HIGH) { // Detect clap signal 
unsigned long currentTime = millis(); 
// Debounce to avoid multiple triggers from one clap 
if (currentTime - lastClapTime > debounceDelay) { 
ledState = !ledState; // Toggle LED/Relay state 
digitalWrite(RELAY_PIN, ledState); // Apply new state 
Serial.print("Clap detected! LED is now "); 
Serial.println(ledState ? "ON" : "OFF"); 
lastClapTime = currentTime; // Update last clap time 
} 
} 
}