#include "shell.h"
#include <ctype.h>
#include <string.h>

/**
 * builtin_exit - function that implement the exit builtin
 * @line: the buffer
 * @commands: the split arguments
 * @exit_st: the exit status
 * @count: count of lines
*/


void builtin_exit(char *line, char **commands, int *exit_st,
		int count __attribute__((unused)))
{
	int num = 0;

	if (commands[1])
	{
		if (_is_positive(commands[1]) == 0)
		{
			num = _atoi(commands[1]);
			*exit_st = num;
		}
		else
		{
			write(STDOUT_FILENO, "./hsh: ", 7);
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "exit: Illegal number: ", 22);
			write(STDOUT_FILENO, commands[1], strlen(commands[1]));
			write(STDOUT_FILENO, "\n", 1);
			*exit_st = 2;
			free_loop(commands);
			return;
		}
	}

	free_loop(commands);
	free(line);
	exit(*exit_st);
}


/**
 * builtin_env - function to apply env builtin
 * @commands: list of strings split arguments
 * @env: environment
 * @exit_st: exit status
*/


void builtin_env(char **commands, char **env, int *exit_st)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}

	*exit_st = 0;
	free_loop(commands);
}

