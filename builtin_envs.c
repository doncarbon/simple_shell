#include "shell.h"

/**
 * setenv_builtin - Implement the setenv built-in.
 * @command: The array containing the command and its arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int setenv_builtin(char **command)
{
	if (command[1] == NULL || command[2] == NULL)
		return (-1);
	if (setenv(command[1], command[2], 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unsetenv_builtin - Implement the unsetenv built-in.
 * @command: The array containing the command and its arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int unsetenv_builtin(char **command)
{
	if (command[1] == NULL)
		return (-1);
	if (unsetenv(command[1]) == -1)
	{
		perror("unsetnv");
		return (-1);
	}
	
	return (0);
}
