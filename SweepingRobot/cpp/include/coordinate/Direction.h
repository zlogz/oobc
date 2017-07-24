#ifndef INCLUDE_DIRECTION_H_
#define INCLUDE_DIRECTION_H_

#include "coordinate/Coordinate.h"

struct Direction : private Coordinate
{
    static const Direction north();
    static const Direction west();
    static const Direction south();
    static const Direction east();

    const Direction leftSide() const;
    const Direction rightSide() const;

    const Coordinate& getUnit() const;

    __DECL_EQUALS(Direction);

private:
    Direction(const S32 x, const S32 y);
};

///////////////////////////////////////////////////
#define __north Direction::north()
#define __west  Direction::west()
#define __south Direction::south()
#define __east  Direction::east()

#endif
