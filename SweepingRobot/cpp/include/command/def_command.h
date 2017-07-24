#ifndef INCLUDE_DEF_COMMAND_H_
#define INCLUDE_DEF_COMMAND_H_

#include "command/Command.h"

/////////////////////////////////////////////////////////
#define COMMAND_NAME(NAME) NAME##Command

/////////////////////////////////////////////////////////
#define DECL_COMMAND(NAME)                      \
struct COMMAND_NAME(NAME) : Command             \
{                                               \
private:                                        \
    OVERRIDE(void operator()(Direction&, Position&) const);\
}

/////////////////////////////////////////////////////////
#define DEF_COMMAND(NAME)                  \
void COMMAND_NAME(NAME)::operator()(Direction& direction, Position& position) const

#endif
