#ifndef INCL_CMAC_NullPtr_20140311151414_H__
#define INCL_CMAC_NullPtr_20140311151414_H__

#include "Config.h"

#if __SUPPORT_NULL_PTR
#define __null_ptr__ nullptr
#else
#define __null_ptr__ 0
#endif

#define __is_null(ptr) ((ptr) == __null_ptr__)
#define __not_null(ptr) ((ptr) != __null_ptr__)

#endif
