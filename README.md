# LibNum

A Microcontroller-Centric Arithmetic, Cryptography, and Utility Library

## Current Status

This project is just getting started, so nothing is usable yet.  At this 
time, there are just a few modules designed to be used in Microsoft Visual 
Studio.  Also, my thoughts are spread between GitHub Markdown documents 
and the user manual (a LaTeX document with source code in this 
repository).  

## Brief Description

### Overview

_LibNum_ will be a traditional thread-safe arithmetic and utility library, 
designed to be compatible with embedded software as well as server and PC 
software.  The library is composed of one function or data structure per 
object module, so that a linker can minimize the program memory footprint 
by extracting only the minimum set of functions and data structures 
necessary to link.  However, the source code for the library will be 
generated from templates, so the library will be provided for each 
platform in several other forms, including a collection of source files 
that are organized in an ordinary way (many functions per source file), so 
that the source files can simply be incorporated in source form into a 
project.  

### Areas of Functionality
- Utility and miscellaneous operations (such as determining the
version number of the library or the size of certain data types).
- Integer arithmetic and utility functions that operate on fundamental
(built into the compiler) character and integer types.
- Integer arithmetic and utility functions that operate on large
(not fundamental) integers.
- Fixed-point utility and arithmetic functions that operate on fundamental
(built into the compiler) character and integer types.
- Fixed-point mathematical functions that operate on large
(not fundamental) character and integer types.
- Floating-point arithmetic and utility functions that operate on
fundamental data types.
- Linear filter and control system component functions.
- Non-linear filter and control system component functions.
- Block memory operations (setting, copying, shifting, etc.).
- Searching (linear search, binary search, etc.)
- Sorting.
- Array manipulation.
- Bit-mapped sets.
- Vertical counters.
- Pseudo-random number generation functions.
- Non-cryptographic hash functions.
- Cryptographic hash functions.
- Symmetric cipher functions.
- Asymmetric cipher functions.
- Supports both C and C++ calling conventions.
-   (In practice, this means that the
  library can be used from both C and C++, as C++ compilers typically
  support C libraries and C code.)
- Contains core functions written in assembly-language, with a C fallback.
  (Large integer and cryptographic functions tend not to be very efficient
  when implemented in a high-level language.)
- Supports multi-core systems and systems with complex memory architectures (coherent
  and non-coherent caches).
- Can be used:
  - As a conventional binary library without source code.
  - As a conventional binary library with source code (some debuggers can use
    source code accompanying a library).
  - As a conventional library with source code that has been customized/modified
    by the end user.
  - By harvesting the library source code to create non-library software modules(s).
    - The library is designed so that the desired functions and data structures
      can be copied into source files and incorporated in a software project.
      (Usually, at least two source files are required:  a C source file
      containing the C functions and data structures and an assembly-language
      source file containing the assembly-language functions and data
      structures.)
    - This approach may be helpful when working with debuggers that don't
      support libraries well.

### Licensing

_LibNum_ is provided under _The Unlicense_ (full text below).  The license places
no restrictions (other than the inabilty to litigate) on a user of the software.
The software may be used without restriction or obligation in embedded products.

<i>
    *This is free and unencumbered software released into the public domain.<br><br>
    Anyone is free to copy, modify, publish, use, compile, sell, or<br>
    distribute this software, either in source code form or as a compiled<br>
    binary, for any purpose, commercial or non-commercial, and by any<br>
    means.<br><br>
    In jurisdictions that recognize copyright laws, the author or authors<br>
    of this software dedicate any and all copyright interest in the<br>
    software to the public domain. We make this dedication for the benefit<br>
    of the public at large and to the detriment of our heirs and<br>
    successors. We intend this dedication to be an overt act of<br>
    relinquishment in perpetuity of all present and future rights to this<br>
    software under copyright law.<br><br>
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,<br>
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF<br>
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.<br>
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR<br>
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,<br>
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR<br>
    OTHER DEALINGS IN THE SOFTWARE.<br><br>
    For more information, please refer to &lt;https://unlicense.org&gt;
</i>
<br><br>

### Memory Management Paradigm

- Trivial input and output parameters (fundamental data types, for example) are passed
by value, and consume little space on the stack.  (This is consistent with
re-entrancy.)
- Trivial variables (such as for iteration) and trivial amounts of temporary storage are
implemented as local variables and so are allocated on the stack.  (The trivial amounts of
stack memory consumed are consistent with the needs of embedded systems, and also
help to make the code re-entrant.)
- Larger input and output parameters are passed by reference.  This has three
implications:
  - The caller is able to select a location for the memory that is appropriate
for the system.  (The memory may be allocated on the caller's stack, or the
memory may be allocated elsewhere.)
  - The caller is able to deal with threading and concurrency issues that
apply to the memory as appropriate.
  - The caller is able to deal with multi-core issues as appropriate.  (For
example, some multi-core systems require explicit steps to maintain cache
coherency between cores.  These issues are left to the caller.  If the output
of a _LibNum_ function will be used by another core, the caller has the
responsibility of taking the platform-specific steps to ensure that works
as intended.)
- Requirements for more than trivial amounts of temporary storage during the
execution of a _LibNum_ function are met by having the caller provide the
temporary storage, by reference.
  - This allows the caller to determine the best source from which to
allocate the memory.
  - This allows the caller to deal appropriately with threading and
concurrency issues.  If the called function is to be re-entrant,
the different threads simultaneously using the function
can't use the same memory for temporary storage.

### Threading and Concurrency Paradigm

The threading and concurrency paradigm is closely related to the memory
management paradigm.

- For use from multiple threads of a multi-threaded application,
no special precautions are required:
  - Function parameters and local variables are automatically
thread safe by virtue of being on the stack.
  - Function inputs, outputs, and temporary storage passed by
reference are also thread-safe, provided that the caller allocates
these from a thread-safe location.
- For use from interrupt service routines, care has to be taken that
registers used are properly saved.  With many compilers, this setup
is performed by the compiler by using an additional keyword.
- For use from multiple cores, there may also the the issue of cache
coherency, but thread safety should be automatic.

### Organization of Source Code Tree

Differentiators, in order:
- First directory level (x64_linux).
  - Processor family (x64, etc.)
  - Operating system (win, linux, msys_win64, etc.)
- Second directory level, Compiler family, version, and language.
  - gcc_17_c, g++_17_c++, msvs_17_c, etc.
- Third directory level, Compiler options (default options, larger than normal integers, whatever).
- Fourth directory level, Library generation paradigm (hand-rolled-looking source, library, all-in-one, etc.)

# Preprocessor Switches

I would not anticipate any preprocessor switches that are selected from the compiler command line.
The code would be for the "typical" case.  There may be alternate code available, and there may be
alternative forms of code that can be switched in or out.  However, this would need to be in the form
of preprocessor switches with hard constants.  If the user desires alternate code, the constants
would need to be changed at the point of the alternate code and the library rebuilt.  These changes
should be available at the site of the code only.

# Design Decisions

- The largest fixed integer parameters that will be accommodated are
512 bits.  Larger types will be treated as variable.
- *Doxygen* will be used for documentation.
- Input parameters by reference are truly *const*.  They will not be modified
or experience a write cycle during the execution of the function.  This means that
they can be a type of memory that is inherently *const* (such as FLASH memory)
without triggering an exception.  In the case it is RAM, the input is thread-safe.
- Output parameters by reference may be used for staging and intermediate calculation, and may be
written more than once, and/or read.  Their values are guaranteed only when a function
has completed.
- Input/Output parameters by reference are same as output parameters.  May be used for
intermediate results, and may be written more than once.  Value guaranteed only after
function terminates.
- Will use C calling conventions because every C++ compiler can do that, and it
sidesteps name mangling.
- Each source file will be potentially be divided into two portions, a C portion and an
assembly-language portion.  Any assembly-language portion will have the base file name suffixed
with *_a*, then the extension associated with assembly-language on the platform.  There
is no hard and fast rule for which modules will have assembly-language portions and which
will not.  It depends on how well the compiler does, what non-standard compiler extensions
are available to introduce assembly-language, etc.  It will vary from platform to platform.
What is guaranteed is that the union of the *.c* file and the assembly-language file
contains all the implemented functions.
- The above point may put constraints on the generation paradigm.  I think the C and the AL should
be generated from the same template for a given module.  This means another
parameter to the generation.  May require some planning.
- Functions would deal with fixed-size operands.  The mapping from built-in data types (int, etc.)
to the fixed size will occur via wrapper functions.
- Limb size on every platform will be 32 bits.  Reasons:
  - Cryptographic functions are typically specified in 32-bit words.
  - 32-bit words are commonly available.
  - If the processor supports larger operands, functions can usually be written so that
the higher-end processors fetch multiple 32-bit words at a time or otherwise
pretend they are operating on an array of 32-bit words.
   - Less capable processors can also have code written to act as if they operate
on 32-bit words.
- All of the available functions would be declared in one .h file.
- In large integers, limbs will be stored in the way most convenient for the machine.
Which leads to the topic of representation.
- The only representations supported for large integers will be:
  - Array of limbs, MSL to LSL (convenient for microcontroller work with fixed-size operands, easy for humans to understand).
  - Array of limbs, LSL to MSL (convenient for arbitrary-sized integers, so that the integers can grow without relocation).
  - Array of bytes, MSB to LSB (convenient for smaller microcontrollers with fixed-size operands, human-friendly).
- Because processors vary in how words are stored, there can't be any assumptions made about how the limbs map to shorter integers or characters.  Explicit conversion functions are provided, but without those, limbs can be accessed only as limbs.
- Limb-based functions operate only in integers that are a multiple of 32 bits in size.  Byte-based functions are provided only in multiples of 16 bits.
- No representations for negative integers other than 2's complement are supported.  However, the functions in this library can be wrapped to support other implmentations.  The unsigned functionality can be used with a sign maintained by the wrapper.  The GMP, for example, maintains all integers as unsigned with the sign contained in the length variable.
- Although primitive arithemtic functions will support all of the formats, certain higher-level
functions may work with only some of the formats.
- Operand sizes and formats:
  - Data direction:
    - "I" for input.
    - "O" for output.
    - "IO" for input/output.
  - Fundamental types:
    - "Ub" for unsigned integer as fundamental type.
    - "Uc" for unsigned integer as array of limbs, MSL to LSL.
    - "Ud" for unsigned integer as array of limbs, LSL to MSL.
    - "Uh" for unsigned integer as unsigned bytes, MSB to LSB.
    - "Sb" for signed integer as fundamental type, 2's complement.
    - "Sc" for signed integer as array of limbs, MSL to LSL, 2's complement.
    - "Sd" for signed integer as array of limbs, LSL to MSL, 2's complement.
    - "Sh" for signed integer as unsigned bytes, MSB to LSB, 2's complement.
    - "Ib" for either type of integer (U or S) as fundamental type.
    - "Ic" for either type of integer (U or S) as array of limbs, MSL to LSL.
    - "Id" for either type of integer (U or S) as array of limbs, LSL to MSL.
    - "Ih" for either type of integer (U or S) as unsigned bytes, MSB to LSB.
    - "Hb" for unsigned character.
    - "Ha" for array of unsigned characters not representing an integer in the framework described above.
    - "Lb" for limb, not necessarily representing an integer.
    - "La" for array of limbs, not necessarily representing an integer.
    - "Zb" for size_t.
    - "Za" for array of size_t.
    - "Xb" for a bit pattern not numerical in nature.
    - "Xa" for an array of a bit pattern not numerical in nature.
    - "Bb" for Boolean, typically 8 bits.
    - "Ba" for an array of Boolean, typically each 8 bits.
    - "Eb" for other enumerated type, a built-in representation.
    - "Ea" for an array of enumerated type.
    - "Fb" for float.
    - "Fa" for an array of floats.
    - "Db" for double.
    - "Da" for an array of doubles.
    - "Rb" for TBD representation of real number.
    - "Ra" for array of TBD representation of real number.
    - "Tb" for other built-in representation.
    - "Ta" for array of other built-in representation.
    - Other specifiers TBD.
  - Size of the data type in bits, or "n" for arbitrary.
  - Representation code:
    - "a" for returned by value via the function name.
    - "b" for returned by reference via the function name, pointer supplied by caller may not be null.
    - "c" for returned by reference via the function name, pointer supplied by caller may be null, and library function must test before using pointer.
    - "d" for passed by value through the parameter list.
    - "e" for passed by reference through the parameter list, pointer supplied by caller may not be null.
    - "f" for passed by reference through the parameter list, pointer supplied by caller may be null, and library function must test before using pointer.
- Function naming:  function names will have the following components, in order.
  - *Ln*, for *L*ib*N*um.
  - Function family.
  - Function.
  - Function modifiers.
  - Output size and format, as described above.
  - Operand format(s) and size(s), as described above.
- Function families.
  - Zbm : Integer bit manipulation.
    - Applies to both unsigned and signed types. 
  - Zar : Integer arithmetic.
    - Applies to both unsigned and signed types.
  - Zal : Integer algorithms.
    - Applies to both unsigned and signed types.
  - Xvc : Bitwise vertical counters.
    - Not bound to types.
  - Zsr : Integer search.
    - Applies to both unsigned and signed types.
  - Zso : Integer sort.
    - Applies to both signed and unsigned types.
  
