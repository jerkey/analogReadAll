#define INTERVAL        1000 // how many milliseconds between print events

unsigned long adders[16]; // store added up values
float addcount;
unsigned long lastPrintTime;

void setup() {
  Serial.begin(57600);
  Serial.println("booted up, analogReadAll.ino printing A1-A15");
  lastPrintTime = millis();
}

void loop() {
  for (int i=0; i<16; i++) adders[i] = 0;
  addcount = 0;
  while (millis() - lastPrintTime < INTERVAL) {
    for (int i=0; i<16; i++) adders[i] += analogRead(A0 + i);
    addcount += 1;
  }
  lastPrintTime = millis();
  for (int i=0; i<16; i++) {
    Serial.print((float)adders[i]/addcount,1);
    Serial.print("\t"); // tab
  }
  Serial.print(millis() / 1000);
  Serial.print("\n"); // newline
}
