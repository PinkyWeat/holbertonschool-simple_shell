#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

int main(int argc, char **argv);

char *_getenv(const char *name);

char *_which(char *filename, ...);

char *_str_concat(char *s1, char *s2);

int repeatMe(char *str, char delim);

char **executeMe(char *buffer);

void printMe(char **print);

void freeMe(char **me);

int cleanBuf(char *buffer);

#endif
