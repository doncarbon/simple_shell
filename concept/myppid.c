#include <stdio.h>
#include <unistd.h>

/**
 * main - check for code
 *
 * Return: Always success (0)
 */
int main(void)
{
	pid_t my_ppid = getppid();

	printf("%d\n", my_ppid);
	return (0);
}
