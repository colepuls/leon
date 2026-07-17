#include <Arduino.h>
#include "controller.h"


void setup() {
    Serial.begin(115200);
    setupController();
    setupPca();
    delay(1000);
}

void loop() {
    updateController();
}