#include "controller.h"
#include <Bluepad32.h>

ControllerPtr controller;

void connectController(ControllerPtr ctrl) {
    controller = ctrl;
    Serial.println("Controller connected.");
}

void disconnectController(ControllerPtr ctrl) {
    controller = nullptr;
    Serial.println("Controller disconnected.");
}

void setupController() {
    BP32.setup(&connectController, &disconnectController);
}

void updateController() {
    Leg frontLeftLeg;

    float leftCrouchPos = 95.0;
    float rightCrouchPos = 90.0;

    float leftExtendPos = 160.0;
    float rightExtendPos = 20.0;

    float hipVerticalPos = 45.0;
    float hipHorizontalPos = 80.0;

    u8 leftChannel = 0;
    u8 rightChannel = 1;
    u8 hipChannel = 2;


    frontLeftLeg = mapLeg(frontLeftLeg, leftCrouchPos, rightCrouchPos, leftExtendPos, rightExtendPos, leftChannel, rightChannel, hipVerticalPos, hipHorizontalPos, hipChannel);

    BP32.update();

    if (controller && controller->isConnected()) {

        if (controller->r2()) {
            extendLeg(frontLeftLeg);
        }

        if (controller->l2()) {
            crouchLeg(frontLeftLeg);
        }

        if (controller->r1()) {
            untuckLeg(frontLeftLeg);
        }

        if (controller->l1()) {
            tuckLeg(frontLeftLeg);
        }
    }

    delay(20);
}


