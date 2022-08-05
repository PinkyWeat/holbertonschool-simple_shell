#include "main.h"
/**
 * main - entry point.
 * @argc: num of args.
 * @argv: pointer to pointer to a string.
 * Return: 0 upon success.
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	size_t bufsize = 0;
	char *buffer = NULL, **location = NULL;
	char *token = NULL, *hint = "no";
	int status = 0, exit_end = 0;

	while (1)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 2);
		if (getline(&buffer, &bufsize, stdin) == -1)
			break;
		token = strtok(buffer, "\n"); /* save only before \n */
		if (strcmp(token, "exit") == 0)
			break;
		if (strcmp(token, "env") == 0) /* prints envps */
		{
			printMe(environ);
			continue;
		}
		location = executeMe(token); /* finds complete root for execve */
		if (!location[0])
		{
			free(location[0]), free(buffer);
			return (0);
		}
		if (strcmp(location[0], hint) == 0)  /** path not found for cmd **/
			continue;
		if (fork() == 0)
		{
			if (execve(location[0], location, environ) == -1)
			{
				perror(" ");
				return (0);
			}
		}
		else
		{
			wait(&status);
			exit_end = WEXITSTATUS(status);
		}
		freeMe(location); /**free(buffer2);*/
	}
	free(buffer);
	return (exit_end);
}
