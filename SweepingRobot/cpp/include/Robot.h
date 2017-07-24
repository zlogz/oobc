#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "coordinate/Position.h"
#include "coordinate/Direction.h"

struct Command;

struct Robot
{
    void execute(const Command*);

    const Direction getDirection() const;
    const Position  getPosition() const;

private:
    Direction direction{__north};
    Position  position{0, 0};
};

#endif
