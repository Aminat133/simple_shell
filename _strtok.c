#include "main.h"

/**
 * _strtok - tokenizes a string
 * @str: string to break into tokins
 * @delim: seperating character.
 *
 * Return: the first token on first call, and
 * the cuncurrent token when Str argument is NULL
 */

char *_strtok(char *str, const char *delim)
{
	static char *nextToken;

	if (str != NULL)
		nextToken = str;

	if (nextToken == NULL || *nextToken == '\0')
		return (NULL);

	char *tokenStart = nextToken;
	char *tokenEnd = NULL;

	/* Find the end of the token*/
	while (*nextToken != '\0')
	{
		for (const char *d = delim; *d != '\0'; d++)
		{
			if (*nextToken == *d)
			{
			/*null terminate the token*/
			*nextToken = '\0';
			tokenEnd = nextToken;
			nextToken++;
			break;
			}
		}
		if (tokenEnd != NULL)
			break;

		nextToken++;
	}

	if (tokenEnd == NULL)
		nextToken = NULL;

	return (tokenStart);
}

