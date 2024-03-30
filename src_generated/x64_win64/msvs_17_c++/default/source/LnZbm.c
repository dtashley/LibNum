//--------------------------------------------------------------------------------------------------
//LibNum integer bit manipulation constant tables and functions.
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
#define MODULE_LNZBM

#include "LibNum.h"


/*!
 * Counts the number of bits with the value of 1 in a limb and returns this value.
 *
 * \param[in]  in_limb           The limb whose bits with the value of 1 are to be counted.
 * \returns                      The number of bits with the value 1 in <i>in_limb</i>, as
 *                               a <i>tLnU8</i>, which is a byte on every system.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          This function cannot generate exceptions.  The function is
 *                               designed to operate without exceptions for all possible value
 *                               of <i>in_limb</i>.
 */
tLnU8 LnZbmBcardOHbaILbd(tLnLimb32 in_limb)
{
   return __popcnt(in_limb);
}


/*!
 * Counts the number of bits with the value of 1 in a limb and returns this value.
 *
 * \param[in]  in_limb           The limb whose bits with the value of 1 are to be counted.
 * \returns                      The number of bits with the value 1 in <i>in_limb</i>, as
 *                               a <i>tLnSizet</i>, which is equivalent to the environment's
 *                               <i>size_t</i>.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          This function cannot generate exceptions.  The function is
 *                               designed to operate without exceptions for all possible value
 *                               of <i>in_limb</i>.
 */
tLnSizet LnZbmBcardOZbaILbd(tLnLimb32 in_limb)
{
   return __popcnt(in_limb);
}


/*!
 * Counts the number of bits with the value of 1 in a byte and returns this value.
 *
 * \param[in]  in_limb           The byte whose bits with the value of 1 are to be counted.
 * \returns                      The number of bits with the value 1 in <i>in_limb</i>, as
 *                               a <i>tLnU8</i>, which is a byte on every system.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          This function cannot generate exceptions.  The function is
 *                               designed to operate without exceptions for all possible value
 *                               of <i>in_limb</i>.
 */
tLnU8 LnZbmBcardOHbaIHbd(tLnU8 in_byte)
{
   return __popcnt(in_byte);  /* I doubt there would be any advantage to using __popcnt16() here, */
                              /* as the underlying popcnt instruction is likely to be very fast   */
                              /* for a 32-bit word, and clearing the upper 24 bits of a 32-bit    */
                              /* word is likely the same cost as clearing the upper 8 bits of a   */
                              /* 16-bit integer.                                                  */
}


/*!
 * Counts the number of bits with the value of 1 in a byte and returns this value.
 *
 * \param[in]  in_limb           The byte whose bits with the value of 1 are to be counted.
 * \returns                      The number of bits with the value 1 in <i>in_limb</i>, as
 *                               a <i>tLnSizet</i>, which is equivalent to the environment's
 *                               <i>size_t</i>.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          This function cannot generate exceptions.  The function is
 *                               designed to operate without exceptions for all possible value
 *                               of <i>in_limb</i>.
 */
tLnSizet LnZbmBcardOZbaIHbd(tLnU8 in_byte)
{
   return __popcnt(in_byte);  /* I doubt there would be any advantage to using __popcnt16() here, */
                              /* as the underlying popcnt instruction is likely to be very fast   */
                              /* for a 32-bit word, and clearing the upper 24 bits of a 32-bit    */
                              /* word is likely the same cost as clearing the upper 8 bits of a   */
                              /* 16-bit integer.                                                  */
}


//End of LnZbm.c.
