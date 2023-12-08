#include "shell.h"

int executor(char **command, char **argv)
{
	pid_t son;
	int status;

	son = fork();
	if (son == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			free2d(command);
			exit(100);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(son, &status, 0);
		free2d(command);
	}
	return(WEXITSTATUS(status));
}
