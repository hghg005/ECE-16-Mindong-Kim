const int accelX = A3;
const int accelY = A4;
const int accelZ = A5;

void setupAccelSensor()
{
  pinMode(accelX, INPUT);
  pinMode(accelY, INPUT);
  pinMode(accelY, INPUT);  
}

void readAccelSensor()
{
  ax = analogRead(accelX);
  ay = analogRead(accelY);
  az = analogRead(accelZ);
}
