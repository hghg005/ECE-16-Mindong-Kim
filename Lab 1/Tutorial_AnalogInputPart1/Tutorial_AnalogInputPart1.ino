const int accelX = A0;

void setup() {
  // put your setup code here, to run once:

  // Begin the Serial communication (you did this in the last lab!)
  //<insert your code here>
  Serial.begin(9600);
  // Define the analog pin as input
  pinMode(accelX, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int accel_val = analogRead(accelX);
  // Print the value (you did this in the last lab too)
  //<insert your code here>
  Serial.print(accel_val);
  delay(1000);
}
