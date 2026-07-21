#include "servo.h"

typedef struct Joint {
    float crouchPos;
    float extendPos;
    float verticalPos;
    float horizontalPos;
    u8 channel;
} Joint;

typedef struct Leg {
    Joint leftJoint;
    Joint rightJoint;
    Joint hipJoint;
} Leg;

Leg mapLeg(Leg leg, float leftJointCrouchPos, float rightJointCrouchPos, float leftJointExtendPos, float rightJointExtendPos, u8 leftJointChannel, u8 rightJointChannel, float hipJointVerticalPos, float hipJointHorizontalPos, u8 hipJointChannel);

void crouchLeg(Leg leg);
void extendLeg(Leg leg);
void tuckLeg(Leg leg);
void untuckLeg(Leg leg);
void walkCrouched(Leg leg);
void walkExtended(Leg leg);