#ifndef INCL_DCM_Singleton_H_
#define INCL_DCM_Singleton_H_

#include "base/Uncloneable.h"

template<typename T>
struct Singleton
{
    static T& getInstance()
    {
        static T instance;
        return instance;
    }

    DISALLOW_COPY_AND_ASSIGN(Singleton)

protected:
    Singleton() {}
};

#define DEF_SINGLETON(object) struct object : Singleton<object>

#endif
