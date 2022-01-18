const int accelX = A3;
const int accelY = A4;
const int accelZ = A5;
const int elapsed_time=50;

int ax=0;
int ay=0;
int current_z=0;
int pre_z=0;
int state=0;

int current_state=-1;
int pre_state=3;

unsigned long past = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupAccelSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  readAccelSensor();
  pre_z=current_z;
  delay(elapsed_time);
  current_z = analogRead(accelZ);
  // Send to Serial Plotter. Notice the last print has a newline.
  
  current_state=detectGesture(ax,ay,current_z,pre_z);

  if(pre_state!=current_state)
  {  
     if(current_state==0)
     {
       Serial.println("Up");  
     }
    else if(current_state==1)
    {
      Serial.println("Down"); 
    }
    else
    {
      Serial.println("Shake"); 
    }
  }

  pre_state=current_state;

}



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
  current_z = analogRead(accelZ);
}


int detectGesture(int ax, int ay, int current_z, int pre_z)
{
  if(abs((current_z-pre_z)/elapsed_time)<=1 && current_z >=2000)//case for up
  {
    state=0;  
  }
  else if(abs((current_z-pre_z)/elapsed_time)<=1 && current_z <1800)//case for down
  {
    state=1;
  }
  else if(abs((current_z-pre_z)/elapsed_time)>30)//case for shaking
  {
    state=2;
  }
  
  return state;
}
