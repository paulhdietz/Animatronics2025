// Audio LED Sync test

const int inPin = 7;  // the input pin
int cnt = 0;

void setup() {
  pinMode(A0, OUTPUT); pinMode(A1, OUTPUT); pinMode(A2, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  while (digitalRead(inPin) == 0);  // wait for high
  switch (cnt) {
    case 0: digitalWrite(A0, HIGH); break;
    case 1: digitalWrite(A1, HIGH); break;
    case 2: digitalWrite(A2, HIGH); break;
  }
  while (digitalRead(inPin) == 1); // wait for low
  cnt++;
  if (cnt == 3) {
    cnt = 0;
    digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW);
  }
}