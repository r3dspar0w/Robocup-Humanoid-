#pragma once

#include "types.h"

#define VALIDATION_COMMUNICATION 31202
#define VALIDATION_DISCOVERY 41203
struct TeamCommunicationMsg
{
    int validation = VALIDATION_COMMUNICATION; // validate msg, to determine if it's sent by us.
    int communicationId;
    int teamId;
    int playerId;
    bool ballDetected;
    double ballDistance; // Distance from the sender robot to the ball
    Point ballPosToField; // Ball position in global / field coordinates
};

struct TeamDiscoveryMsg
{
    int validation = VALIDATION_DISCOVERY; // validate msg, to determine if it's sent by us.
    int communicationId;
    int teamId;
    int playerId;
};
