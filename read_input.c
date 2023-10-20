#include "main.h"
#include <string.h>

/**
 * read_input - creates a string from the
 * input from the keyboard.
 *
 * Return: the read string.
 */

char *read_input(void)
{
	char *cmd = NULL;
	size_t n = 0;

	if (_getline(&cmd, &n) == -1)
	{
		_puts("Error reading input.\n");
		free(cmd);
		exit(EXIT_FAILURE);
	}

	cmd[_strcspn(cmd, "\n")] = '\0';
	return (cmd);
}

