#ifndef ROLE_H_
#define ROLE_H_

#include "Keywords.h"

/////////////////////////////////////////////////////////////////////////////
namespace details
{
   template<typename T>
   struct Role
   {
      virtual ~Role() {}
   };
}

#define DEFINE_ROLE(role)  struct role : ::details::Role<role>

#endif
