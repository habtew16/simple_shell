#include "shell.h"
/**
*split_line - creates a double pointer array that holders pointers
*to each string from the command line
*@line: buffer that stores the stdin input
*Return: double pointer array of pointers that are commands to interpret
*and execute
*/
char **split_line(char *line)
{
	int i, len;
	char *token;
	char *_hash;
	char **words;

	i = 0;
	len = _strlen(line);

	words = malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);
	_hash = strtok(line, "#");
	token = strtok(_hash, del);
	while (token != NULL)
	{
		words[i] = malloc(_strlen(token) + 1);
		if (words[i] == NULL)
		{
			free_loop(words);
			return (NULL);
		}
		_strncpy(words[i], token, _strlen(token) + 1);
		token = strtok(NULL, del);
		i++;
	}
	words[i] = NULL;
	return (words);
}

