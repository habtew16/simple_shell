#include "shell.h"

/**
*special_case - function that handle special cases such as:
*EOF in interactive and non-interactive mode and \n entry
*@line: buffer that stores the stdin input
*@line_len: line length
*@exit_st: exit status
*Return: 0 if the entry does not match any special case
*or 3 if it is a \n
*/



int special_case(char *line, ssize_t line_len, int *exit_st)
{
	int i = 0;

	if (line_len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(line);
		exit(*exit_st);
	}

	if (_strcmp(line, "\n") == 0)
	{
		*exit_st = 0;
		return (3);
	}

	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}

	if (line[i] == '\0')
	{
		*exit_st = 0;
		return (0);
	}

	if (line[0] == '/')
	{
		*exit_st = 0;
		return (0);
	}

	return (0);
}

