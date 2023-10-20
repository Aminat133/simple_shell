#include "main.h"

/**
 * main - runs a shell.
 *
 * Return: 0 on success
 */

int main(void)
{
	int running = 1;
	char *cmd;

	while (running)
	{
		_puts("$ ");
		cmd = read_input();

		if (_strcmp(cmd, "exit") == 0)
		{
			running = 0;
		}
		else if (_strcmp(cmd, "env") == 0)
		{
			execute_env();
		}
		else
		{
			execute_command(cmd);
		}

		free(cmd);
		}
		return (0);
}

