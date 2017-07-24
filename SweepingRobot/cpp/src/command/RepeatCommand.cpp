#include "command/RepeatCommand.h"
#include "command/def_command.h"

////////////////////////////////////////////////////////////
RepeatCommand::RepeatCommand(const U32 times, const Command* command)
: command(command), times(times)
{
}

////////////////////////////////////////////////////////////
DEF_COMMAND(Repeat)
{
    for(U32 i = 0; i < times; i++)
    {
        (*command)(direction, position);
    }
}

////////////////////////////////////////////////////////////
RepeatCommand::~RepeatCommand()
{
    delete command;
}
