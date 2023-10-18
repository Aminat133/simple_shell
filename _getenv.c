#include "main.h"
/**
 * _getenv - our own function for gettin
 * the environment variables
 *@name: represents env variable
 * Return: it returns null
 */
char *_getenv(const char *name)
{
	size_t nameLength;
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);
	nameLength = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, nameLength) == 0 && (*env)[nameLength] == '=')
			return (&(*env)[nameLength + 1]);
	}

	return (NULL);
}
