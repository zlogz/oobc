#ifndef INCL_DCM_down_cast_H__
#define INCL_DCM_down_cast_H__

template <typename TO, typename FROM>
TO& down_cast(FROM& from)
{
    return (TO&)from;
}

#endif

