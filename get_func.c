#include "main.h"
/**
 * repeatMe - counts num of repeated times a char is in a string.
 * @str: string we will loop through.
 * @delim: the char we want to count.
 * Return: num of repeated times delim is in string.
 */
int repeatMe(char *str, char delim)
{
	int i, len = strlen(str), count = 0;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == delim)
			count++;
	}
	return (count);
}
/**
 * executeMe - takes a string and turns it to a **char to be executed.
 * @buffer: string to be tokenized.
 * Return: string of strings.
 */
char **executeMe(char *buffer)
{
	char **str = NULL;
	char *ptr = strdup(buffer), *token = NULL, *tok = NULL;
	int x = 0, cargs = 0;

	cargs = repeatMe(buffer, ' ') + 2; /* counts spaces + NULL */
	str = malloc(cargs * sizeof(char *)); /* allocate memory accordingly */
	token = strtok(ptr, " ");
	for (x = 0; token; x++)
	{
		str[x] = strdup(token);
		token = strtok(NULL, " ");
	}
	str[x] = NULL;
	if (repeatMe(str[0], '/') == 0)
	{
		tok = strdup(str[0]);
		free(str[0]);
		str[0] = _which(tok);
		if (str[0] == NULL)
		{
			free(str[0]);
			str[0] = "no";
			free(ptr), free(tok);
			return (str);
		}
	}
	free(tok), free(ptr);
	return (str);
}
/**
 * printMe - Prints a **string.
 * @print: what to print.
 */
void printMe(char **print)
{
	int x = 0;

	for (x = 0; print[x]; x++)
		printf("%s\n", print[x]);
}
/**
 * _which - returns file path.
 * @filename: file to look for.
 * Return: path.
 */
char *_which(char *filename, ...)
{
	char *token = NULL, *duplicate = NULL, *aux = NULL, *aux2 = NULL;
	char **saveMe; /*= malloc(sizeof(char *) * 7);*/
	int i, args = 0, counter = 0;
	struct stat st;

	duplicate = _getenv("PATH"); /* obtain current path */
	args = repeatMe(duplicate, ':') + 2; /* num of sub paths + null */
	saveMe = malloc(args * sizeof(char *)); /* reserve space */
	if (saveMe == NULL)
		return ("error");
	token = strtok(duplicate, ":"); /* tokenize */
	for (i = 0; token; i++)
	{
		saveMe[i] = strdup(token);
		token = strtok(NULL, ":");
	}
	saveMe[i] = NULL; /* last marker */
	free(duplicate);
	for (i = 0; saveMe[i]; i++)
	{
		aux = _str_concat(saveMe[i], "/");
		aux2 = _str_concat(aux, filename);
		if (stat(aux2, &st) == 0)
		{
			free(aux);
			break; /* leaves when exists */
		}
		else
			counter++; /* counts num of times file didn't exists */
		free(aux), free(aux2);
	}
	freeMe(saveMe); /* only need to free now */
	counter += 1; /* hardcode maybe */
	if (counter == args)
	{
		aux2 = "no";
		return (NULL);
	}
	return (aux2);
}
/**
 * _getenv - gets env.
 * @name: name of envp.
 * Return: content of envp.
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *duplicate = NULL, *token = NULL, *aux = NULL;

	for (; environ[i]; i++) /* loop through envps */
	{
		duplicate = strdup(environ[i]);
		token = strtok(duplicate, "=");
		if (strcmp(duplicate, name) == 0) /* checks name of envp */
		{
			token = strtok(NULL, "=");
			aux = strdup(token);
			free(duplicate);
			return (aux);
		}
		free(duplicate);
	}
	return (0);
}
