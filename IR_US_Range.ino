

// Pin number constants
const int triggerPin = 5;
const int echoPin = 6;



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}


// the loop routine runs over and over again forever:
void loop() {
  long sensorValue = 0;
  int max = 100;
  long duration, cm;

//  digitalWrite(triggerPin, LOW);
//  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  Serial.print("US Sensor Reading = ");
  Serial.print(cm);
  Serial.print("cm\t");
  
  for (int i = 0; i < max; i++) {
    // read the input on analog pin 0:
    sensorValue += analogRead(A0);
    delay(1);        // delay in between reads for stability
  }
  
  sensorValue = sensorValue/max;
  float volts = (sensorValue)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  float distance = 65*pow(volts, -1.1);  

  // print out the value you read:
  Serial.print("IR Sensor Reading = ");
  Serial.print(distance);
  Serial.println("cm");
  sensorValue = 0;
}
