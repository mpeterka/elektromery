#define DIGITAL_SENSOR_PIN 3
#define LEDPIN    13  // The onboard LED

// posledni stav (svetlo / tma)
int  lastState; 
// pocet bliknuti. Az pretece, pretece...
unsigned long pocet = 0L;


void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);          // Enable the Serial data output
  Serial.println("Odecet elektromeru");
}


// This module is ACTIVE LOW when a reflection is seen
void loop() {

  int currentState = digitalRead(DIGITAL_SENSOR_PIN);
  if (currentState != lastState && currentState == LOW) {
    // zmena stavu
    pocet++;
    Serial.print("Blink ");
    Serial.println(pocet);
  }

  digitalWrite(LEDPIN, currentState == LOW ? HIGH : LOW);


  lastState = currentState;
  
  delay(100);

}
