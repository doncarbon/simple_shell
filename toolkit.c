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
void error(char *shell, char *cmd, int index)
{
	fprintf(stderr, "%s: %i: %s: not found\n", shell, index, cmd);
}
