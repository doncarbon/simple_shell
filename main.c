#include "shell.h"

/**
 * main - Entry point for the simple shell.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
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
		if (strcmp(command[0], "cd") == 0)
			status = change_dir(command);
		else if (strcmp(command[0], "setenv") == 0)
			status = setenv_builtin(command);
		else if (strcmp(command[0], "unsetenv") == 0)
			status = unsetenv_builtin(command);
		else
			status = executor(command, argv, index);
	}
	free(line);
}
