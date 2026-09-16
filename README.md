<div align="center">

![Libft — 42 / 1337](/libft-banner.svg)

**My own C library, built from the basics.**

![C](https://img.shields.io/badge/language-C-38bdf8?style=flat-square)
![42 / 1337](https://img.shields.io/badge/cursus-42%20%2F%201337-5eead4?style=flat-square)
![Static library](https://img.shields.io/badge/build-libft.a-94a3b8?style=flat-square)
![Functions](https://img.shields.io/badge/functions-26-5eead4?style=flat-square)
![In progress](https://img.shields.io/badge/status-in%20progress-fbbf24?style=flat-square)

[About](#about) · [Functions](#functions) · [Build](#build) · [Usage](#usage) · [Tests](#tests)

</div>

---

## About

**Libft** is my 42 / 1337 project for learning how a C library works: handling bytes, working with strings, allocating memory, and building reusable functions.

This repository currently contains **26 functions** from my existing implementation. Each function has a description comment above it, and the [Makefile](Makefile) explains every variable, source-list entry, rule, and command. The project is **in progress**; remaining mandatory functions and the linked-list bonus are not included yet.

### What I am learning

| Area | Practice |
| :--- | :--- |
| Characters | ASCII ranges, classification, and case conversion |
| Memory | Byte operations, overlapping copies, and allocation |
| Strings | Terminators, bounded buffers, searching, and comparison |
| Ownership | Allocation failure, cleanup, and returning independent strings |
| Build tools | Object files, static archives, dependencies, and Makefile rules |

## Functions

### Characters · 7 functions

| Function | What it does |
| :--- | :--- |
| [`ft_isalpha`](ft_isalpha.c) | Checks whether a value is an ASCII letter, including `A`, `Z`, `a`, and `z`. |
| [`ft_isdigit`](ft_isdigit.c) | Checks whether a value is a decimal digit from `0` to `9`. |
| [`ft_isalnum`](ft_isalnum.c) | Checks whether a value is an ASCII letter or digit. |
| [`ft_isascii`](ft_isascii.c) | Checks whether a value is in the ASCII range, `0`–`127`. |
| [`ft_isprint`](ft_isprint.c) | Checks whether a value is printable ASCII, including space. |
| [`ft_toupper`](ft_toupper.c) | Converts a lowercase ASCII letter to uppercase. |
| [`ft_tolower`](ft_tolower.c) | Converts an uppercase ASCII letter to lowercase. |

### Memory · 7 functions

| Function | What it does |
| :--- | :--- |
| [`ft_memset`](ft_memset.c) | Fills a memory area with a specified byte. |
| [`ft_bzero`](ft_bzero.c) | Sets a specified number of bytes to zero. |
| [`ft_memcpy`](ft_memcpy.c) | Copies bytes between memory areas that do not overlap. |
| [`ft_memmove`](ft_memmove.c) | Copies bytes safely even when the memory areas overlap. |
| [`ft_memchr`](ft_memchr.c) | Finds the first matching byte within a memory area. |
| [`ft_memcmp`](ft_memcmp.c) | Compares memory areas using unsigned bytes. |
| [`ft_calloc`](ft_calloc.c) | Allocates zero-initialized memory and checks multiplication overflow. |

### String queries and copies · 6 functions

| Function | What it does |
| :--- | :--- |
| [`ft_strlen`](ft_strlen.c) | Counts characters before a string's null terminator. |
| [`ft_strlcpy`](ft_strlcpy.c) | Copies a string within a destination capacity and returns the full source length. |
| [`ft_strlcat`](ft_strlcat.c) | Appends a string within a total buffer capacity and returns the attempted length. |
| [`ft_strchr`](ft_strchr.c) | Finds the first occurrence of a character, including the null terminator. |
| [`ft_strncmp`](ft_strncmp.c) | Compares up to a specified number of characters. |
| [`ft_strnstr`](ft_strnstr.c) | Finds a complete substring within a specified search bound. |

### New strings · 5 functions

| Function | What it does |
| :--- | :--- |
| [`ft_strdup`](ft_strdup.c) | Allocates an independent copy of a string. |
| [`ft_substr`](ft_substr.c) | Allocates a substring from a starting index, bounded by a maximum length. |
| [`ft_strjoin`](ft_strjoin.c) | Allocates a string containing two input strings joined together. |
| [`ft_strtrim`](ft_strtrim.c) | Allocates a copy with characters from a set removed from both ends. |
| [`ft_split`](ft_split.c) | Allocates an array of nonempty words separated by one delimiter character. |

### Numbers · 1 function

| Function | What it does |
| :--- | :--- |
| [`ft_atoi`](ft_atoi.c) | Reads leading whitespace, one optional sign, and decimal digits to produce an `int`. |

## Build

You need a C compiler, `make`, and `ar`.

```sh
git clone https://github.com/zakari-aee/libft.git
cd libft
make
```

The result is **`libft.a`**, a static library you can link into another C program.

| Command | Effect |
| :--- | :--- |
| `make` or `make all` | Builds the library. |
| `make clean` | Removes object files and keeps `libft.a`. |
| `make fclean` | Removes object files and `libft.a`. |
| `make re` | Cleans everything, then builds again. |
| `make test` | Builds and runs the local test suite. |
| `make CC=clang` | Uses Clang for files that need compilation. |

Run `make re CC=clang` to rebuild **every** object with another compiler. A second `make` with no changed files performs no compilation or archiving.

<details>
<summary><strong>Understand the Makefile</strong></summary>

```text
source files (.c)  →  object files (.o)  →  static library (libft.a)
                         cc -c                    ar rcs
```

| Make syntax | Meaning |
| :--- | :--- |
| `NAME = libft.a` | Stores the library filename in a variable. |
| `$(NAME)` | Reads the value of that variable. |
| `SRCS += ...` | Adds more source filenames to the existing list. |
| `$(SRCS:.c=.o)` | Replaces `.c` with `.o` in every listed filename. |
| `target: prerequisites` | Declares what a target needs before it can be built. |
| `%.o: %.c libft.h` | Matches each object to its source and shared header. |
| `$<` | Refers to the first prerequisite: the source file in the compile rule. |
| `$@` | Refers to the current target: an object or the library filename. |
| `-Wall -Wextra -Werror` | Enables warnings and makes warnings fail compilation. |
| `-c` | Compiles a source into an object without linking a program. |
| `ar rcs` | Adds or replaces archive members, creates the archive, and indexes symbols. |
| `$(MAKE)` | Calls Make again and preserves its command-line options. |
| `.PHONY` | Marks action targets so matching filenames do not prevent them from running. |

Recipe commands begin with a **tab**. The `re` target runs cleanup and rebuilding in separate, ordered commands so it also works with parallel Make.

Every active line is explained directly in the [Makefile](Makefile).

</details>

## Usage

Save this example as `main.c` in the repository root:

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char **words;
    size_t i;

    words = ft_split("42 1337 libft", ' ');
    if (!words)
        return (1);
    i = 0;
    while (words[i])
    {
        puts(words[i]);
        free(words[i]);
        i++;
    }
    free(words);
    return (0);
}
```

Compile your program with the library **after** the source file:

```sh
cc -Wall -Wextra -Werror -I. main.c libft.a -o demo
./demo
```

```text
42
1337
libft
```

### Memory and input contracts

- Free results from `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, and `ft_strtrim` after use.
- For `ft_split`, free **each word**, then free the array. Its last entry is `NULL`.
- An empty split result is an allocated array containing only `NULL`.
- Standard-style string functions need valid, null-terminated inputs. Memory functions need valid areas for the requested byte count.
- `ft_memcpy` requires non-overlapping areas; use `ft_memmove` for overlapping copies.
- For `ft_strlcpy` and `ft_strlcat`, a return value greater than or equal to the supplied capacity indicates truncation or insufficient space.
- `ft_atoi` does not report parsing errors or overflow; numeric results must fit in an `int`.

## Tests

```sh
make test
```

The suite exercises **all 26 project functions**, including:

- Character boundaries and comparisons against the C library.
- Empty strings, null-character searches, and bounded buffers.
- 3,000 randomized memory rounds, including overlapping moves.
- Integer limits and 5,000 randomized decimal conversions.
- AddressSanitizer, UndefinedBehaviorSanitizer, and leak detection.
- Injected allocation failures, including failure at each allocation in `ft_split`.

Tests use temporary files under `/tmp` and remove them afterward. They need a compiler with sanitizer support and an environment that permits LeakSanitizer to inspect processes. Test harnesses live in [`tests/`](tests/) and are excluded from the library build.

Check the library sources with the [official 42 Norminette](https://github.com/42School/norminette):

```sh
norminette ft_*.c libft.h
```

The current library sources and header pass Norminette. Local checks are separate from the campus evaluation; use your assigned subject for the remaining project requirements.

---

<div align="center">

**Written to understand what happens behind the function call.**

[zakari-aee](https://github.com/zakari-aee) · 42 / 1337 · Libft

</div>
