#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <strings.h>
#include <stdlib.h>

int main()
{
	char *command = NULL;
	char **array;
	size_t cmd_size = 0;
	pid_t pid;
	int i = 0, status;
	char *token = NULL;
	ssize_t line;

	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&command, &cmd_size, stdin);
		array = malloc(sizeof(char *) * 1024);
		token = strtok(command, " \t\n");
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		array[i] = NULL;
		pid = fork();
		if (pid = 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("execve");
		}
		else
			wait(&status);
		i = 0;
		free(array);
	}
}
