#include "main.h"

/**
 * _getenv - gets the environment.
 * @name: varname to find.
 * Return: nothing.
 */


char *_getenv(const char *name)
{
	size_t nameLength;
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);
	nameLength = strlen(name);

	for (env = (char **)environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, nameLength) == 0 && (*env)[nameLength] == '=')
			return (&(*env)[nameLength + 1]);
	}

	return (NULL);
}

