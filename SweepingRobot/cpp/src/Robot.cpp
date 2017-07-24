#include "Robot.h"
#include "command/Command.h"

/////////////////////////////////////////////////////////////
const Direction Robot::getDirection() const
{
    return direction;
}

/////////////////////////////////////////////////////////////
const Position Robot::getPosition() const
{
    return position;
}

/////////////////////////////////////////////////////////////
void Robot::execute(const Command* command)
{
    (*command)(direction, position);
    delete command;
}
