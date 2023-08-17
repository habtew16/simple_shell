#include "shell.h"
/**
 *add_node_end - append node to list pointed
 *@head: pointer to pointer
 *@directory_path: string to initialize new node
 *Return: new or NULL
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

