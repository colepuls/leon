#include "movement.h"

Leg initializeLeg(Leg leg, float leftJointOffsetPos, float rightJointOffsetPos, u8 leftJointDirection, u8 rightJointDirection, u8 leftJointChannel, u8 rightJointChannel, float motorSpacing, float upperLink, float lowerLink) {
    // offsetPos
    leg.leftJoint.offsetPos = leftJointOffsetPos;
    leg.rightJoint.offsetPos = rightJointOffsetPos;

    // direction
    leg.leftJoint.direction = leftJointDirection;
    leg.rightJoint.direction = rightJointDirection;

    // channel
    leg.leftJoint.channel = leftJointChannel;
    leg.rightJoint.channel = rightJointChannel;

    // coordinate values
    leg.motorSpacing = motorSpacing;
    leg.upperLink = upperLink;
    leg.lowerLink = lowerLink;

    return leg;
}

float getAngle(Leg leg, float x, float y) {
    float leftJointX = -leg.motorSpacing / 2;
    float rightJointX = leg.motorSpacing / 2;
    float leftJointY = 0;
    float rightJointY = 0;

    float leftX = x - leftJointX;
    float rightX = x - rightJointX;
    float leftY = y - leftJointY;
    float rightY = y - rightJointY;

    float leftDistance = sqrtf((leftX * leftX) + (leftY * leftY));
    float rightDistance = sqrtf((rightX * rightX) + (rightY * rightY));

    float leftOutsideAngle = atan2f(leftY, leftX);
    float rightOutsideAngle = atan2f(rightY, rightX);

    float leftInsideAngle = acosf(((leg.upperLink * leg.upperLink) + (leftDistance * leftDistance) - (leg.lowerLink * leg.lowerLink)) / (2 * leg.upperLink * leftDistance));
    float rightInsideAngle = acosf(((leg.upperLink * leg.upperLink) + (rightDistance * rightDistance) - (leg.lowerLink * leg.lowerLink)) / (2 * leg.upperLink * rightDistance));

    float leftAngleRadians = leftOutsideAngle - leftInsideAngle;
    float rightAngleRadians = rightOutsideAngle + rightInsideAngle;

    // radians -> degrees
    float leftAngleDegrees = leftAngleRadians * 180.0 / PI;
    float rightAngleDegrees = rightAngleRadians * 180.0 / PI;

    // raw degrees -> servo acceptable degrees
    float leftServoAngle = leg.leftJoint.offsetPos + leg.leftJoint.direction * leftAngleDegrees;
    float rightServoAngle = leg.rightJoint.offsetPos + leg.rightJoint.direction * rightAngleDegrees;

    return leftServoAngle, rightServoAngle;
}

void moveLegToPos(Leg leg, float x, float y) {
    float leftServoAngle, rightServoAngle = getAngle(leg, x, y);
    setAngle(leg.leftJoint.channel, leftServoAngle);
    setAngle(leg.rightJoint.channel, rightServoAngle);
    delay(200);
}