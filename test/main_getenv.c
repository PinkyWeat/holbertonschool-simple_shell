#include "main.h"


int main(void)
{

	printf("PATH: %s\n\n", _getenv("PATH"));
	printf("HOME: %s\n\n", _getenv("HOME"));
	printf("ROOT: %s\n\n", _getenv("ROOT"));
	printf("PATH: %s\n", getenv("PATH"));
	printf("HOME: %s\n", getenv("HOME"));
	printf("ROOT: %s\n", getenv("ROOT"));
	return (0);
}
