const int trigPin = 2;
const int echoPin = 3;
const int RGBPin = 6;
const int buzzer = 7;
int sound = 500;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RGBPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit * 0.034) / 2;

  if (distanceincm > 50) {
    digitalWrite(RGBPin, LOW); // turn off the RGB LED
    noTone(buzzer);
  }
  else if (distanceincm <= 50 && distanceincm > 20) {
    analogWrite(RGBPin, 255); // green
    noTone(buzzer);
  }
  else if (distanceincm <= 20 && distanceincm > 10) {
    analogWrite(RGBPin, 255); // yellow
    tone(buzzer, sound);
  }
  else {
    analogWrite(RGBPin, 255); // red
    tone(buzzer, sound);
  }
  // add more conditions for different distances
  delay(100); // wait for a short time before taking the next reading
}
