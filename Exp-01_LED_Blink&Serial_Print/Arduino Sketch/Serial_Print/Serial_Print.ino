/*
  Hello World and Name
*/

void setup() {
  Serial.begin(9600);

  while (!Serial);

  Serial.println("Hello World!");
  Serial.println("Name:Nishant");
}

void loop() {
  // Nothing to repeat
}
