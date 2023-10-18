#include "main.h"
#include <sys/wait.h>
#include <errno.h>

/**
 * execute_command - Execute the command specified in `cmd`
 * @cmd: The command string to execute
 * Return: nothing.
 */
void execute_command(char *cmd)
{
	char *argv[MAX_ARGS];
	int argc = 0;
	pid_t pid;

	argv[argc] = strtok(cmd, " \n");

	while (argv[argc] != NULL && argc < MAX_ARGS - 1)
	{
		argc++;
		argv[argc] = strtok(NULL, " \n");
	}

	argv[argc] = NULL;

	if (argc == 0)
	{
		return; /* Empty command */
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execute_child_process(argv);
	}
	else
	{
		execute_parent_process(pid);
	}
}

/**
 * execute_child_process - Execute the command in the child process
 * @argv: An array of command and arguments
 * Return : nothing.
 */
void execute_child_process(char *argv[])
{
char *path;
char *dir;

	execve(argv[0], argv, environ);

	path = _getenv("PATH");
	dir = _strtok(path, ":");

	while (dir != NULL)
	{
		char full_path[1024];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, argv[0]);

		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		dir = _strtok(NULL, ":");
	}

	printf("%s: command not found\n", argv[0]);
	exit(EXIT_FAILURE);
}

/**
 * execute_parent_process - Wait for and handle the parent process
 * @pid: Process ID of the child process
 * Return : nothing.
 */
void execute_parent_process(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
}


