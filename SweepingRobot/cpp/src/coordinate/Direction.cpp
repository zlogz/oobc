#include "coordinate/Direction.h"

///////////////////////////////////////////////////
Direction::Direction(const S32 x, const S32 y)
: Coordinate(x, y)
{
}

///////////////////////////////////////////////////
__DEF_EQUALS(Direction)
{
    return Coordinate::operator ==(rhs);
}

///////////////////////////////////////////////////
const Coordinate& Direction::getUnit() const
{
    return *this;
}

///////////////////////////////////////////////////
const Direction Direction::leftSide() const
{
    return Direction(-getY(), getX());
}

///////////////////////////////////////////////////
const Direction Direction::rightSide() const
{
    return Direction(getY(), -getX());
}

///////////////////////////////////////////////////
#define DEFINE_DIRECTION(name, x_unit, y_unit)  \
const Direction Direction::name()               \
{                                               \
    return Direction(x_unit, y_unit);           \
}

///////////////////////////////////////////////////
DEFINE_DIRECTION(north,  0,  1)
DEFINE_DIRECTION(west,  -1,  0)
DEFINE_DIRECTION(south,  0, -1)
DEFINE_DIRECTION(east,   1,  0)
