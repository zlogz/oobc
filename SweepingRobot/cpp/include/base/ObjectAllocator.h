#ifndef _OBJECT_ALLOCATOR_H
#define _OBJECT_ALLOCATOR_H

#include "base/BaseTypes.h"
#include "base/NullPtr.h"

template<typename T, WORD16 MAX_NUM>
struct ObjectAllocator
{
    ObjectAllocator() 
        : freeHead(__null_ptr__)
        , freeTail(__null_ptr__)
        , freeCounter(0)
    {
        for(WORD16 i = 0; i < MAX_NUM; i++)
        {
            freeEntity(entities[i]);
        }
    }

    WORD16 getFreeSlotNum() const
    {
        if (freeCounter < 0 || freeCounter > MAX_NUM)
        {
            return 0xFFFF;
        }

        return freeCounter;
    }

    bool hasFreeSlot() const
    {
        return freeHead != __null_ptr__;
    }

    void* alloc()
    {
        if(!hasFreeSlot())
        {
            return __null_ptr__;
        }
        return doAlloc();
    }

    void free(void* p)
    {
        if(p == __null_ptr__) return;
        //if (isFree(p)) return; //important!, protect case :free a entity which has been freed

        if(!within(p)) return;
        if(!((((char*)p - (char*)entities) % sizeof(Entity)) == 0)) return;

        freeEntity(*(Entity*)p);
    }

    bool within(void* p) const
    {
        return p >= (void*)entities && p < (void*)&(entities[MAX_NUM]);
    }

private:
    union Entity
    {
        char obj[sizeof(T)];
        Entity* next;
    };

private:

    void* doAlloc()
    {
        void* p = (void*)freeHead;

        freeHead = freeHead->next;

        if(freeHead == __null_ptr__)
        {
            freeTail = __null_ptr__;
        }

        freeCounter--;

        return p;
    }

    void freeEntity(Entity& entity)
    {
        if(freeHead == 0)
        {
            freeHead = &entity;
        }
        else
        {
            CMAC_ASSERT_VALID_PTR_VOID(freeTail);
            freeTail->next = &entity;
        }

        freeTail = &entity;
        freeTail->next = __null_ptr__;
        freeCounter++;
    }

    bool isFree(const void* p) const
    {
        Entity* _header = freeHead;
        while (_header != __null_ptr__)
        {
            if(_header == p) return true;
            _header = _header->next;
        }

        return false;
    }

private:
    Entity entities[MAX_NUM];
    Entity* freeHead;
    Entity* freeTail;
    WORD16  freeCounter;
};

//////////////////////////////////////////////////////////////////////////
#define DECL_OPERATOR_NEW()              \
void* operator new(size_t) throw();      \
void operator delete(void* p)

//////////////////////////////////////////////////////////////////////////
#define DEF_OPERATOR_NEW(p_type, allocator)                     \
    void* p_type::operator new(size_t) throw()                  \
    {                                                           \
       return allocator.alloc();                                \
    }                                                           \
    void p_type::operator delete(void* p)                       \
    {                                                           \
        allocator.free(p);                                      \
    }

//////////////////////////////////////////////////////////////////////////
#define DEF_GENERIC_OPERATOR_NEW(p_type, allocator)             \
    template <typename T>                                       \
    void* p_type<T>::operator new(size_t) throw()               \
    {                                                           \
       return allocator.alloc();                                \
    }                                                           \
    template <typename T>                                       \
    void p_type<T>::operator delete(void* p)                    \
    {                                                           \
        allocator.free(p);                                      \
    }


//////////////////////////////////////////////////////////////////////////
#define DEF_OBJ_ALLOCATOR(p_type, p_num)                    \
namespace {                                                 \
  ObjectAllocator<p_type, p_num> p_type##Allocator;         \
}                                                           \
DEF_OPERATOR_NEW(p_type, p_type##Allocator)


#endif

