#include "servo.h"

typedef struct Joint {
    float offsetPos;
    int32_t direction;
    u8 channel;
} Joint;

typedef struct Leg {
    Joint leftJoint;
    Joint rightJoint;
    float motorSpacing;
    float upperLink;
    float lowerLink;
} Leg;

Leg initializeLeg(Leg leg, float leftJointOffsetPos, float rightJointOffsetPos, int leftJointDirection, int rightJointDirection, u8 leftJointChannel, u8 rightJointChannel, float motorSpacing, float upperLink, float lowerLink);
float* getAngles(Leg leg, float x, float y);
void moveLegToPos(Leg leg, float x, float y);
void resetLeg(Leg leg);