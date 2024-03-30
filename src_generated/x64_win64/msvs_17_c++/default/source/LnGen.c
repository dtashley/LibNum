//--------------------------------------------------------------------------------------------------
//LibNum general functions.
// 
//If the library will be used from C++, there are varying mechanisms for causing the C++
//compiler to use C calling conventions.  In Microsoft Visual Studio, the "compile files
//with .C extension as C" option must be selected.  In GCC, the "-c" option must be used
//for the .C files only.
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
#define MODULE_LNGEN

#include "LibNum.h"


/*!
 * Returns the version number of the library.
 *
 * \param[out]  out_major_version      If the pointer passed by the caller is non-null,
 *                                     this function provides the caller with the major version
 *                                     of the library.
 * \param[out]  out_minor_version      If the pointer passed by the caller is non-null,
 *                                     this function provides the caller with the minor version
 *                                     of the library.
 * \param[out]  out_patch_version      If the pointer passed by the caller is non-null,
 *                                     this function provides the caller with the patch version
 *                                     of the library.
 * \notes                              <i>out_major_version</i> and <i>out_minor_version</i> are
 *                                     interpreted literally, whereas <i>out_patch_version</i> is
 *                                     mapped to letters, a-z, aa, ab, ac, etc.  (1, 2, 3) would
 *                                     correspond to version 1.2c.  The three pointers may be non-null
 *                                     or null independently--this function tests the pointers individually
 *                                     and will fill in the components corresponding to non-null pointers.
 *                                     The pointers may not be coincident; and the behavior of this function
 *                                     in this case is undefined in terms of the data the caller will
 *                                     receive, but not harmful.
 * \returns                            Nothing through the function name.
 * \reentrancyandthreadsafety          This function is re-entrant and thread safe, so long as the memory
 *                                     pointed to does not overlap between threads.
 * \errorsandexceptions                This function cannot generate exceptions.
 */
void LnVersionOUb32fOUb32fOUb32f(tLnLimb32* const out_major_version, tLnLimb32* const out_minor_version, tLnLimb32* const out_patch_version)
{
   //Fill in the major version, if the passed pointer is non-NULL.
   if (out_major_version)
   {
      *out_major_version = 0;
   }

   //Fill in the minor version, if the passed pointer is non-NULL.
   if (out_minor_version)
   {
      *out_minor_version = 0;
   }

   //Fill in the patch version, if the passed pointer is non-NULL.
   if (out_patch_version)
   {
      *out_patch_version = 0;
   }
}


/*!
 * Checks everything that can be checked about about the library build.  If this function
 * returns 0, the library is not safe to use.
 *
 * \returns                      !=0 if the library build has passed all checks, or 0
 *                               otherwise.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          This function cannot generate exceptions.
 */
tLnU8 LnGenCheckOBb8(void)
{
   if (
         (sizeof(tLnU8 *)   == 8) //Assume all pointers same size, so only check 1.
         &&
         (sizeof(tLnSizet)  == 8)
         &&
         (sizeof(tLnU8)     == 1)
         &&
         (sizeof(tLnU32)    == 4)
         &&
         (sizeof(tLnLimb32) == 4)
      )
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

//End of LnGen.c.
