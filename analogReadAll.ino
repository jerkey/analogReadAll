#define INTERVAL        1000 // how many milliseconds between print events
#define BOTANALOG	7 // lowest ADC to watch
#define TOPANALOG	7 // highest ADC to watch

unsigned long adders[16]; // store added up values
int maxVal[16], minVal[16]; // store max and min values each time
float addcount;
unsigned long lastPrintTime;

void setup() {
  Serial.begin(57600);
  Serial.println("# booted up, analogReadAll.ino printing A"+String(BOTANALOG)+"-A"+String(TOPANALOG));
  for (int i=BOTANALOG; i<TOPANALOG+1; i++) {
    Serial.print("minVal["+String(i)+"]");
    Serial.print("\t"); // tab
    Serial.print("average["+String(i)+"]");
    Serial.print("\t"); // tab
    Serial.print("maxVal["+String(i)+"]");
    Serial.print("\t"); // tab
  }
  lastPrintTime = millis();
}

void loop() {
  for (int i=BOTANALOG; i<TOPANALOG+1; i++) {
    maxVal[i] = 0;
    minVal[i] = 2000;
    adders[i] = 0;
  }
  addcount = 0;
  while (millis() - lastPrintTime < INTERVAL) {
    for (int i=BOTANALOG; i<TOPANALOG+1; i++) {
      int thisRead = analogRead(A0 + i);
      adders[i] += thisRead;
      if (minVal[i] > thisRead) minVal[i] = thisRead;
      if (maxVal[i] < thisRead) maxVal[i] = thisRead;
    }
    addcount += 1;
  }
  lastPrintTime = millis();
  for (int i=BOTANALOG; i<TOPANALOG+1; i++) {
    Serial.print(minVal[i]);
    Serial.print("\t"); // tab
    Serial.print((float)adders[i]/addcount,1);
    Serial.print("\t"); // tab
    Serial.print(maxVal[i]);
    Serial.print("\t"); // tab
  }
  Serial.print("# time: "+String(millis() / 1000));
  Serial.print("\n\r"); // newline and then return
}
