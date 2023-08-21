#include "shell.h"

/**
 * _getenv - function used to get the env
 * variable
 * @name: is the name of the given environment
 * @env: environment from where the variable is
 * going to be get
 * Return: returns the value of name
 */


char *_getenv(const char *name, char **env)
{
	char *comp = NULL;
	int i;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		comp = strtok(env[i], "=");
		if (strcmp(comp, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
	}
	return (NULL);
}

