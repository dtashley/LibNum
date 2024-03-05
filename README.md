# LibNum

A Microcontroller-centric Arithmetic, Cryptography, and Utility Library

## Current Status

This project is just getting started, so nothing is usable yet.  At this time,
there are just a few modules designed to be used in Microsoft
Visual Studio.  Also, my thoughts are spread between GitHub Markdown
documents and the user manual (a LaTeX document with source code in this
repository).

## Brief Description

### Overview

_LibNum_ is a traditional thread-safe arithmetic and utility library,
designed to be compatible with embedded software as well as
server and PC software.  The library is
composed of one function or data structure per object module, so that
a linker can minimize the program memory footprint by extracting
only the minimum set of functions and data structures necessary to link.  
However, the source code for the library is generated from templates, so
the library is provided for each platform in several other forms, including a
collection of source files that are organized in an ordinary way
(many functions per source file), so that the source files can simply
be incorporated in source form into a project.

### Areas of Functionality
- Utility and miscellaneous operations (such as determining the
version number of the library or the size of certain data types).
- Integer arithmetic and utility functions that operate on basic
(built into the compiler) character and integer types.
- Integer arithmetic and utility functions that operate on large
(sizes not necessarily supported by the compiler) integers.
- Fixed-point utility and arithmetic functions that operate on basic
(built into the compiler) character and integer types.
- Fixed-point mathematical functions that operate on large
(sizes not necessarily supported by the compiler) character and integer types.
- Floating-point arithmetic and utility functions that operate on
basic (built into the compiler) data types.
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

- Trivial input and output parameters (native data types, for example) are passed
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
- First directory level (x64_msvs_11_0_13_4).
  - Processor family (x64, etc.).
  - Compiler toolchain (msvs, etc.).
  - Version of the compiler toolchain.
- Second directory level.
  - Operating system.
- Third directory level (c_def, cpp_i64).
  - Language (C, C++).
  - Compiler options (default options, larger-than-normal integers, whatever).
- Fourth directory level (TBD).
  - Library generation paradigm (hand-rolled-looking source, library, all-in-one, etc.)

#Preprocessor Switches

TBD.
