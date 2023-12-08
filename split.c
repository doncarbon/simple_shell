#include "shell.h"

/**
 * split - Split a string into an array of tokens.
 * @input: The string to be split.
 *
 * Return: An array of tokens, or NULL on failure.
 */
char **split(char *input)
{
	char *token = NULL, *tmp = NULL;
	char **array;
	int count = 0;
	int i = 0;

	if (!input)
		return (NULL);
	tmp = strdup(input);
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(input);
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
	{
		free(input);
		return (NULL);
	}

	token = strtok(input, " \t\n");
	while (token)
	{
		array[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(input);
	array[i] = NULL;

	return (array);
}
