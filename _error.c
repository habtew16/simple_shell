#include "shell.h"

/**
 * _werror - function used to print character
 * to standard error
 * @c: char to be printed in standard error
 * Return: return 1 if success
 * -1 if fails
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
 * print_num - function to print number
 * @count: count of given command done how many times
 */

void print_num(int count)
{
	if (count == 0)
		_werror('0');
	else
		print_num_recursive(count);
}


/**
 * print_error_msg - function that prints error
 * messafe
 * @argv: commands given in list
 * @fi: is first command in argument that is
 * going to be printed if no erro
 * @count: counnnt of the args
*/

void print_error_msg(char **argv, char *fi, int count)
{
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fi, _strlen(fi));
	write(STDERR_FILENO, ": ", 2);
}

/**
 * _error - function used to write custom error
 * message when command not found
 * @argv: list of arguments from ain function
 * which are commands
 * @fi: is first command to be printed
 * if no error found
 * @count: count of commands done
 * @exit_status: status code for exit
*/

void _error(char **argv, char *fi,
		int count __attribute__((unused)), int **exit_status)
{
	struct stat st;

	print_error_msg(argv, fi, count);

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

