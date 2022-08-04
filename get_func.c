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
		continue;
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
	char *ptr;
	int x = 0, cargs = 0;
	char *token = NULL, *tok = NULL;

	ptr = strdup(buffer);
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
			free(tok);
			return (str);
		}
	}
	free(ptr);
	return (str);
}

/**
 * _which - returns file path.
 * @filename: file to look for.
 * Return: path.
 */
char *_which(char *filename, ...)
{
	int i, args = 0, counter = 0;
	struct stat st;
	char *token = NULL, *duplicate = NULL, *aux = NULL, *aux2 = NULL;
	char **saveMe;

	duplicate = _getenv("PATH"); /* obtain current path */
	args = repeatMe(duplicate, ':') + 2; /* num of sub paths + null */
	saveMe = malloc(args * sizeof(char *)); /* reserve space */
	if (saveMe == NULL)
		return (0);
	token = strtok(duplicate, ":"); /* tokenize */
	for (i = 0; token; i++)
	{
		saveMe[i] = _strdup(token);
		token = strtok(NULL, ":");
	}
	saveMe[i] = NULL; /* first pos + concat */
	for (i = 0; saveMe[i]; i++)
	{
		aux = _str_concat(saveMe[i], "/");
		aux2 = _str_concat(aux, filename);
		if (stat(aux2, &st) == 0)
		{
			break;
		}	/* sale del if cuando existe */
		else
			counter++; /* counts num of times file didn't exists */
		free(aux);
		free(aux2);
	}
	/* only need to free now */
	counter += 1; /* hardcode maybe */
	if (counter == args)
	{
		/*aux2 = "no";*/
		return (NULL);
	}
	/**for (i = 0; saveMe[i]; i++)
		free(saveMe[i]);
	free(saveMe);*/
	return (aux2);
}
/**
 * _getenv - gets env.
 * @name: name of envp.
 * Return: content of envp.
 */
char *_getenv(const char *name)
{
        int i;
        char *duplicate = NULL, *token = NULL;

        /* loop through envps */
        for (i = 0; environ[i]; i++)
        {
                duplicate = strdup(environ[i]);
                token = strtok(duplicate, "=");
                /* check for PATH */
                if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			return(token);
		}
	}
        return (0);
}
