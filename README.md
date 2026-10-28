*This project has been created as part of the 42 curriculum by zallioua.*

# Libft

## Description

Libft is my first C library. I rebuilt functions from the standard C library to see how they really work, and linked list functions that I'll reuse in my next 42 projects. It compiles into `libft.a`.

## Instructions

```sh
make          # build libft.a
make clean    # remove the .o files
make fclean   # remove the .o files and libft.a
make re       # rebuild everything
```

To use it:

```c
#include "libft.h"
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft
```

## Library description

`libft.a` is a static library made with `ar`. When a program is linked with it, only the functions it needs are copied in. All the prototypes are in `libft.h`.

It has three parts:

- **Libc functions** — my versions of standard functions, same behavior, with the `ft_` prefix.
- **Additional functions** — string, conversion and output functions.
- **Linked lists** — functions for the `t_list` structure.

A few choices I made:

- The libc functions act like the originals, even on `NULL`.
- `ft_memmove` picks the copy direction so overlapping memory works.
- `ft_calloc` returns a freeable pointer for a size of `0`, and `NULL` on overflow.
- `ft_atoi`, `ft_itoa` and `ft_putnbr_fd` handle `INT_MIN`.
- `ft_split` and `ft_lstmap` free everything if an allocation fails.

## Functions

### Part 1 - Libc functions

| Function | What it does |
|---|---|
| `ft_isalpha` | checks for a letter |
| `ft_isdigit` | checks for a digit |
| `ft_isalnum` | checks for a letter or digit |
| `ft_isascii` | checks for an ASCII value |
| `ft_isprint` | checks for a printable character |
| `ft_toupper` | lowercase to uppercase |
| `ft_tolower` | uppercase to lowercase |
| `ft_strlen` | length of a string |
| `ft_strlcpy` | copies a string with a size limit |
| `ft_strlcat` | appends a string with a size limit |
| `ft_strchr` | first occurrence of a character |
| `ft_strrchr` | last occurrence of a character |
| `ft_strncmp` | compares two strings up to `n` chars |
| `ft_strnstr` | finds a substring in the first `len` chars |
| `ft_strdup` | new copy of a string |
| `ft_memset` | fills memory with a byte |
| `ft_bzero` | fills memory with zeros |
| `ft_memcpy` | copies memory |
| `ft_memmove` | copies memory, even if it overlaps |
| `ft_memchr` | finds a byte in memory |
| `ft_memcmp` | compares memory |
| `ft_calloc` | allocates zeroed memory |
| `ft_atoi` | string to `int` |

### Part 2 - Additional functions

| Function | What it does |
|---|---|
| `ft_substr` | part of a string |
| `ft_strjoin` | joins two strings |
| `ft_strtrim` | removes chars from both ends |
| `ft_split` | splits a string into an array |
| `ft_itoa` | `int` to string |
| `ft_strmapi` | new string from a function on each char |
| `ft_striteri` | applies a function on each char |
| `ft_putchar_fd` | writes a char to an fd |
| `ft_putstr_fd` | writes a string to an fd |
| `ft_putendl_fd` | writes a string and a newline to an fd |
| `ft_putnbr_fd` | writes a number to an fd |

### Part 3 - Linked lists

| Function | What it does |
|---|---|
| `ft_lstnew` | creates a node |
| `ft_lstadd_front` | adds a node at the start |
| `ft_lstadd_back` | adds a node at the end |
| `ft_lstsize` | counts the nodes |
| `ft_lstlast` | returns the last node |
| `ft_lstdelone` | frees one node |
| `ft_lstclear` | frees the whole list |
| `ft_lstiter` | applies a function to each node |
| `ft_lstmap` | makes a new list from a function |

## Resources

- `man` pages, section 3
- The 42 Norm
- W3Schools, Stack Overflow, GeeksforGeeks and Google, for C concepts and examples
- YouTube, for visual and deeper explanations
- AI, to explore subjects in more depth.