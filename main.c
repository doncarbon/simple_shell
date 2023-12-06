#include "shell.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success) 1 (Failure)
 */
int main()
{
	char **command = NULL;
	int status = 0;
	pid_t pid;

	while (1)
	{
		command = split(prompt());
		pid = fork();
		if (pid == 0)
		{
			if (execve(command[0], command, NULL) == -1)
			{
				perror("execve");
				free(command);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else if (pid > 0)
			wait(&status);
		else
		{
			perror("fork");
			free(command);
			exit(EXIT_FAILURE);
		}
		free(command);
	}
	return (0);
}
