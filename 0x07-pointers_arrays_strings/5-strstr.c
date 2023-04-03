#include "main.h"
/**
 * _strstr - Entry point
 * @haystack: input..
 * @needle: input.
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *x = haystack;
		char *po = needle;

		while (*x == *po && *po != '\0')
		{
			x++;
			po++;
		}

		if (*po == '\0')
			return (haystack);
	}

	return (0);
}

