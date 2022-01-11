const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval_1 = 200;           // interval for LED ON(milliseconds)
const long interval_2 = 50;           // interval for LED off(milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();
  
  if(ledState == LOW)
  {
    if (currentMillis - previousMillis >= interval_2) 
    {
      previousMillis = currentMillis; // save the last time you blinked the LED
 
      ledState = HIGH;
    }
  
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  else
   {
    if (currentMillis - previousMillis >= interval_1) 
    {
      previousMillis = currentMillis; // save the last time you blinked the LED
 
      ledState = LOW;
    }
   }
}
