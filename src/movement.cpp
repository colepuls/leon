#include "movement.h"

Leg mapLeg(Leg leg, float leftJointCrouchPos, float rightJointCrouchPos, float leftJointExtendPos, float rightJointExtendPos, u8 leftJointChannel, u8 rightJointChannel, float hipJointVerticalPos, float hipJointHorizontalPos, u8 hipJointChannel) {
    // crouch pos
    leg.leftJoint.crouchPos = leftJointCrouchPos;
    leg.rightJoint.crouchPos = rightJointCrouchPos;

    // extend pos
    leg.leftJoint.extendPos = leftJointExtendPos;
    leg.rightJoint.extendPos = rightJointExtendPos;

    // hip pos
    leg.hipJoint.verticalPos = hipJointVerticalPos;
    leg.hipJoint.horizontalPos = hipJointHorizontalPos;

    // set channels
    leg.leftJoint.channel = leftJointChannel;
    leg.rightJoint.channel = rightJointChannel;
    leg.hipJoint.channel = hipJointChannel;

    return leg;
}

void crouchLeg(Leg leg) {
    setAngle(leg.leftJoint.channel, leg.leftJoint.crouchPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.crouchPos);
    delay(100);
}

void extendLeg(Leg leg) {
    setAngle(leg.leftJoint.channel, leg.leftJoint.extendPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.extendPos);
    delay(100);
}

void tuckLeg(Leg leg) {
    setAngle(leg.hipJoint.channel, leg.hipJoint.horizontalPos);
    delay(100);
}

void untuckLeg(Leg leg) {
    setAngle(leg.hipJoint.channel, leg.hipJoint.verticalPos);
    delay(100);
}

void walkCrouched(Leg leg) {
    // pos 1
    setAngle(leg.leftJoint.channel, leg.leftJoint.crouchPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.extendPos);
    delay(200);

    // pos 2
    setAngle(leg.leftJoint.channel, leg.leftJoint.extendPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.crouchPos);
    delay(200);

    // pos 3
    setAngle(leg.leftJoint.channel, leg.leftJoint.crouchPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.crouchPos);
    delay(200);
}

void walkExtended(Leg leg) {
    // pos 1
    setAngle(leg.leftJoint.channel, leg.leftJoint.extendPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.crouchPos);
    delay(200);

    // pos 2
    setAngle(leg.leftJoint.channel, leg.leftJoint.crouchPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.extendPos);
    delay(200);

    // pos 3
    setAngle(leg.leftJoint.channel, leg.leftJoint.extendPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.extendPos);
    delay(200);
}