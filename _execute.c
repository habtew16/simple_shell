#include "shell.h"

/**
* execute_line - function to get input from user and execute
* it by using appropriate commannds
* @argv: list of argumennts passed by user
* @commands: executable commands
* @count: count of the commands passed
* @env: environment is collection of strings
* @exit_st: is exit status
* @line: input line that is used to get inpt
* from user
*/

void execute_line(char **argv, char **commands, int count,
	char **env, int *exit_st, char *line)
{
	pid_t pid;
	int status;
	char *full_path = NULL;

	(void)line;

	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return;
	}

	if (pid == 0)
	{
		full_path = commands[0];

		if (**commands != '/' && _strcmp(commands[0], "..") != 0)
		{
			full_path = _which(commands, env);
		}

		if (full_path && access(full_path, X_OK) == 0)
		{
			execve(full_path, commands, env);
		}

		_error(argv, commands[0], count, &exit_st);
		free_loop(commands);
		free(line);
		exit(*exit_st);
	}
	else
	{
		wait(&status);
		free_loop(commands);
		*exit_st = WEXITSTATUS(status);
	}
}

