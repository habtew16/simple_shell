#include "shell.h"
#include <string.h>


/**
* _strlen - return length of a string
* @s: char type
* Return: length of string
*/


int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcat - function name to copy one file into other
 * @s1: first string
 * @s2: second string to be coppied
 * Return: dest string which new and modified continain
 * second strong
*/

char *_strcat(char *s1, char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	char *cat = (char *)malloc((len1 + len2 + 1) * sizeof(char));

	if (cat == NULL)
		return (NULL);
	strcpy(cat, s1);
	strcat(cat, s2);
	return (cat);
}


/**
 * _strdup - function to return address of the newly
 * allocated memory
 * @str: string to allocate and get new memory address
 * Return: returns address of the allocated memory
*/


char *_strdup(char *str)
{
	int i, j;
	char *dup;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	for (j = 0; j <= i; ++j)
		dup[j] = str[j];
	return (dup);
}


/**
 * _strcmp - compares two strings
 * @s1: s1 first string
 * @s2: string two
 * Return: 0 if two strings are equla
 * 1 if first is greater
 * -1 if second is greator
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

/**
 * _strncpy - funnction to copy one string in to destination
 * @dest: destination pointer
 * @src: source string
 * @n: number of strings
 * Return: new copied string
*/


char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

