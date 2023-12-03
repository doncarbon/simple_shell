#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-al", "/simple_shell", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		printf("Error");
	}
	return (0);
}
