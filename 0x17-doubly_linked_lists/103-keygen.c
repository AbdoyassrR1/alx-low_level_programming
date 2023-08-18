#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments
 * @argv: array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char pass[7];
	char *cod;
	int len = strlen(argv[1]), i, temp;

	cod = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (len ^ 59) & 63;
	pass[0] = cod[temp];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += argv[1][i];
	pass[1] = cod[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < len; i++)
		temp *= argv[1][i];
	pass[2] = cod[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	pass[3] = cod[rand() & 63];

	temp = 0;
	for (i = 0; i < len; i++)
		temp += (argv[1][i] * argv[1][i]);
	pass[4] = cod[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	pass[5] = cod[(temp ^ 229) & 63];

	pass[6] = '\0';
	printf("%s", pass);
	return (0);
}
