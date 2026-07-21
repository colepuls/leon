#include <Arduino.h>
#include "controller.h"

Leg frontLeftLeg;

static const float leftCrouchPos = 100.0;
static const float rightCrouchPos = 90.0;

static const float leftExtendPos = 160.0;
static const float rightExtendPos = 30.0;

static const float hipVerticalPos = 45.0;
static const float hipHorizontalPos = 80.0;

static const u8 leftChannel = 0;
static const u8 rightChannel = 1;
static const u8 hipChannel = 2;

void setup() {
    Serial.begin(115200);
    setupController();
    setupPca();
    frontLeftLeg = mapLeg(frontLeftLeg, leftCrouchPos, rightCrouchPos, leftExtendPos, rightExtendPos, leftChannel, rightChannel, hipVerticalPos, hipHorizontalPos, hipChannel);
    delay(1000);
}

void loop() {
    updateController(frontLeftLeg);
}