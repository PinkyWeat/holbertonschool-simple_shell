#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * str_concat - function that concatenates two strings..
 * @s1: ctrl + c.
 * @s2: ctrl + v.
 * Return: final pointer.
 */
char *_str_concat(char *s1, char *s2)
{
	char *conc;
	int p1, p2 = 0, len; /* p1: paste 1, p2: paste 2 */

	if (s1 != NULL && s2 == NULL)
		len = strlen(s1);
	if (s1 == NULL && s2 != NULL)
		len = strlen(s2);
	if (s1 != NULL && s2 != NULL)
		len = (strlen(s1) + strlen(s2));
	/* Above: in case s1 or s2 have null value */
	len += 1; /* For the '\0' */
	conc = malloc(len);
	if (conc == NULL)
		return (NULL);
	/* Above: checking string with malloc */
	if (s1 != NULL)
	{
		for (p1 = 0; s1[p1]; p1++)
		{
			conc[p2] = s1[p1];
			p2++;
		}
	}
	if (s2 != NULL)
	{
		for (p1 = 0; s2[p1]; p1++)
		{
			conc[p2] = s2[p1];
			p2++;
		}
	}
	conc[p2] = '\0';
	return (conc);
}

/**
* _strdup - return a pointer to a newly allocated space in memory.
* @str: array to copy
* Return: pointer
*/

char *_strdup(char *str)
{
	char *pointer;
	int size, x;

	if (str == NULL)
	{
		return (NULL);
	}
	size = strlen(str);
	pointer = (char *)malloc((size + 1) * sizeof(char));

	if (pointer == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		pointer[x] = str[x];
	}
	return (pointer);
}
