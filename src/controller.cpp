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
    frontLeftLeg = mapLeg(frontLeftLeg, 95, 90, 160, 20, 0, 1);
                                //    lCr, rCr, lEx, rEx

    BP32.update();

    if (controller && controller->isConnected()) {

        if (controller->r2()) {
            extendLeg(frontLeftLeg);
        }

        if (controller->l2()) {
            crouchLeg(frontLeftLeg);
        }
    }

    delay(20);
}


