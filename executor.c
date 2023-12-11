#include "shell.h"

/**
 * executor - Execute a command with arguments.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @index: The index where the command is located.
 *
 * Return: The exit status of the executed command.
 */

int executor(char **command, char **argv, int index)
{
	char *wholecmd = NULL;
	pid_t son;
	int status;

	wholecmd = pathfinder(command[0]);
	if (wholecmd == NULL)
	{
		error(argv[0], command[0], index);
		free2d(command);
		return (127);
	}
	son = fork();
	if (son == 0)
	{
		if (execve(wholecmd, command, environ) == -1)
		{
			free(wholecmd);
			free2d(command);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(son, &status, 0);
		free2d(command);
		free(wholecmd);
	}
	return (WEXITSTATUS(status));
}
