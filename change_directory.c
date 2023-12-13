#include "shell.h"

/**
 * change_dir - Implement the cd built-in command.
 * @path: The directory path to change to.
 *
 * Return: 0 on success, -1 on failure.
 */
int change_dir(char **path)
{
	char *new_dir = NULL;
	char *current_dir = getcwd(NULL, 0);

	if (!path[1] || strcmp(path[1], "~") == 0)
		new_dir = _getenv("HOME");
	else if (strcmp(path[1], "-") == 0)
		new_dir = _getenv("OLDPWD");
	else
		new_dir = path[1];
	if (!new_dir)
		return (-1);
	if (chdir(new_dir) == -1)
	{
		perror("cd");
		return (-1);
	}
	if (!current_dir || setenv("PWD", current_dir, 1) == -1)
	{
		perror("cd");
		free(current_dir);
		return (-1);
	}
	if (setenv("OLDPWD", new_dir, 1) == -1)
	{
		perror("cd");
		free(current_dir);
		return (-1);
	}
	free(current_dir);
	return (0);
}
