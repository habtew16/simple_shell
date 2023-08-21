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
*@fi: first command to print if not found
*@count: the number of times you have done a command
*@exit_status: exit status
*/
void _error(char **argv, char *fi,
		int count __attribute__((unused)), int **exit_status)
{
	struct stat st;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fi, _strlen(fi));
	write(STDERR_FILENO, ": ", 2);

	if (stat(fi, &st) == 0 && S_ISDIR(st.st_mode))
	{
		**exit_status = 126;
		if (_strcmp(fi, "..") == 0)
			**exit_status = 127;
		perror("");
	}
	else
	{
		**exit_status = 127;
		write(STDERR_FILENO, "not found\n", 10);
	}
}

