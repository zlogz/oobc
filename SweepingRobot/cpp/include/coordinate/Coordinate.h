#ifndef INCLUDE_COORDINATE_H_
#define INCLUDE_COORDINATE_H_

#include "base/BaseTypes.h"
#include "base/EqHelper.h"

struct Coordinate
{
    Coordinate(const S32 x, const S32 y);

    S32 getX() const;
    S32 getY() const;

    __DECL_EQUALS(Coordinate);

private:
    S32 x;
    S32 y;
};

#endif
