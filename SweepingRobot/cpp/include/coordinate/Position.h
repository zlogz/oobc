#ifndef INCLUDE_POSITION_H_
#define INCLUDE_POSITION_H_

#include "coordinate/Coordinate.h"

struct Position : private Coordinate
{
    Position(const S32 x, const S32 y);

    const Position operator+(const Coordinate& unit) const;
    const Position operator-(const Coordinate& unit) const;

    __DECL_EQUALS(Position);
};

#endif
