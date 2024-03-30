//--------------------------------------------------------------------------------------------------
//Header file for LibNum.  This file must be #include'd in any source file that uses the
//library.
//
//All functions in the library use the C calling convention (to avoid name mangling).  This
//#include file and the library should be usable from both C and C++.
//--------------------------------------------------------------------------------------------------
//This file is part of LibNum, https://github.com/dtashley/LibNum, and is provided
//under The Unlicense, reproduced below.
//--------------------------------------------------------------------------------------------------
//This is free and unencumbered software released into the public domain.
//
//Anyone is free to copy, modify, publish, use, compile, sell, or
//distribute this software, either in source code form or as a compiled
//binary, for any purpose, commercial or non - commercial, and by any
//means.
//
//In jurisdictions that recognize copyright laws, the author or authors
//of this software dedicate any and all copyright interest in the
//software to the public domain.We make this dedication for the benefit
//of the public at large and to the detriment of our heirs and
//successors.We intend this dedication to be an overt act of
//relinquishment in perpetuity of all present and future rights to this
//software under copyright law.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//OTHER DEALINGS IN THE SOFTWARE.
//
//For more information, please refer to <https://unlicense.org>
//--------------------------------------------------------------------------------------------------
#ifndef LN_LIBNUM_H_INCLUDED
#define LN_LIBNUM_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
   extern "C" {
#endif

typedef size_t tLnSizet;
   //Adopt the appropriate size_t from the target system.
typedef uint8_t  tLnU8;
typedef uint32_t tLnU32;
   //Fixed sizes.
typedef uint32_t tLnLimb32;
   //The size of a limb;

/* LnGen.c */
extern void LnVersionOUb32fOUb32fOUb32f(tLnLimb32* const out_major_version, tLnLimb32* const out_minor_version, tLnLimb32* const out_patch_version);
extern tLnU8 LnGenCheckOBb8(void);

/* LnZbm.c */
extern tLnU8    LnZbmBcardOHbaILbd(tLnLimb32 in_limb);
extern tLnSizet LnZbmBcardOZbaILbd(tLnLimb32 in_limb);
extern tLnU8    LnZbmBcardOHbaIHbd(tLnU8     in_byte);
extern tLnSizet LnZbmBcardOZbaIHbd(tLnU8     in_byte);

#ifdef __cplusplus
   }
#endif

#endif

//End of LibNum.h.
