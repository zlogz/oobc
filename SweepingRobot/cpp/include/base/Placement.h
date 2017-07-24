#ifndef INCL_BASE_PLACEMENT_H
#define INCL_BASE_PLACEMENT_H

#include <string.h>
#include <new>

template <typename T>
struct Placement
{
    Placement& operator=(const T& rhs)
    {
        assignBy(rhs);
        return *this;
    }

    void* alloc()
    {
        return (void*)&u;
    }

    T* operator->() const
    {
        return getObject();
    }

    T& operator*() const
    {
        return getRef();
    }

    T* getObject() const
    {
        return (T*)&u;
    }

    T& getRef() const
    {
        return (T&)u;
    }

    void destroy()
    {
        getObject()->~T();
    }

private:
    void assignBy(const T& rhs)
    {
        T* p = (T*)alloc();
        *p = rhs;
    }
private:
    union
    {
        char   c;
        short  s;
        int    i;
        long   l;
        long long   ll;
        float  f;
        double d;
        void*  p;

        char buff[sizeof(T)];
    }u;
};

template <typename T>
struct DefaultPlacement : Placement<T>
{
    T* init()
    {
        return new(Placement<T>::alloc()) T();
    }
};

#endif
