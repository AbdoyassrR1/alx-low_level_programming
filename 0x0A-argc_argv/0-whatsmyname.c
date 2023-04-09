#include <stdio.h>
#include <stdlib.h>

/**
 * mynameis -  A function that print program name, followed by a new line
 * @argc : int
 * @argv : array
 * Return: 0
 */
int mynameis(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
