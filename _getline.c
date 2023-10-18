#include "main.h"

/**
 * allocateMemory - allocates memory for line buffer
 * @line: double pointer to line buffer
 * @size: pointer to size of line buffer
 *
 * Return: 0 on success, -1 on failure
 */
int allocateMemory(char **line, size_t *size)
{
	if (line == NULL || size == NULL)
		return (-1);

	*size = 128;
	*line = malloc(*size);
	if (*line == NULL)
		return (-1);

	return (0);
}

/**
 * readCharacter - reads a character from the stream
 * @stream: pointer to stream to read from
 * @line: double pointer to line buffer
 * @bytesRead: pointer to bytes read
 * @totalBytesRead: pointer to total bytes read
 * @size: pointer to size of line buffer
 *
 * Return: 0 on success, -1 on failure
 */
int readCharacter(FILE *stream, char **line, ssize_t *bytesRead,
		ssize_t *totalBytesRead, size_t *size)
{
	int c;

	c = fgetc(stream);
	if (c == EOF)
	{
		if (*bytesRead == 0)
			return (-1);
		return (1);
	}
	(*line)[*bytesRead] = (char)c;
	(*bytesRead)++;
	(*totalBytesRead)++;
	if (*bytesRead >= (ssize_t)(*size - 1))
	{
		if (resizeLineBuffer(line, size) == -1)
			return (-1);
	}
	if (c == '\n')
		return (1);

	return (0);
}

/**
 * resizeLineBuffer - resizes the line buffer
 * @line: double pointer to line buffer
 * @size: pointer to size of line buffer
 *
 * Return: 0 on success, -1 on failure
 */
int resizeLineBuffer(char **line, size_t *size)
{
	char *newLine;

	*size *= 2;
	newLine = realloc(*line, *size);
	if (newLine == NULL)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	*line = newLine;

	return (0);
}

/**
 * _getline - reads and stores the input from the keyboard.
 * @line: double pointer to storage.
 * @size: size of storage.
 * @stream: where to read the input from.
 *
 * Return: the total bytes read.
 */
ssize_t _getline(char **line, size_t *size, FILE *stream)
{
	ssize_t bytesRead = 0, totalBytesRead = 0;
	int c;

	if (line == NULL || size == NULL || stream == NULL)
		return (-1);
	if (*line == NULL)
	{
		*size = 128;
		*line = malloc(*size);
		if (*line == NULL)
			return (-1);
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			if (bytesRead == 0)
				return (-1);
			break;
		}
		(*line)[bytesRead++] = (char)c;
		totalBytesRead++;
		if (bytesRead >= (ssize_t)(*size - 1))
		{
			if (resizeLineBuffer(line, size) == -1)
			{
				free(*line);
				*line = NULL;
				return (-1);
			}
		}
		if (c == '\n')
			break;
	}
	(*line)[bytesRead] = '\0';

	return (totalBytesRead);
}

