int lm35_pin=A1;
int trigPin = 13;
int echoPin = 9;
int sensor= 7;
int warm_up;

long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  
  
  //Reading temparature value
  int temp_adc_val;
  float temp_val;
  temp_adc_val=analogRead(lm35_pin);
  temp_val=(temp_adc_val*4.48);
  temp_val=(temp_val/10);
  Serial.print("Temparature = ");
  Serial.print(temp_val);
  Serial.print("Degree Celsius\n");
  delay(2000);
  
  
  // ultrasoni sensor starting 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);
  distance = duration * 0.034 / 2;
    delayMicroseconds(2);

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);

  //PIR Sensor Values readings
  int val;
  val=digitalRead(sensor);
  if(val==LOW)
  {
    if(warm_up==1)
    {
      Serial.print("Warming Up\n\n");
      warm_up=0;
      delay(2000);
    }
    Serial.print("No object in sight\n\n");
    delay(1000);
  }
 else
  {
    Serial.println("Object Detected\n\n"); 
    warm_up=1;
    delay(1000);
  } 

}
