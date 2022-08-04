#include "main.h"

/**
 * _getenv - gets env.
 * @name: name of envp.
 * Return: content of envp.
 */

char *_getenv(const char *name)
{
	int x, z, s;
	char *duplicate;

	for (x = 0; environ[x] != NULL; x++)
	{
		s = 1;
		for (z = 0; environ[x][z] != '='; z++)
		{
			if (name[z] != environ[x][z])
			{
				s = 0;
				break;
			}
		}
		if (s)
		{
			duplicate = strdup(&environ[x][z + 1]);
			return (duplicate);
		}
	}
	return (NULL);
}
