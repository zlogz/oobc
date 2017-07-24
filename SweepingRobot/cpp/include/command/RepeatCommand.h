#ifndef INCLUDE_REPEATCOMMAND_H_
#define INCLUDE_REPEATCOMMAND_H_

#include "base/BaseTypes.h"
#include "command/Command.h"

struct RepeatCommand : Command
{
    RepeatCommand(const U32 times, const Command*);
    ~RepeatCommand();

private:
    OVERRIDE(void operator()(Direction&, Position&) const);

private:
    const Command* command;
    const U32 times;
};

#endif
