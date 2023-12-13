#include "shell.h"

/**
 * builtin_exit - Handle the built-in exit command with arguments.
 * @command: An array of strings representing the command and its arguments.
 *
 * Return: The exit status to be used to exit the shell.
 */
int builtin_exit(char *command)
{
	int exit_status = 127;

	if (command != NULL)
	{
		exit_status = atoi(command);
		if (exit_status == 0 && command[0] != '0')
		{
			return (0);
		}
	}

	return (exit_status);
}
