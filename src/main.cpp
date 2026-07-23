#include <Arduino.h>
#include "controller.h"

Leg frontLeftLeg;

static const float leftJointOffsetPos = 100.0;
static const float rightJointOffsetPos = 90.0;

static const float motorSpacing = 55.0;
static const float upperLink = 55.0;
static const float lowerLink = 110.0;

static const u8 leftJointDirection = 1;
static const u8 rightJointDirection = -1;

static const u8 leftJointChannel = 0;
static const u8 rightJointChannel = 1;

void setup() {
    Serial.begin(115200);
    setupController();
    setupPca();
    frontLeftLeg = initializeLeg(frontLeftLeg, leftJointOffsetPos, rightJointOffsetPos, leftJointDirection, rightJointDirection, leftJointChannel, rightJointChannel, motorSpacing, upperLink, lowerLink);
    delay(1000);
}

void loop() {
    updateController(frontLeftLeg);
}