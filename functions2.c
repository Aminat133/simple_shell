#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated with malloc.
 * @new_size: The new size for the allocated memory block.
 *
 * Return: A pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, size_t new_size)
{
	if (new_size == 0)
	{
		free(ptr);  /* If the new size is 0, free the old memory and return NULL */
		return (NULL);
	} else if (ptr == NULL)
	{
		return (malloc(new_size));  /* If pointer is NULL, allocate new memory */
	}
	else
	{
		void *new_ptr = malloc(new_size);

		if (new_ptr)
		{
			char *src = (char *)ptr;
			char *dst = (char *)new_ptr;
			size_t i;

			for (i = 0; i < new_size; i++)
				dst[i] = src[i];

			free(ptr);  /* Free the old memory */
			return (new_ptr);
		}
		else
		{
			return (NULL);
		}
	}
}


/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
	char *originalDest = dest;

	/* Move the destination pointer to the end of the string */
	while (*dest != '\0')
	{
		dest++;
	}

	/* Copy characters from the source to the end of the destination */
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0'; /* Null-terminate the concatenated string */

	return (originalDest);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting copied string.
 */
char *_strcpy(char *dest, const char *src)
{
	char *originalDest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0'; /* Null-terminate the destination string */

	return (originalDest);
}

/**
 * _strncmp - Compares two strings up to a specified number of characters.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: int less than, equal to, or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2 up
 * to 'n' characters.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
	{
		return (0); /* Strings are equal up to 'n' characters */
	}
	else if (*str1 < *str2)
	{
		return (-1); /* str1 is less than str2 */
	}
	else
	{
		return (1); /* str1 is greater than str2 */
	}
}
