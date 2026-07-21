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

        if (controller->r2()) {
            extendLeg(fL_leg);
        }

        if (controller->l2()) {
            crouchLeg(fL_leg);
        }

        if (controller->r1()) {
            untuckLeg(fL_leg);
        }

        if (controller->l1()) {
            tuckLeg(fL_leg);
        }

        if (controller->a()) {
            walkCrouched(fL_leg);
        }

        if (controller->b()) {
            walkExtended(fL_leg);
        }
    }

    delay(20);
}


