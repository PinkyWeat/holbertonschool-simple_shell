#include "main.h"
/**
 *
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
 */
char **executeMe(char *buffer)
{
	char **str = NULL;
	char *ptr = strdup(buffer);
	int x = 0, cargs = 0;
	char *token = NULL, *tok = NULL;

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
	}
	return (str);
}
/**
 *
 */
void printMe(char **print)
{
        int x = 0;

        for (x = 0; print[x]; x++)
        {
                printf("print[%i]: %s\n", x, print[x]);
        }
}
/**
 * _which - returns file path.
 */
char *_which(char *filename, ...)
{
	int i, args = 0;
	struct stat st;
	char *token = NULL, *duplicate = NULL, *aux = NULL, *aux2 = NULL;
	char **saveMe; /*= malloc(sizeof(char *) * 7);i*/

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
	saveMe[i] = NULL; /* first pos + concat */
	for (i = 0; i < 7; i++)
	{
		aux = _str_concat(saveMe[i], "/");
		aux2 = _str_concat(aux, filename);
		if (stat(aux2, &st) == 0)
			break; /* sale del if cuando existe */
		free(aux);
		free(aux2);
	}
	/* only need to free now */
	for (i = 0; saveMe[i]; i++)
		free(saveMe[i]);
	/* free(saveMe[i]), free(saveMe), free(duplicate); */
	return (aux2);
}
/**
 * _getenv - gets env.
 */
char *_getenv(const char *name)
{
        int i = 0;
        char *duplicate, *token;

        /* loop through envps */
        for (; environ; i++)
        {
               /* printf("envp looks: %s\n", environ[i]); */

                duplicate = strdup(environ[i]);
                /* printf("duplicate of envp: %s\n", duplicate); */

                token = strtok(duplicate, "=");
                /*printf("token before if: %s\n", token); */
                /* check for PATH */
                if (strcmp(duplicate, name) == 0)
                {
                        token = strtok(NULL, "=");
                        /*printf("token after strcmp + strtok: %s\n", token); */
                        return(token);
                }
                else
                        continue;
        }
        printf("for is done\n");
        return (0);
}
