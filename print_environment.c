#include "shell.h"

/**
 * print_environment - Prints the current environment.
 *
 * Return: VOID.
 */
void print_environment(void)
{
	int i;
	
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
