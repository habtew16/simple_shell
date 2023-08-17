#include "shell.h"

/**
* main - entry function to execute shell program
* @argc: the number of arguents passed to shell program
* @argv: total lists of arguments separated by comma
* @env: envarionment that is lists of strings
* Return: always return 0
*/

int main(int argc, char **argv, char **env)
{
	int special_case_result;
	char **commands;

	char *input_line = NULL;
	size_t bufsize = 0;
	ssize_t line_len = 0, count = 0;
	int exit_st = 0;

	(void)argc;
	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "($) ", 4);
		signal(SIGINT, SIG_IGN);
		line_len = getline(&input_line, &bufsize, stdin);
		if (line_len > 0 && input_line[line_len - 1] == '\n')
			input_line[line_len - 1] = '\0';
		if (line_len == 0 || (line_len == 1 && input_line[0] == '\0'))
			continue;
		count++;
		special_case_result = special_case(input_line, line_len, &exit_st);
		if (special_case_result == 3)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "($) ", 4);
			continue;
		}
		commands = split_line(input_line);
		if (_strcmp("exit", *commands) == 0)
			built_exit(input_line, commands, &exit_st, count);
		else if (_strcmp("env", *commands) == 0)
		built_env(commands, env, &exit_st);
		else
			execute_line(argv, commands, count, env, &exit_st, input_line);
		fflush(stdout);

	} while (1);
	free(input_line);
	return (0);
}

