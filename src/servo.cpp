#include "servo.h"

typedef uint8_t u8;
typedef uint16_t u16;

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();
u8* channels;

const u8 sdaPin = 21;
const u8 sclPin = 22;

const u8 numServos = 3;

const u16 minPWM = 500;
const u16 maxPWM = 2500;
const u8 minAngle = 0;
const u8 maxAngle = 180;

void setupPca() {
    channels = (u8*)malloc(sizeof(u8) * numServos);
    for (u8 i = 0; i < numServos; i++) { channels[i] = i; }

    Wire.begin(sdaPin, sclPin);
    pca.begin();
    pca.setPWMFreq(100);
    delay(10);
}

void setAngle(u8 channel, float angle) {
    angle = constrain(angle, 0.0f, 180.0f);
    u16 pulseUs = map(angle, minAngle, maxAngle, minPWM, maxPWM);
    u16 pwmVal = pulseUs * 4096 / 10000;
    pca.setPWM(channel, 0, pwmVal);
}