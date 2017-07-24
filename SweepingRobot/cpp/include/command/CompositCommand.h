#ifndef INCLUDE_COMPOSITCOMMAND_H_
#define INCLUDE_COMPOSITCOMMAND_H_

#include "command/Command.h"
#include <vector>

struct CompositCommand : Command
{
private:
    OVERRIDE(void operator()(Direction&, Position&) const);

protected:
    CompositCommand(){};
    ~CompositCommand();
    void add(const Command&);

private:
    typedef std::vector<const Command*> Commands;
    Commands commands;
};

#endif
