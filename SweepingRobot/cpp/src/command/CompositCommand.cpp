#include "command/CompositCommand.h"
#include "command/def_command.h"

//////////////////////////////////////////////////
DEF_COMMAND(Composit)
{
    for(auto command : commands)
    {
        (*command)(direction, position);
    }
}

//////////////////////////////////////////////////
void CompositCommand::add(const Command& command)
{
    commands.push_back(&command);
}

//////////////////////////////////////////////////
CompositCommand::~CompositCommand()
{
    for(auto command : commands)
    {
        delete command;
    }
}
