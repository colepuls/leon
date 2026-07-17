#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;

extern Adafruit_PWMServoDriver pca;
extern u8* channels;

extern const u8 sdaPin;
extern const u8 sclPin;

extern const u8 numServos;

extern const u16 minPWM;
extern const u16 maxPWM;
extern const u8 minAngle;
extern const u8 maxAngle;

void setupPca();
void setAngle(u8 channel, float angle);