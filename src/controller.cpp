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
            triangleGait(fL_leg, 60.0f, 80.0f, 140.0f);
        }

        if (controller->b()) {
            triangleGait(fL_leg, 80.0f, 80.0f, 160.0f);
        }

        if (controller->y()) {
            cycloidGate(fL_leg, 60.0f, 80.0f, 140.0f);
        }

        if (controller->x()) {
           cycloidGate(fL_leg, 80.0f, 80.0f, 160.0f);
        }

        if (controller->r2()) {
            moveHip(fL_leg, 1);
        }

        if (controller->l2()) {
            moveHip(fL_leg, -1);
        }
    }

    delay(10);
}


