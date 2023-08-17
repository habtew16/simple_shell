#include "shell.h"

/**
 * add_node_end - Adds a new node at the end of the list.
 * @head: Pointer to the head of the list.
 * @directory_path: String to be added to the new node.
 */


void add_node_end(directory_list **head, const char *directory_path)
{
	directory_list *last = *head;
	directory_list *new = malloc(sizeof(directory_list));

	new->next = NULL;
	new->directory_path = _strdup((char *)directory_path);
	if (last)
	{
		while (last->next)
		last = last->next;
		last->next = new;
	}
	else
		*head = new;
}
/**
 *list_path - function that builds a linked list of the PATH directories
 *@env: environment variables
 *Return: the head of the list
 */

directory_list *list_path(char **env)
{
	char *token;
	char *path;
	directory_list *head;

	head = NULL;
	path = _getenv("PATH", env);
	add_node_end(&head, ".");
	token = strtok(path, ":");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}

