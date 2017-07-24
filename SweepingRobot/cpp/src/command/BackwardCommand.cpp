/*
 * BackwardCommand.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: fingerballet
 */

#include "command/BackwardCommand.h"
#include "coordinate/Direction.h"
#include "coordinate/Position.h"

DEF_COMMAND(Backward)
{
    position = position - direction.getUnit();
}
