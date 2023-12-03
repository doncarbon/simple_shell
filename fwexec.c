#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i = 0, status;
	pid_t childpids;

	while (i < 5)
	{
		childpids = fork();
		if (childpids == -1)
			return (1);
		if (childpids == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				return (1);
			childpids = fork();
			sleep(3);
		}
		else
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
