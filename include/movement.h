#include "servo.h"

typedef struct Joint {
    float offsetPos;
    int32_t direction;
    u8 channel;
} Joint;

typedef struct Leg {
    Joint leftJoint;
    Joint rightJoint;
    Joint hipJoint;
    float motorSpacing;
    float upperLink;
    float lowerLink;
} Leg;

Leg initializeLeg(Leg leg, float leftJointOffsetPos, float rightJointOffsetPos, float hipJointOffsetPos, int leftJointDirection, int rightJointDirection, int hipJointDirection, u8 leftJointChannel, u8 rightJointChannel, u8 hipJointChannel, float motorSpacing, float upperLink, float lowerLink);
float* getAngles(Leg leg, float x, float y);
void moveLegToPos(Leg leg, float x, float y);
void resetLeg(Leg leg);
void moveLegLine(Leg leg, float startX, float endX, float startY, float endY);
void triangleGait(Leg leg, float stepLength, float stepHeight, float extendedYPos);
void cycloidGate(Leg leg, float stepLength, float stepHeight, float groundY);
void moveHip(Leg leg, int direction);