#include "shell.h"

int executor(char **command, char **argv, int index)
{
	char *wholecmd;
	pid_t son;
	int status;

	wholecmd = pathfinder(command[0]);
	if(wholecmd == NULL)
	{
		error(argv[0], command[0], index);
		free2d(command);
		return(127);
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
	return(WEXITSTATUS(status));
}
