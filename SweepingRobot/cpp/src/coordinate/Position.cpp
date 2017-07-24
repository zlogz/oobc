#include "coordinate/Position.h"

//////////////////////////////////////////////////////////
Position::Position(const S32 x, const S32 y)
: Coordinate(x, y)
{
}

//////////////////////////////////////////////////////////
__DEF_EQUALS(Position)
{
    return Coordinate::operator ==(rhs);
}

//////////////////////////////////////////////////
const Position Position::operator+(const Coordinate& unit) const
{
    return Position(getX() + unit.getX(), getY() + unit.getY());
}

//////////////////////////////////////////////////
const Position Position::operator-(const Coordinate& unit) const
{
    return Position(getX() - unit.getX(), getY() - unit.getY());
}
