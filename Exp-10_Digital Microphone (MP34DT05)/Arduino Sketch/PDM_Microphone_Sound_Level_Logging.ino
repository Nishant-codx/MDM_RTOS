#include <PDM.h>

short sampleBuffer[256];
volatile int samplesRead = 0;

void onPDMdata() {
  int bytesAvailable = PDM.available();
  PDM.read(sampleBuffer, bytesAvailable);
  samplesRead = bytesAvailable / 2;
}

void setup() {
  Serial.begin(9600);

  PDM.onReceive(onPDMdata);

  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1);
  }

  Serial.println("Microphone Ready");
}

void loop() {

  if (samplesRead) {

    long sum = 0;

    for (int i = 0; i < samplesRead; i++) {
      sum += abs(sampleBuffer[i]);
    }

    int soundLevel = sum / samplesRead;

    Serial.print("Sound Level: ");
    Serial.println(soundLevel);

    samplesRead = 0;
  }
}