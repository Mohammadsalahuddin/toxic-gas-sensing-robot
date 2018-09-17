
//please add the thinger.io lib for arduino, using arduino library manager.
//please add the thinger.io lib for arduino, using arduino library manager.
// or check the thinger.io documentation

#include <YunClient.h>
#include <ThingerYun.h>

#define USERNAME "__________YOUR_____USER____NAME____"
#define DEVICE_ID "__________YOUR DEVICE_____ID_____"
#define DEVICE_CREDENTIAL "_____YOUR___CREDENTIAL_____"

ThingerYun thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;

// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

int val =0;


// for controlling the robot movements
void control_robot(int x)
{
	if (x == 0)
		stop();
	else if (x == 1)
		up();
	else if (x == 2)
		down();
	else if (x == 3)
		left();
	else if (x == 4)
		right();
	else 
		stop();	
	
}


void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  
    // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // initialize bridge
  Bridge.begin();


  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["LPG"] >> outputValue(analogRead(A0)); // optional 
  thing["CO2"] >> outputValue(analogRead(A1));
  thing["CO"] >> outputValue(analogRead(A2));
  thing["AIRQ"] >> outputValue(analogRead(A3));
  thing ["control"] << control_robot(val);

  // more details at http://docs.thinger.io/arduino/
}

void up()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  delay(2000);
}


void down()
{
    // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void left()
{
    // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void right()
{
    // now change motor directions
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}



void loop() {
  thing.handle();
}