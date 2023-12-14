#include "shell.h"

/**
 * prompt - Display a shell prompt and get user input.
 *
 * Return: command buffer string.
 */
char *prompt(void)
{
	char *buffer = NULL;
	size_t buffer_len = 0;
	ssize_t line;

	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
	line = getline(&buffer, &buffer_len, stdin);

	if (line == -1)
	{
		if(feof(stdin))
		{
			free(buffer);
			return (NULL);
		}
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (buffer);
}
