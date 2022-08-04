#include "main.h"
/**
 *
 */
int main(__attribute__((unused))int argc ,__attribute__((unused))char **argv)
{
	size_t bufsize = 0, h = 0, r;
	char *buffer = NULL, **location = NULL;
	char *token = NULL, *hint = "no";
	int interactMe = 1, status;

	while (1)
	{
		interactMe = isatty(0); /* check for interactive mode */
		if (interactMe)
			write(1, "$ ", 2);
		if (getline(&buffer, &bufsize, stdin) == -1)
			break;
		/* dup cmd line + save only what was first written */
		/**buffer2 = strdup(buffer);*/
		token = strtok(buffer, "\n");
		if (strcmp(token, "exit") == 0)
		{
			/**free(buffer2);*/
			free(buffer);
			return(h);
		}
		if (strcmp(token, "env") == 0)
		{
			for (r = 0; environ[r] != NULL; r++)
			{
				printf("%s\n", environ[r]);
			}
			continue;
		}
		/* creates child proc for execve */
		location = executeMe(token);
		if (!location[0])
		{
			free(location[0]);
			free(buffer);
			return (0);
		}
		if (strcmp(location[0], hint) == 0)  /**hardcode*/
			continue;
		if (fork() == 0)
		{
			if (execve(location[0], location, environ) == -1)
			{
				perror(" "); /* logrado aca ejecuta y se termina */
				return (0);
			}
		}
		else
			wait(&status);
		free_array(location); /**free(buffer2);*/
	}
	free(buffer);
	return (0);
}
