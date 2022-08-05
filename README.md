# C - Simple Shell

### Description

Project consists on creating a clone of a Unix shell, a command-line interpreter of shell that provides a command line user interface for Unix-like operating systems.

The shell is both an interactive and scripting languge.
---

### Requirements

- All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options **``-Wall -Werror -Wextra -pedantic -std=gnu89``**
- Code uses the Betty style.
- Shell does not have any memory leaks, tested with Valgrind.
- No more that 5 functions per file.
- All prototypes of all functions are included in header file ``main.h``.
---

### Compilation & Testing

We compile with:

	gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Tested memory with:

	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh

---

### Example

---
### File Description

**main.c** - contains main() function which is first called by the operating system when the user runs the program.

**main.h** - file contains the main header with all the prototypes  of the functions and libraries used.

**get_func.c** - file contains the following functions:
> ``repeatMe`` -  function counts number of repeated times a char appears in a string.
> ``executeMe`` - function takes a string and tokenizes it into a ``**char``
> ``printMe`` - function prints a ``**char``, was used for an easier debugging.
> ``_which`` - function returns the path of a given file.
> ``_getenv`` - function gets the value of the enviromental variable given.

**funcs_aux.c** - file contains more auxiliary functions:
> ``_str_concat`` - function concatenates two strings.
> ``freeMe`` - function frees memory for a ``**char``

**hsh** - shell interpreter executable file.

---

### Flowcharts

![]()

![]()

![]()

---
### Authors

Written by [Denisse Landau](https://www.linkedin.com/in/denisse-l-5844a5140/ "Denisse Landau") and [Damian Caetano](https://www.linkedin.com/in/alexis-caetano-0b452b238/ "Damian Caetano")
