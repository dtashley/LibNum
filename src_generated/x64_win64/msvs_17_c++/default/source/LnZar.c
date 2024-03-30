//--------------------------------------------------------------------------------------------------
//LibNum integer arithmetic functions.
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
 * Increments a 32-bit integer (either unsigned or signed), represented as 4 bytes, MSB
 * to LSB.  Rollover to 0 is supported.
 *
 * \param[in]  in_U8arr4         Pointer to the first byte of the array of 4 bytes containing
 *                               the integer to be incremented.  This pointer may not be null
 *                               or otherwise invalid.
 * \returns                      != 0 if a rollover to 0 occurred, or 0 otherwise.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          This function cannot generate exceptions.  The function is
 *                               designed to operate without exceptions for all possible values
 *                               of data.
 */
tLnU8 LnZarIncOB8aIOUh32e(tLnU8 * const in_U8arr4)
{
   in_U8arr4[3]++;
   if (!in_U8arr4[3])
   {
      in_U8arr4[2]++;
      if (!in_U8arr4[2])
      {
         in_U8arr4[1]++;
         if (!in_U8arr4[1])
         {
            in_U8arr4[0]++;
            if (!in_U8arr4[0])
            {
               return 1;
            }
            else
            {
               return 0;
            }
         }
         else
         {
            return 0;
         }
      }
      else
      {
         return 0;
      }
   }
   else
   {
      return 0;
   }
}

//End of LnZar.c.
