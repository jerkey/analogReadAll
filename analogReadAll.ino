#define INTERVAL        1000 // how many milliseconds between print events
#define BOTANALOG	7 // lowest ADC to watch
#define TOPANALOG	7 // highest ADC to watch

unsigned long adders[16]; // store added up values
float addcount;
unsigned long lastPrintTime;

void setup() {
  Serial.begin(57600);
  Serial.println("# booted up, analogReadAll.ino printing A"+String(BOTANALOG)+"-A"+String(TOPANALOG));
  lastPrintTime = millis();
}

void loop() {
  for (int i=BOTANALOG; i<TOPANALOG+1; i++) adders[i] = 0;
  addcount = 0;
  while (millis() - lastPrintTime < INTERVAL) {
    for (int i=BOTANALOG; i<TOPANALOG+1; i++) adders[i] += analogRead(A0 + i);
    addcount += 1;
  }
  lastPrintTime = millis();
  for (int i=BOTANALOG; i<TOPANALOG+1; i++) {
    Serial.print((float)adders[i]/addcount,1);
    Serial.print("\t"); // tab
  }
  Serial.print("# time: "+String(millis() / 1000));
  Serial.print("\n\r"); // newline and then return
}
