#include "main.h"

void free_array(char **array)
{
	int i = 0;

	for (; array[i]; i++)
	{
		free(array[i]);
	}

	free(array[i]);
	free(array);
}

