#include "shell.h"

/**
 * handle_cases - function to hanndle spetial cases like
 * EOF in interactive and non-interactive mode and \n entry
 * @line:strinng which contiainns standard input
 * @len: lenngth of the buffer of linne
 * @exit_st: exit status
 * Return: if the entry does not match any special case
 * expressed above then return 0 or else
 * if it is a match then return 3\n
*/



int handle_cases(char *line, ssize_t len, int *exit_st)
{
	int i = 0;

	if (len == -1)
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

