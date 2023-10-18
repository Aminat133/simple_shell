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
		printf("$ ");
		cmd = read_input();

		if (strcmp(cmd, "exit") == 0)
		{
			running = 0;
		}
		else if (strcmp(cmd, "env") == 0)
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

