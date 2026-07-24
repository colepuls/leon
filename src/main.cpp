#include <Arduino.h>
#include "controller.h"

Leg frontLeftLeg;

static const float leftJointOffsetPos = 100.0;
static const float rightJointOffsetPos = 90.0;

static const float motorSpacing = 60.0;
static const float upperLink = 60.0;
static const float lowerLink = 120.0;

static const int leftJointDirection = 1;
static const int rightJointDirection = 1;

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