#include <stdio.h>
#include "main.h"

/**
 * main - a program that prints all arguments it receives.
 * @argc : n of args
 * @argv : array of args
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; argc > i; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
