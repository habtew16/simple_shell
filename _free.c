#include "shell.h"
/**
* free_loop - Frees a double pointer array of pointers
* @arr: Double pointer array of pointers
*/
void free_loop(char **arr)
{
	int i;

	if (arr)
	{
		for (i = 0; arr[i]; i++)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	free(arr);
	}
}


/**
* free_list - Frees a linked list of directories
* @head: Head of the linked list
*/


void free_list(directory_list *head)
{
	directory_list *current = head;

	while (current)
	{
		directory_list *temp = current;
	current = current->next;
	free(temp->directory_path);
	free(temp);
	}
}


