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

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Tested memory with:

	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh

---

### Example

Print a string:

       int x = 0;

       char *string = "Otaku";

       x = _printf("I'am am an%s, string);

       printf("%s, x);

       return (0);

Print an integer:

        int x = 0;

        int prints = 420;

        x = _printf("It's:%i", prints);

        printf("%i", x);

        return(0);
---
### File Description

****

---
### Flowcharts

![]()

![]()

![]()

---
### Authors

Written by [Denisse Landau](https://www.linkedin.com/in/denisse-l-5844a5140/ "Denisse Landau") and [Damian Caetano](https://www.linkedin.com/in/alexis-caetano-0b452b238/ "Damian Caetano")
