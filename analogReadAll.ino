void setup() {
  Serial.begin(57600);
  Serial.println("booted up, analogReadAll.ino printing A1 A2 A3 A4 A5 in hex");
  pinMode(2,OUTPUT);
}

void loop() {
  Serial.print(analogRead(A1),HEX);
  Serial.print("  ");
  Serial.print(analogRead(A2),HEX);
  Serial.print("  ");
  Serial.print(analogRead(A3),HEX);
  Serial.print("  ");
  Serial.print(analogRead(A4),HEX);
  Serial.print("  ");
  Serial.print(analogRead(A5),HEX);
  Serial.println("  ");
  delay(200);
}
