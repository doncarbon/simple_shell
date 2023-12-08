#include "shell.h"

char *pathfinder(char *cmd)
{
	struct stat sta;
	char *pathenv = NULL;
	char *wholecmd = NULL;
	char *folder = NULL;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if(stat(cmd, &sta) == 0)
				return (strdup(cmd));
			else
				return (NULL);
		}
	}
	pathenv = _getenv("PATH");
	if (pathenv == NULL)
		return (NULL);
	folder = strtok(pathenv, ":");
	while(folder)
	{
		wholecmd = malloc(strlen(folder) + strlen(cmd) + 2);
		if (!wholecmd)
			return(NULL);
		strcpy(wholecmd, folder);
		strcat(wholecmd, "/");
		strcat(wholecmd, cmd);
		if(stat(wholecmd, &sta) == 0)
		{
			free(pathenv);
			return(wholecmd);
		}
		free(wholecmd);
		folder = strtok(NULL, ":");
	}
	free(pathenv);
	return (NULL);
}
