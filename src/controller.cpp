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
    BP32.update();

    if (controller && controller->isConnected()) {

        if (controller->a()) {
            Serial.println("A pressed.");
            setAngle(channels[0], 180);
            delay(500);
        }

        if (controller->b()) {
            Serial.println("B pressed.");
            setAngle(channels[0], 90);
            delay(500);
        }

        if (controller->x()) {
            Serial.println("X pressed.");
            setAngle(channels[1], 0);
            delay(500);
        }

        if (controller->y()) {
            Serial.println("Y pressed.");
            setAngle(channels[1], 90);
            delay(500);
        }

        if (controller->r2()) {
            Serial.println("R2 pressed.");
            setAngle(channels[0], 180);
            setAngle(channels[1], 0);
            delay(500);
        }

        if (controller->l2()) {
            Serial.println("L2 pressed.");
            setAngle(channels[0], 90);
            setAngle(channels[1], 90);
            delay(500);
        }
    }

    delay(20);
}


