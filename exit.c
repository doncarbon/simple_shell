#include "shell.h"

/**
 * builtin_exit - Handle the built-in exit command with arguments.
 * @command: An array of strings representing the command and its arguments.
 *
 * Return: The exit status to be used to exit the shell.
 */
int builtin_exit(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		status = 0;
	}
	else
	{
		status = atoi(command[1]);
	}

	free2d(command);
	exit(status);

	return (status);
}
