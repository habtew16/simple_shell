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
 * print_num_recursive - recursive helper function to print a number
 * @num: the number to print
 */


void print_num_recursive(int num)
{
	if (num == 0)
		return;
	print_num_recursive(num / 10);
	_werror((num % 10) + '0');
}

/**
 * print_num - function that print a num with function write
 * @count: the number of times you have done a command
 */

void print_num(int count)
{
	if (count == 0)
		_werror('0');
	else
		print_num_recursive(count);
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
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, first, _strlen(first));
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
		write(STDERR_FILENO, "not found\n", 10);
	}
}

