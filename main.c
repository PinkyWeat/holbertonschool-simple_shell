#include "main.h"
/**
 *
 */
int main(__attribute__((unused))int argc ,__attribute__((unused))char **argv)
{
        size_t bufsize = 0;
        char *buffer = NULL, **location = NULL;
	char *token = NULL, *hint = "no";
        int interactMe = 1;
	int pid = 0, status;

	while (interactMe)
	{
		interactMe = isatty(0);	/*check for interactive mode*/
		if (interactMe)
			write(1, "$ ", 2);

        	if (getline(&buffer, &bufsize, stdin) == -1)
		{
			putchar(10);
			break;
		}
        	/*dup cmd line + save only what was first written*/
		token = strtok(buffer, "\n");
		/*creates child proc for execve*/		
		location = executeMe(token);
		if (strcmp(location[0], "exit") == 0)
		{
			return(0);
		}
		if (strcmp(location[0], "env") == 0)
		{
			printf("%s\n", *environ);
			continue;
		}
		if (strcmp(location[0], hint) == 0) /* hardcode */
		{
			continue;
		}
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			if (execve(location[0], location, environ) == -1)
			{
				perror(" "); /* logrado aca ejecuta y se termina */
				return(0);
			}
		}
		else
			wait(&status);
		/**for (x = 0; location[x]; x++)
			free(location[x]);
		free(buffer), free(buffer2), free(location);*/
	}
	return (0); 
}
