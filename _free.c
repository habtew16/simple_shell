#include "shell.h"
/**
* free_loop - function used to free doubly
* linked list set by directory_node
* @arr: pointer array that contains
* the address of another pointer
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
* free_list - function to Free a linked list of directories
* @head: is the head of the directory_list
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


