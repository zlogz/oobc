#include "command/TurnLeftCommand.h"
#include "coordinate/Direction.h"

DEF_COMMAND(TurnLeft)
{
    direction = direction.leftSide();
}
