#ifndef StructWrapper__H__
#define StructWrapper__H__

#include <base/static_assert.h>

///////////////////////////////////////////////////////////////////////
template <typename FROM, typename TO>
struct StructWrapper : FROM
{
	static const TO& by(const FROM& from)
	{
	    STATIC_ASSERT(sizeof(FROM) == sizeof(TO));

	    return (const TO&)from;
	}

	static TO& by(FROM& from)
	{
		return (TO&)from;
	}
};

///////////////////////////////////////////////////////////////////////
#define STRUCT_WRAPPER(to, from) struct to : StructWrapper<from, to>

///////////////////////////////////////////////////////////////////////

#endif 
