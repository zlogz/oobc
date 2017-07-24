#ifndef INCL_BaseTypes_20131017061824_H_
#define INCL_BaseTypes_20131017061824_H_

typedef unsigned char  BYTE;
typedef unsigned char  UCHAR;
typedef signed char SCHAR;
typedef char CHAR;
typedef int  INT;
typedef short SHORT;
typedef long LONG;


typedef unsigned short WORD;
typedef unsigned short WORD16;
typedef signed short   SWORD16;

typedef unsigned int        WORD32;

typedef int    SWORD32;
typedef int BOOL;

#ifdef WIN32
typedef __int64          SWORD64;
typedef unsigned __int64 WORD64;
#else
typedef unsigned long long WORD64;
#endif

typedef signed char  INT8;
typedef short INT16;
typedef int   INT32;

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;

typedef unsigned char  U8;
typedef unsigned short U16;
typedef unsigned int   U32;
typedef unsigned long long U64;

typedef signed char  S8;
typedef signed short S16;
typedef signed int   S32;
typedef signed long long S64;

typedef unsigned char   BOOLEAN;

typedef double DOUBLE;
typedef float  FLOAT;
#ifndef VOID
#define VOID void
#endif

#endif
