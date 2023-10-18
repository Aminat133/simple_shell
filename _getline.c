#include "main.h"
/**
 * _getline - reads and stores the input
 * from the keyboard.
 * @line: duble pointer to storage.
 * @size: size of storage.
 * @stream: where to read the input from.
 *
 * Return: the total bytes read.
 */
ssize_t _getline(char **line, size_t *size, FILE *stream)
{
	if (line == NULL || size == NULL || stream == NULL)
		return (-1);
	ssize_t bytesRead = 0, totalBytesRead = 0;
	int c;

	if (*line == NULL)
	{
		*size = 128;
		*line = (char *)malloc(*size);
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
		if (bytesRead >= *size - 1)
		{
			*size *= 2;
			char *newLine = (char *)realloc(*line, *size);

			if (newLine == NULL)
			{
				free(*line);
				*line = NULL;
				return (-1);
			}
			*line = newLine;
		}
		if (c == '\n')
			break;
	}
	(*line)[bytesRead] = '\0';
	return (totalBytesRead);
}

