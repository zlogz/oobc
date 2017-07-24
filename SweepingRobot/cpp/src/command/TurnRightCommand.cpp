#include "command/TurnRightCommand.h"
#include "coordinate/Direction.h"

DEF_COMMAND(TurnRight)
{
    direction = direction.rightSide();
}

