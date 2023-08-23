#include "shell.h"

/**
 * split_line - Splits the input line into individual command strings.
 *
 * This function takes an input line and tokenizes it into an array of
 * command strings, where each command is a separate element in the array.
 *
 * @line: The input buffer containing the command line.
 *
 * Return: A double pointer array containing pointers to individual
 * command strings extracted from the input line.
 *
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

