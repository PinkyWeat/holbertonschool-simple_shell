#include "main.h"

int main()
{
	char *full_path = NULL;

	full_path = _which("pwd");

	printf("Path: %s\n", full_path);
	free(full_path);
	return (0);
}
