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

void updateController(Leg fL_leg) {

    BP32.update();

    if (controller && controller->isConnected()) {

        if (controller->a()) {
            moveLegToPos(fL_leg, -30.0, 140.0);
        }

        if (controller->b()) {
            moveLegToPos(fL_leg, 30.0, 140.0);
        }

        if (controller->y()) {
            resetLeg(fL_leg);
        }
    }

    delay(20);
}


