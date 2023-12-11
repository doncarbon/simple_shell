#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @str: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(char *str)
{
	int i;
	char *tmp = NULL;
	char *cp = NULL;
	char *k = NULL;
	char *value = NULL;

	for (i = 0; environ[i]; i++)
	{
		tmp = strdup(environ[i]);
		k = strtok(tmp, "=");
		if (strcmp(k, str) == 0)
		{
			value = strtok(NULL, "\n");
			cp = strdup(value);
			free(tmp);
			return (cp);
		}
		free(tmp);
	}
	return (NULL);
}
