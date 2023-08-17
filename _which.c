#include "shell.h"
/**
*_which - fuction that looks for files in the current PATH.
*@commands:the split arguments
*@env: environment variables.
*Return: full_path of the command or NULL if it can´t find it
*/

char *_which(char **commands, char **env)
{
	directory_list *head = list_path(env);
	char *full_path = NULL;
	struct stat st;

	while (head)
	{
		char *dir_with_slash = _strcat(head->directory_path, "/");

		full_path = _strcat(dir_with_slash, commands[0]);
		free(dir_with_slash);

		if (stat(full_path, &st) == 0)
		{
			break;
		}

		free(full_path);
		head = head->next;
	}

	free_list(list_path(env));
	return (full_path);
}

