#include "shell.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success) 1 (Failure)
 */
int main(int argc, char **argv)
{
	char **command = NULL;
	char *line = NULL;
	int status = 0, index = 0;
	(void) argc;

	while (1)
	{
		line = prompt();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			free(line), line = NULL;
			return (status);
		}
		index++;
		command = split(line);
		if (!command)
			continue;
		status = executor(command, argv, index);
	}
}
