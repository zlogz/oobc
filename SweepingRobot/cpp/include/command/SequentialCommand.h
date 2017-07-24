#ifndef INCLUDE_SEQUENTIALCOMMAND_H_
#define INCLUDE_SEQUENTIALCOMMAND_H_

#include "command/CompositCommand.h"

struct SequentialCommand : CompositCommand
{
    typedef std::initializer_list<const Command*> CommandList;

    SequentialCommand(const CommandList&);
};

#endif
