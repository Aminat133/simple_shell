#include "main.h"

/**
 * _getenv - gets the environment.
 * @name: varname to find.
 * Return: nothing.
 */


char *_getenv(const char *name)
{

        if (name == NULL || environ == NULL)
                return (NULL);
        size_t nameLength = strlen(name);

        for (char **env = environ; *env != NULL; env++)
        {
                if (strncmp(*env, name, nameLength) == 0 && (*env)[nameLength] == '=')
                        return (&(*env)[nameLength + 1]);
        }

        return (NULL);
}

