#include "coordinate/Coordinate.h"

//////////////////////////////////////////////////
Coordinate::Coordinate(const S32 x, const S32 y)
: x(x), y(y)
{
}

//////////////////////////////////////////////////
__DEF_EQUALS(Coordinate)
{
    return (x == rhs.x) && (y == rhs.y);
}

//////////////////////////////////////////////////
S32 Coordinate::getX() const
{
    return x;
}

//////////////////////////////////////////////////
S32 Coordinate::getY() const
{
    return y;
}
