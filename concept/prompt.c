#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t line;

	printf("$ ");
	line = getline(&command, &len, stdin);
	if (line == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	printf("\n%s", command);
	command[len - 1] = '\0';

	return (0);
}
