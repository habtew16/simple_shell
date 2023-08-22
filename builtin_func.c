#include "shell.h"
#include <ctype.h>
#include <string.h>

/**
 * builtin_exit - is function used to implement built
 * in exit with status code
 * @input_line: input line that contains commands
 * @commands: splited commands from input line
 * @exit_status: is the exit status code
 * @count: total count of input lines
*/


void builtin_exit(char *input_line, char **commands, int *exit_status,
		int count __attribute__((unused)))
{
	int num_value;

	num_value = 0;

	if (commands[1])
	{
		if (_is_positive(commands[1]) == 0)
		{
			num_value = _atoi(commands[1]);
			*exit_status = num_value;
		}
		else
		{
			write(STDOUT_FILENO, "./hsh: ", 7);
			write(STDOUT_FILENO, "1: ", 3);
			write(STDOUT_FILENO, "exit: Illegal number: ", 22);
			write(STDOUT_FILENO, commands[1], strlen(commands[1]));
			write(STDOUT_FILENO, "\n", 1);
			*exit_status = 2;
			free_loop(commands);
			return;
		}
	}

	free_loop(commands);
	free(input_line);
	exit(*exit_status);
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

