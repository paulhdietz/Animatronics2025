// Audio LED Sync test

const int inPin = 7;  // the input pin
char cnt = 0;

void setup() {
  pinMode(A0, OUTPUT); pinMode(A1, OUTPUT); pinMode(A2, OUTPUT);
  pinMode(inPin, INPUT);
  delay(3000);  // Delay to avoid hearing USB connecting sound during reset
}

void loop() {
  while (digitalRead(inPin) == 0);  // wait for high
  switch (cnt) {
    case 0: digitalWrite(A0, HIGH); cnt++; break;
    case 1: digitalWrite(A1, HIGH); cnt++; break;
    case 2: digitalWrite(A2, HIGH); cnt++; break;
    case 3: digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); cnt=0; break;
  }
  while (digitalRead(inPin) == 1);  // wait for low
}