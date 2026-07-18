#include "movement.h"

Leg mapLeg(Leg leg, float leftJointCrouchPos, float rightJointCrouchPos, float leftJointExtendPos, float rightJointExtendPos, u8 leftJointChannel, u8 rightJointChannel) {
    // crouch pos
    leg.leftJoint.crouchPos = leftJointCrouchPos;
    leg.rightJoint.crouchPos = rightJointCrouchPos;

    // extend pos
    leg.leftJoint.extendPos = leftJointExtendPos;
    leg.rightJoint.extendPos = rightJointExtendPos;

    // set channels
    leg.leftJoint.channel = leftJointChannel;
    leg.rightJoint.channel = rightJointChannel;

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

void moveLegLeft(Leg leg) {
    // would need to add more positions to Leg object
}

// to do: clean code base