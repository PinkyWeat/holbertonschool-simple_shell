#include "main.h"
/**
 *
 */
int main(__attribute__((unused))int argc ,__attribute__((unused))char **argv)
{
        size_t bufsize = 0;
        char *buffer = NULL, *buffer2 = NULL, **location = NULL;
	char *token = NULL, *hint = "no";
        int interactMe = 1;
	int pid = 0, status, x;

	while (interactMe)
	{
		interactMe = isatty(0);	/*check for interactive mode*/
		if (interactMe)
			write(1, "$ ", 2);

        	if (getline(&buffer, &bufsize, stdin) == -1)
		{
			break;
		}
        	/*dup cmd line + save only what was first written*/
		buffer2 = strdup(buffer);
		token = strtok(buffer, " \n");
		/*creates child proc for execve*/		
		location = executeMe(token);
		
		if (strcmp(location[0], "exit") == 0)
		{
			free(buffer2);
			return(0);
		}
		if (strcmp(location[0], "env") == 0)
		{
			printf("%s\n", *environ);
			free(buffer);
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
				perror("Error: "); /* logrado aca ejecuta y se termina */
		}
		else
			wait(&status);
		for (x = 0; location[x]; x++)
			free(location[x]);
		free(buffer), free(buffer2), free(location);
	}
	return (0); 
}
