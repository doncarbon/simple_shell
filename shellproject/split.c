#include "shell.h"

/**
 * split - splits command to tokens
 * @input: command to split
 *
 * Return: array of tokens
 */
char **split(char *input)
{
	char *token;
	char **array;
	int i;

	token = strtok(input, " \t\n");
	array = malloc(sizeof(char *) * MAX_INPUT_LENGTH);
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}

	array[i] = NULL;

	return (array);
}
