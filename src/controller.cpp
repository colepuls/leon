

#include "controller.h"

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
            delay(1000);
        }

        if (controller->b()) {
            Serial.println("B pressed.");
            setAngle(channels[0], 90);
            delay(1000);
        }
    }

    delay(20);
}


