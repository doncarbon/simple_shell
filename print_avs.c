#include <stdio.h>
#include <stdlib.h>

/**
 * print_avs - prints all the arguments, without using ac
 * @av: NULL terminated array of strings
 * @ac: the number of items in av
 */
void main(int ac, char **av)
{
	(void)av;
	int count = 0;

	while (av[count] != NULL)
	{
		printf("%s\n", av[count]);
		count++;
	}
}

