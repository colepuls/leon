#include "servo.h"

typedef struct Joint {
    float offsetPos;
    u8 direction;
    u8 channel;
} Joint;

typedef struct Leg {
    Joint leftJoint;
    Joint rightJoint;
    float motorSpacing;
    float upperLink;
    float lowerLink;
} Leg;

Leg initializeLeg(Leg leg, float leftJointOffsetPos, float rightJointOffsetPos, u8 leftJointDirection, u8 rightJointDirection, u8 leftJointChannel, u8 rightJointChannel, float motorSpacing, float upperLink, float lowerLink);
float getAngle(Leg leg, float x, float y);
void moveLegToPos(Leg leg, float x, float y);