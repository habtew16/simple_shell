#include "shell.h"

/**
 * _is_positive - function to check if passed strinng
 * is positive or not
 * @str: string to check
 * Return: always 0 on success and -1 if is negative
 * the passed strinnng is not a number
*/


int _is_positive(char *str)
{
	int i = 0;

	if (str[0] == '-')
		return (-1);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
	}
	return (0);
}


/**
* _atoi - function  entry point to convert string to integer
* @s: strinng to be converted to number
* Return: return integer if string conntians integer
* or return 0 if string doesn't contain any number
*/

int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	while (s[i] == ' ')
	{
		i++;
	}

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}


	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}

