#include "shell.h"

/**
 * build_full_path - function that creates full path
 * @head: first (head) node
 * @command: splited commands
 * Return: erturns full path
 */


char *build_full_path(directory_list *head, char *command)
{
	char *full_path = NULL;
	struct stat st;

	while (head)
	{
		char *dir_with_slash = _strcat(head->directory_path, "/");

		full_path = _strcat(dir_with_slash, command);
		free(dir_with_slash);

		if (stat(full_path, &st) == 0)
		{
			break;
		}
		free(full_path);
		head = head->next;
	}
	return (full_path);
}


/**
 * _which - is a function used to look for
 * files in the current path of the given
 * direcotry
 * @commands:user input arguments
 * @env:the environment variable which contains
 * direcotry files
 * Return: returns full path of command passed
 * or (NULL) if the comand passed doesn't exist
*/

char *_which(char **commands, char **env)
{
	directory_list *head = list_path(env);
	char *full_path = build_full_path(head, commands[0]);

	free_list(list_path(env));
	return (full_path);
}

