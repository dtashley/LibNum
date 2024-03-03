# LibNum
A Microcontroller-centric Arithmetic, Cryptography, and Utility Library

(This project is just getting started, so nothing is usable yet.  At this time,
there are just a few modules designed to be used in Microsoft
Visual Studio.)

*LibNum*:
- Is a traditional library, in that it is a library composed of one function
  or data structure per object module.  (In the traditional usage, the
  linker extracts only the minimum set of object modules it needs to
  resolve references, which gives the library a minimal footprint in
  the executable image.  This is important for embedded work, where memory
  of all types is at a premium.)
- Contains functions for:
  - Utility and miscellaneous operations (such as determining the
    version number of the library or the size of certain data types).
  - Block memory operations (setting, copying, shifting, etc.).
  - Searches (linear search, binary search, etc.)
  - Sorting.
  - Array manipulation.
  - Bit-mapped sets.
  - Vertical counters.
  - Integer arithmetic and utility functions that operate on basic
    (built into the compiler) character and integer types.
  - Integer mathematical functions that operate on basic
    (built into the compiler) character and integer types.
  - Fixed-point utility and arithmetic functions that operate on basic
    (built into the compiler) character and integer types.
  - Fixed-point mathematical functions that operate on basic
    (built into the compiler) character and integer types.
  - Floating-point arithmetic and utility functions that operate on
    basic (built into the compiler) data types.
  - Floating-point mathematical functions that operate on
    basic (built into the compiler) data types.
  - Integer arithmetic and utility functions that operate on large
    (sizes not necessarily supported by the compiler) integers.
  - Integer mathematical functions that operate on large
    (sizes not necessarily supported by the compiler) integers.
  - Fixed-point utility and arithmetic functions that operate on fixed-point
    values represented as large (sizes not necessarily supported by the
    compiler) integers.
  - Fixed-point mathematical functions that operate on fixed-point
    values represented as large (sizes not necessarily supported by the
    compiler) integers.
  - Floating-point arithmetic and utility functions that operate on
    large (sizes not necessarily supported by the compiler) data types.
  - Floating-point mathematical functions that operate on
    large (sizes not necessarily supported by the compiler) data types.
  - Linear filter and control system component functions.
  - Non-linear filter and control system component functions.
  - Pseudo-random number generation functions.
  - Non-cryptographic hash functions.
  - Cryptographic hash functions.
  - Symmetric cipher functions.
  - Asymmetric cipher functions.
- Supports C and C calling conventions.  (In practice, this means that the
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
- Is provided under _The Unlicense_ (extremely permissive).
  - The license text is:<br><br>
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
    For more information, please refer to <https://unlicense.org>*

The source code of the library is maintained as a set of source code templates that are interpreted
to generate the customized source code for each target environment.  (This eliminates
code customized via C preprocessor conditionals.  Such conditionals often confuse
debuggers and also make the soure code difficult for a human to understand.)

The documentation for the library is contained in .PDF manual packaged with the library.  To avoid
redundancy of information, the interfaces of the functions and data structures of the library
are not documented in the source code (that information is in the *.PDF* manual).  The function
internals, however, are documented in the source code.

#Preprocessor Switches
The code is parameterized by preprocessor switches specified on the command line.  To avoid
as much confusion as possible, the switches:
* Are all prefixed with *LIBNUM_CLSW_*.
* Except for the prefix, are common with the switches for *LibGen* (https://github.com/dtashley/LibGen).
* All enumerated switches must be specified, or a compilation error will result.

Switches are divided into two categories:
* Switches that are either present or absent (i.e. are Boolean in nature).
* Switches that are enumerated in nature (must be specified, and must be one of a set of values).

## `LIBNUM_CLSW_PFORM_SW`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_PFORM_SW_WINAPI`  | Windows API, also sometimes called Win32, although this is a misnomer because 64-bit programs and 64-bit operating systems also use the Windows API. |
| `LIBNUM_CLSW_PFORM_SW_WINAPI`  | Windows API with MFC. |
| `LIBNUM_CLSW_PFORM_SW_WIN_NET` | Windows .NET. |
| `LIBNUM_CLSW_PFORM_SW_UNIX`    | Unix. |
| `LIBNUM_CLSW_PFORM_SW_LINUX`   | Linux. |
| `LIBNUM_CLSW_PFORM_SW_FREEBSD` | FreeBSD. |
| `LIBNUM_CLSW_PFORM_SW_CYGWIN`  | Cygwin. |
| `LIBNUM_CLSW_PFORM_SW_MSYS`    | MSYS. |
| `LIBNUM_CLSW_PFORM_SW_ANDROID` | Android. |
| `LIBNUM_CLSW_PFORM_SW_FIRE_OS` | FireOS. |
| `LIBNUM_CLSW_PFORM_SW_IOS`     | iOS. |
| `LIBNUM_CLSW_PFORM_SW_NO_OS`   | Embedded system with none of the operating systems listed above or system with none of the operating systems listed above. |

## `LIBNUM_CLSW_PFORM_OS_ADR_SIZE`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_PFORM_OS_ADR_SIZE_32`  | 32-bit operating system with 32-bit addresses. |
| `LIBNUM_CLSW_PFORM_OS_ADR_SIZE_64`  | 64-bit operating system with 32-bit addresses. |
| `LIBNUM_CLSW_PFORM_OS_ADR_SIZE_UNSPECIFIED`  | Nature of operating system and address size unspecified. |

## `LIBNUM_CLSW_PFORM_AL`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_PFORM_AL_X86_32`       | x86 architecture, 32-bit. |
| `LIBNUM_CLSW_PFORM_AL_X86_64`       | x86 architecture, 64-bit. |
| `LIBNUM_CLSW_PFORM_AL_UNSPECIFIED`  | Architecture unspecified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_SZ_LIMB_ARITH_INT`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_SZ_LIMB_ARITH_INT_16`           | The best limb size for large integer arithmetic is 16 bits. |
| `LIBNUM_CLSW_SZ_LIMB_ARITH_INT_32`           | The best limb size for large integer arithmetic is 32 bits. |
| `LIBNUM_CLSW_SZ_LIMB_ARITH_INT_64`           | The best limb size for large integer arithmetic is 64 bits. |
| `LIBNUM_CLSW_SZ_LIMB_ARITH_INT_UNSPECIFIED`  | The best limb size for large integer arithmetic is not specified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_SZ_DT_CHAR`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_SZ_DT_CHAR_8`           | Characters are 8 bits in size. |
| `LIBNUM_CLSW_SZ_DT_CHAR_16`           | Characters are 16 bits in size. |
| `LIBNUM_CLSW_SZ_DT_CHAR_32`           | Characters are 32 bits in size. |
| `LIBNUM_CLSW_SZ_DT_CHAR_UNSPECIFIED`  | The size of short integers is not specified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_SZ_DT_INT_SHORT`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_SZ_DT_INT_SHORT_16`           | Short integers are 16 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_SHORT_32`           | Short integers are 32 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_SHORT_64`           | Short integers are 64 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_SHORT_UNSPECIFIED`  | The size of short integers is not specified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_SZ_DT_INT`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_SZ_DT_INT_16`           | Integers are 16 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_32`           | Integers are 32 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_64`           | Integers are 64 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_UNSPECIFIED`  | The size of integers is not specified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_SZ_DT_INT_L`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_SZ_DT_INT_L_32`           | Long integers are 32 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_L_64`           | Long integers are 64 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_L_96`           | Long integers are 96 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_L_128`           | Long integers are 128 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_L_UNSPECIFIED`  | The size of long integers is not specified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_SZ_DT_INT_LL`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_SZ_DT_INT_LL_64`           | Long long integers are 64 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_LL_96`           | Long long integers are 96 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_LL_128`           | Long long integers are 128 bits in size. |
| `LIBNUM_CLSW_SZ_DT_INT_LL_UNSPECIFIED`  | The size of long long integers is not specified.  This will cause generic C code to be used, which may be very inefficient in some cases. |

## `LIBNUM_CLSW_PROJTYPE`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_PROJTYPE_OBJ`           | Source files are being used to produce an object file. |
| `LIBNUM_CLSW_PROJTYPE_LIB`           | Source files are being used to produce a classic library. |
| `LIBNUM_CLSW_PROJTYPE_WINDLL`        | Source files are being used to produce Windows DLL. |
| `LIBNUM_CLSW_PROJTYPE_APP`           | Source files are being used to produce an application. |
| `LIBNUM_CLSW_PROJTYPE_UNSPECIFIED`   | The type of project is not specified. |

## `LIBNUM_CLSW_ASSERTIONS`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_ASSERTIONS_DISABLED`              | Assertions are disabled. |
| `LIBNUM_CLSW_ASSERTIONS_ENABLED`               | Assertions are enabled. |

## `LIBNUM_CLSW_DEBUGGING`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_DEBUGGING_DISABLED`              | Debugging and logging functionality should not be included. |
| `LIBNUM_CLSW_DEBUGGING_ENABLED`            | Debugging and logging functionality should be included. |
| `LIBNUM_CLSW_DEBUGLVL_UNSPECIFIED`        | Debug level is not specified. |

## `LIBNUM_CLSW_PROGTYPE`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_PROGTYPE_CONSOLE`              | Program is a console-mode utility (text input, text output). |
| `LIBNUM_CLSW_PROGTYPE_WINGUI`               | Program is a graphical program under Windows. |
| `LIBNUM_CLSW_PROGTYPE_TCL_A_CONSOLE`        | Program is Tcl console-mode utility, using Tcl code ported by Dave Ashley around 2004. |
| `LIBNUM_CLSW_PROGTYPE_TCL_A_GUI`            | Program is Tcl/Tk graphical utility, using Tcl code ported by Dave Ashley around 2004. |
| `LIBNUM_CLSW_PROGTYPE_TCL_B_CONSOLE`        | Placeholder for future console port of Tcl. |
| `LIBNUM_CLSW_PROGTYPE_TCL_B_GUI`            | Placeholder for future graphical port of Tcl/Tk. |
| `LIBNUM_CLSW_PROGTYPE_CLIKE_A_CONSOLE`      | Placeholder for future console application involving _Clike_, a yet to be developed scripting language. |
| `LIBNUM_CLSW_PROGTYPE_CLIKE_A_GUI`          | Placeholder for future graphical port of _Clike_, a yet to be developed scripting language. |
| `LIBNUM_CLSW_PROGTYPE_UNIX_SWING`           | Program developed using Unix Swing. |
| `LIBNUM_CLSW_PROGTYPE_UNIX_AWT`             | Program developed using Unix AWT. |
| `LIBNUM_CLSW_PROGTYPE_CGIBIN_HELPER`        | Program is invoked by CGI-BIN PHP, Python, or Perl scripts, like to implement functionality awkward under the scripting language. |
| `LIBNUM_CLSW_PROGTYPE_CGIBIN_HTTPD`         | Program is a CGI-BIN program invoked directly by Apache to answer HTTP[S] requests. |
| `LIBNUM_CLSW_PROGTYPE_CGIBIN_SERVER`        | Program listens on TCP port(s) and is an actual HTTP[S] server. |
| `LIBNUM_CLSW_PROGTYPE_UNITTEST_COV`         | Program is a unit test program to test library components and/or measure testing statement/branch coverage. |
| `LIBNUM_CLSW_PROGTYPE_UNSPECIFIED`          | Program type is not specified. |

## `LIBNUM_CLSW_THREADS`
Must be one of the following values:

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_THREADS_1R`                    | The program runs with one thread and a greatly reduced priority (essentially, a background program). |
| `LIBNUM_CLSW_THREADS_1`                     | The program runs with 1 thread for a console-mode program, or 2 threads for a GUI program, at unmodified priority. |
| `LIBNUM_CLSW_THREADS_HALF_PHYS_CORES`       | The program runs with a number of threads that will not use more than one half of the physical cores available. |
| `LIBNUM_CLSW_THREADS_ALL_PHYS_CORES`        | The program runs with a number of threads that will not use more than all physical cores available. |
| `LIBNUM_CLSW_THREADS_ALL_LOGICAL_CORES`     | The program runs with a number of threads that will not use more than all the logical cores available. |
| `LIBNUM_CLSW_THREADS_PROG_SET`              | The number of threads and priority are set by the program, possibly in response to command-line switches, rather than at compile time. |
| `LIBNUM_CLSW_THREADS_UNSPECIFIED`           | The number of threads and priority are unspecified. |

## `LIBNUM_CLSW_CON_MODE_LINE_LEN`
Optional.  Unsigned integer.  Must be >=38 and <=1000.  The number of printable characters per line.  If not set, defaults to 78.

## `LIBNUM_CLSW_MALLOC_STRAT`
Must be one of the following values.  Applies to malloc() and realloc() only, not new and delete.

| Constant                     | Interpretation |
| :---                         |     :---       |
| `LIBNUM_CLSW_MALLOC_STRAT_C`                 | The standard C strategy is used.  malloc() and realloc() return NULL on allocation failure. |
| `LIBNUM_CLSW_MALLOC_STRAT_CPP_EXCEP`         | An exception is thrown when out of memory. |
| `LIBNUM_CLSW_MALLOC_STRAT_CPP_EXCEP_NOTIF`   | A reserve pool is released when out of memory.  The state can be polled.  When the reserve pool is exhausted, and exception is thrown. |
