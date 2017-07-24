#include "command/ForwardCommand.h"
#include "coordinate/Direction.h"
#include "coordinate/Position.h"

DEF_COMMAND(Forward)
{
    position = position + direction.getUnit();
}


