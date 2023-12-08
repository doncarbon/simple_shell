#include "shell.h"

void free2d(char **array)
{
	int i;
	if (!array)
		return;
	for(i = 0; array[i]; i++)
		free(array[i]), array[i] = NULL;

	free(array), array = NULL;
}
