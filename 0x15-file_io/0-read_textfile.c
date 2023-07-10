#include "main.h"

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: the file to read.
 * @letters: number of letters to read.
 *
 * Return: the number of letters , 0 otherwise.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp;
	char *buffer;
	int r;
	int w;

	fp = open(filename, O_RDONLY);
	if (fp == -1)
		exit(EXIT_FAILURE);

	buffer =  malloc(letters);

	r = read(fp, buffer, letters);

	if (r == -1)
		exit(EXIT_FAILURE);

	w = write(STDOUT_FILENO, buffer, r);
	if (w == -1)
		exit(EXIT_FAILURE);

	free(buffer);
	close(fp);
	return (r);
}
