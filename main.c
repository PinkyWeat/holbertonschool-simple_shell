#include "main.h"
/**
 *
 */
int main(__attribute__((unused))int argc ,__attribute__((unused))char **argv)
{
        size_t bufsize = 0;
        char *buffer = NULL, *buffer2 = NULL, **location = NULL;
        char *token = NULL, *hint = "no";
        int character = 0, interactMe = 1;
        int pid = 0, status;

        while (interactMe)
        {
                interactMe = isatty(0); /* check for interactive mode */
                if (interactMe)
                        write(1, "$ ", 2);
                /* printf("#cisfun$ "); */
                character = getline(&buffer, &bufsize, stdin);
                if (character == -1)
                {
                        putchar(10);
                        break;
                }
                /* dup cmd line + save only what was first written */
                buffer2 = strdup(buffer);
                token = strtok(buffer2, "\n");
                /* creates child proc for execve */
                location = executeMe(token);
                if (strcmp(location[0], hint) == 0) /* hardcode */
                        continue;
                pid = fork();
                if (pid == -1)
                        return (-1);
                if (pid == 0)
                {
                        /* free(buffer), free(buffer2), free(location); */
                        if (execve(location[0], location, environ) == -1)
                        {
				perror(" "); /* logrado aca ejecuta y se termina */
				return (0);
			}
                }
                else
			wait(&status);
                free_array(location), free(buffer2);
        }
	free(buffer);
        return (0);
}
