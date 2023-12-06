#include "shell.h"

/**
 * prompt - display a $ to get the command input.
 *
 * Return: command buffer string.
 */
char *prompt()
{
	char *buffer = NULL;
	size_t buffer_len = 0;
	int line;

	write(1, "$ ",2);
	line = getline(&buffer, &buffer_len, stdin);

	if (line == EOF)
	{
		perror("EOF");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	
	if (line == 0 || (strcmp(buffer, "exit") == 0))
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
