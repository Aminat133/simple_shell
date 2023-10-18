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
		printf("%s\n", *env);
		env++;
	}
}

