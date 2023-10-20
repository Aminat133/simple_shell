#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @str: The string to get the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _puts - Prints a string to stdout.
 * @str: The string to print.
 *
 * Return: void
 */
int _puts(const char *str)
{
	int i;
	/* Loop through the characters of the string */
	for (i = 0; str[i] != '\0'; i++) {
		/* Call our custom putchar function to print each character */
		_putchar(str[i]);
	}

	return (0);
}

/**
 * _putchar - Writes a character to stdout.
 * @character: The character to write.
 *
 * Return: The character written as an unsigned char cast to an int.
 */
int _putchar(int character)
{
	/* Use the write function to write the character to stdout (file descriptor 1) */
	if (write(1, &character, 1) == 1) {
		return ((int)(unsigned char)character);
	} else {
		return (EOF);
	}
}

/**
 * _strcspn - Gets the length of the initial segment of a string that does not
 * contain any characters from a specified reject string.
 * @str: The string to search.
 * @reject: The reject string.
 *
 * Return: The length of the initial segment of str that does not contain any
 * characters from reject.
 */
size_t _strcspn(const char *str, const char *reject)
{
	size_t length = 0;

	/* Create a lookup table to check if a character in 'reject' is present */
	int lookup[256] = {0};
	const char *r;
	for (r = reject; *r != '\0'; ++r) {
		lookup[(unsigned char)*r] = 1;
	}

	/* Iterate through 'str' and count characters until one is found in 'reject' */
	while (str[length] != '\0' && !lookup[(unsigned char)str[length]]) {
		length++;
	}

	return (length);
}
