#include "main.h"

/**
 * execute_env - prints the environment
 *
 * Return: nothing.
 */

void execute_env(void)
{
	char **env = environ;

	while (*env)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}

