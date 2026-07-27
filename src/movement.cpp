#include "movement.h"

Leg initializeLeg(Leg leg, float leftJointOffsetPos, float rightJointOffsetPos, float hipJointOffsetPos, int leftJointDirection, int rightJointDirection, int hipJointDirection, u8 leftJointChannel, u8 rightJointChannel, u8 hipJointChannel, float motorSpacing, float upperLink, float lowerLink) {
    // offsetPos
    leg.leftJoint.offsetPos = leftJointOffsetPos;
    leg.rightJoint.offsetPos = rightJointOffsetPos;
    leg.hipJoint.offsetPos = hipJointOffsetPos;

    // direction
    leg.leftJoint.direction = leftJointDirection;
    leg.rightJoint.direction = rightJointDirection;
    leg.hipJoint.direction = hipJointDirection;

    // channel
    leg.leftJoint.channel = leftJointChannel;
    leg.rightJoint.channel = rightJointChannel;
    leg.hipJoint.channel = hipJointChannel;

    // coordinate values
    leg.motorSpacing = motorSpacing;
    leg.upperLink = upperLink;
    leg.lowerLink = lowerLink;

    return leg;
}

float* getAngles(Leg leg, float x, float y) {
    x = -x; // flip axis

    // define limits
    float leftLimit = sqrtf(((x + (leg.motorSpacing / 2)) * (x + (leg.motorSpacing / 2))) + (y * y));
    float rightLimit = sqrtf(((x - (leg.motorSpacing / 2)) * (x - (leg.motorSpacing / 2))) + (y * y));

    if ((fabsf(leg.lowerLink - leg.upperLink) <= leftLimit && leftLimit <= leg.upperLink + leg.lowerLink) && (fabsf(leg.lowerLink - leg.upperLink) <= rightLimit && rightLimit <= leg.upperLink + leg.lowerLink)) {
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
        float rightAngleDegrees = (rightAngleRadians * 180.0 / PI) - 180.0;

        // raw degrees -> servo acceptable degrees
        float leftServoAngle = leg.leftJoint.offsetPos + leg.leftJoint.direction * leftAngleDegrees;
        float rightServoAngle = leg.rightJoint.offsetPos + leg.rightJoint.direction * rightAngleDegrees;

        // store angles for return
        float* angles = (float*)malloc(sizeof(float) * 2);
        angles[0] = leftServoAngle;
        angles[1] = rightServoAngle;

        return angles;
    }
    else {
        Serial.println("ERROR: Cannot reach position.");
        return (float*)NULL;
    }
}

void moveLegToPos(Leg leg, float x, float y) {
    float* angles = getAngles(leg, x, y);

    if (angles == NULL) {
        delay(200);
        return;
    }

    setAngle(leg.leftJoint.channel, angles[0]);
    setAngle(leg.rightJoint.channel, angles[1]);
    delay(10);

    free(angles);
}

void resetLeg(Leg leg) {
    setAngle(leg.leftJoint.channel, leg.leftJoint.offsetPos);
    setAngle(leg.rightJoint.channel, leg.rightJoint.offsetPos);
    delay(200);
}

// write traingle and cycloid gait...
// trot gait (fl, br), (fr, bl)

void moveLegLine(Leg leg, float startX, float endX, float startY, float endY) {
    float x, y;

    for (int i = 1; i <= 10; i++) {
        x = startX + (i / 10.0f) * (endX - startX);
        y = startY + (i / 10.0f) * (endY - startY);
        moveLegToPos(leg, x, y);
    }
}

void triangleGait(Leg leg, float stepLength, float stepHeight, float extendedYPos) {
    // front ground position
    float aPosX = -stepLength / 2;
    float aPosY = extendedYPos;

    // peak position
    float bPosX = 0;
    float bPosY = stepHeight;

    // rear ground position
    float cPosX = stepLength / 2;
    float cPosY = extendedYPos;

    // c -> b -> a -> c

    // c -> b
    // start in c pos
    moveLegToPos(leg, cPosX, cPosY);
    moveLegLine(leg, cPosX, bPosX, cPosY, bPosY);

    // b -> a
    moveLegLine(leg, bPosX, aPosX, bPosY, aPosY);

    // a -> c
    moveLegLine(leg, aPosX, cPosX, aPosY, cPosY);
}

void cycloidGate(Leg leg, float stepLength, float stepHeight, float groundY) {
    float x, y;
    float u;
    float theta;

    float rearX = -stepLength / 2.0f;

    for (int i = 1; i <= 10; i++) {
        // get angle
        u = i / 10.0f;
        theta = 2.0f * PI * u;

        // get foot position
        x = -(rearX + (stepLength / (2.0f * PI)) * (theta - sinf(theta)));
        y = groundY - (stepHeight / 2.0f) * (1.0f - cosf(theta));

        // move foot to position
        moveLegToPos(leg, x, y);
        delay(20);
    }
}

void moveHip(Leg leg, int direction) {
    float currentAngle = getCurrentAngle(leg.hipJoint.channel);
    float angle;
    int step = 5;

    if (direction == 1) {
        angle = currentAngle + step;
        setAngle(leg.hipJoint.channel, angle);
        delay(100);
    }

    if (direction == -1) {
        angle = currentAngle - step;
        setAngle(leg.hipJoint.channel, angle);
        delay(100);
    }
}

