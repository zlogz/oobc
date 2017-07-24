#ifndef INCL_MAX_MIN_H
#define INCL_MAX_MIN_H

#include "BaseTypes.h"
#include <algorithm>


#define __MIN(a,b)    std::min(a, b)
#define __MAX(a,b)    std::max(a, b)

#define __BETWEEN(v, min, max) __MAX((min), __MIN((v), (max)))

template <typename T, T MIN_VALUE, T MAX_VALUE>
struct ValueScope
{
	static T fix(const T value)
	{
		return std::max(MIN_VALUE, std::min(MAX_VALUE, value));
	}
};

template <typename T, T MIN, T MAX>
inline T __between(const T value)
{
	return ValueScope<T, MIN, MAX>::convert(value);
}

template <typename T, T MIN, T MAX>
inline bool __isBetween(const T value)
{
    return (value >= MIN) && (value <= MAX);
}


#endif
