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
            moveLegToPos(fL_leg, -87.5f, 150.0f);
        }

        if (controller->b()) {
            moveLegToPos(fL_leg, 100.5f, 130.0f);
        }

        if (controller->y()) {
            resetLeg(fL_leg);
        }

        if (controller->x()) {
            moveLegToPos(fL_leg, 0.0f, 150.0f);
        }
    }

    delay(20);
}


