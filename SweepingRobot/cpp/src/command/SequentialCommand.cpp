#include "command/SequentialCommand.h"

SequentialCommand::SequentialCommand(const CommandList& commands)
{
    for(auto command : commands)
    {
        add(*command);
    }
}

