#include "shell.h"

/**
*_werror - puts a char to the std error
*@c: character to write
*Return: int to print
*/
int _werror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}


/**
*_error - writes an error message similar to the sh error
*when command not found
*@argv: the argv from the main function
*@first: first command to print if not found
*@count: the number of times you have done a command
*@exit_st: exit status
*/
void _error(char **argv, char *first,
		int count __attribute__((unused)), int **exit_st)
{
	struct stat st;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	if (stat(first, &st) == 0 && S_ISDIR(st.st_mode))
	{
		**exit_st = 126;
		if (_strcmp(first, "..") == 0)
			**exit_st = 127;
		perror("");
	}
	else
	{
		**exit_st = 127;
		write(STDERR_FILENO, "No such file or directory\n", 26);
	}
}

