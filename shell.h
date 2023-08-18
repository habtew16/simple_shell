#ifndef shell_h
#define shell_h


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define del " \t\r\n\v\a"

/**
* struct directory_node - singly linked list
* @directory_path: string - (malloc'ed string)
* @next: points to the next node
*
* Description: singly linked list node structure
* for directories of PATH
*/
typedef struct directory_node
{
	char *directory_path;
	struct directory_node *next;
} directory_list;


int is_whitespace(char *str);
int _is_positive(char *com);
int _atoi(char *s);
void execute_line(char **argv, char **commands,
		int count, char **env, int *exit_st, char *line);
char **split_line(char *line);
directory_list *list_path(char **env);
int _setenv(const char *name, const char *value, int overwrite);
char *_which(char **commands, char **env);
void builtin_exit(char *line, char **arg, int *exit_st,
		int count __attribute__((unused)));
void builtin_env(char **arg, char **env, int *exit_st);
char *_getenv(const char *name, char **env);
void _error(char **argv, char *first,
		int count __attribute__((unused)), int **exit_st);
int handle_cases(char *line, ssize_t len, int *exit_st);
void add_node_end(directory_list **head, const char *directory_path);
void print_num(int count);
int _strlen(char *s);
char *_strcat(char *s1, char *s2);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void free_loop(char **arr);
void free_list(directory_list *head);
char *_strncpy(char *dest, char *src, int n);

#endif

