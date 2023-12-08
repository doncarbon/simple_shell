#include "shell.h"

/**
 * free2d - Free memory allocated for a two-dimensional array of strings.
 * @array: The array to be freed.
 *
 * This function frees the memory allocated for a two-dimensional array
 * of strings and sets the array to NULL to avoid dangling pointers.
 */
void free2d(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]), array[i] = NULL;

	free(array), array = NULL;
}


/**
 * error - Print an error message to stderr.
 * @shell: The name of the shell program.
 * @cmd: The command causing the error.
 * @index: The index where the error occurred.
 *
 * This function prints an error message to stderr indicating that
 * the specified command was not found.
 */
void error(char *shell, char *cmd, int index)
{
	fprintf(stderr, "%s: %i: %s: not found\n", shell, index, cmd);
}
