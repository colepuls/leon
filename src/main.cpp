#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Bluepad32.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdint.h>


typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;


/* ----- Servo Setup ----- */
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

void writeServo(u8 channel, float angle) {
    angle = constrain(angle, 0, 180);
    u16 pulseUs = map(angle, 0, 180, 500, 2500);
    u16 ticks = (pulseUs * 4096UL) / 20000UL;
    pca.setPWM(channel, 0, ticks);
}

struct Leg {
    static const u8 hip;
    static const u8 fJoint;
    static const u8 bJoint;
};

Leg flLeg = { 0, 1, 2 };
Leg frLeg = { 3, 4, 5 };
Leg blLeg = { 6, 7, 8 };
Leg brLeg = { 9, 10, 11 };
/* ----- Servo Setup ----- */



/* ----- Controller Setup ----- */
GamepadPtr gamepad;

struct ControllerState {
    bool a, b, x, y;
    float leftX;
    float leftY;
};

ControllerState ctrl;

void onConnected(GamepadPtr gp) {
    gamepad = gp;
}

void onDisconnected(GamepadPtr) {
    gamepad = nullptr;
}

bool readController(ControllerState& state) {
    if (!gamepad || !gamepad->isConnected()) {
        return false;
    }

    u8 button = gamepad->buttons();

    state.a = button & BUTTON_A;
    state.b = button & BUTTON_B;
    state.x = button & BUTTON_X;
    state.y = button & BUTTON_Y;
    state.leftX = axisToUnit(gamepad->axisX());
    state.leftY = axisToUnit(gamepad->axisY());

    return true;
}
/* ----- Controller Setup ----- */


void setup() {}
void loop() {}