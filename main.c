#include "main.h"
/**
 *
 */
int main(__attribute__((unused))int argc ,__attribute__((unused))char **argv)
{
        size_t bufsize = 0;
        char *buffer = NULL, *buffer2 = NULL, **location = NULL;
	char *token = NULL, *hint = "no";
        int character = 0;
	int pid = 0, status;

	while (1)
	{
		/* printf("#cisfun$ "); */
        	character = getline(&buffer, &bufsize, stdin);
		if (character == -1)
		{
			putchar(10);
			exit(EXIT_SUCCESS);
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
				perror("Error: "); /* logrado aca ejecuta y se termina */
		}
		wait(&status);
		/* free(buffer), free(buffer2); */
	}
	return (0); 
}
