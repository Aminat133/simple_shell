#include "main.h"

/**
 * _getline - Reads a line of input from stdin.
 * @line: A pointer to a buffer to store the line in.
 * @n: A pointer to the size of the buffer.
 *
 * Return: The number of bytes read, or -1 on failure.
 */
ssize_t _getline(char **line, size_t *n) {
	ssize_t bytesRead = 0;
	char ch;

	if (line == NULL || n == NULL) {
		return (-1);  /* Invalid arguments*/
	}

	if (*line == NULL) {
		*n = 128;
		*line = (char *)malloc(*n);
		if (*line == NULL) {
			return (-1);  /* Memory allocation failed*/
		}
	}

	while (read(STDIN_FILENO, &ch, 1) > 0) {
		if (ch == '\n') {
			(*line)[bytesRead] = '\0';
			return (bytesRead);
		}

		(*line)[bytesRead] = ch;
		bytesRead++;

		if (bytesRead >= (ssize_t)(*n - 1)) {
			*n *= 2;
			*line = (char *)_realloc(*line, *n);
			if (*line == NULL) {
				return (-1);  /* Memory reallocation failed*/
			}
		}
	}

	if (bytesRead > 0) {
		(*line)[bytesRead] = '\0';
		return (bytesRead);
	}

	return (-1);  /* No input or error*/
}

