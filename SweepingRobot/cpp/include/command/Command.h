#ifndef INCLUDE_COMMAND_H_
#define INCLUDE_COMMAND_H_

#include "base/Role.h"

struct Direction;
struct Position;

DEFINE_ROLE(Command)
{
    ABSTRACT(void operator()(Direction&, Position&) const);
};

#endif
