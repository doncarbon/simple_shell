#include "shell.h"

char *_getenv(char *str)
{
	int i;
	char *tmp;
	char *cp;
	char *k;
	char *value;

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
	return(NULL);
}
