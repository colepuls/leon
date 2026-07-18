#include "servo.h"

typedef struct Joint {
    float crouchPos;
    float extendPos;
    u8 channel;
} Joint;

typedef struct Leg {
    Joint leftJoint;
    Joint rightJoint;
    Joint hipJoint;
} Leg;

Leg mapLeg(Leg leg, float leftJointCrouchPos, float rightJointCrouchPos, float leftJointExtendPos, float rightJointExtendPos, u8 leftJointChannel, u8 rightJointChannel);

void crouchLeg(Leg leg);
void extendLeg(Leg leg);