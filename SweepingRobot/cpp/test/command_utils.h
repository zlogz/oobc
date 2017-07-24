#ifndef TEST_COMMAND_UTILS_H_
#define TEST_COMMAND_UTILS_H_

#include "command/BackwardCommand.h"
#include "command/ForwardCommand.h"
#include "command/TurnLeftCommand.h"
#include "command/TurnRightCommand.h"
#include "command/SequentialCommand.h"
#include "command/RepeatCommand.h"

#define MEM_WRAPPER(CMD, ...)   (new CMD(__VA_ARGS__))

#define __backward              MEM_WRAPPER(BackwardCommand)
#define __forward               MEM_WRAPPER(ForwardCommand)
#define __turn_left             MEM_WRAPPER(TurnLeftCommand)
#define __turn_right            MEM_WRAPPER(TurnRightCommand)
#define __commands(...)         MEM_WRAPPER(SequentialCommand, {__VA_ARGS__})
#define __repeat(n, command)    MEM_WRAPPER(RepeatCommand, n, command)

#define __forwards(n)           __repeat(n, __forward)
#define __backwards(n)          __repeat(n, __backward)
#define __turn_round            __repeat(2, __turn_left)

#endif
