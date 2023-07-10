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
	ssize_t fp;
	char *buffer;
	size_t r;
	size_t w;

	fp = open(filename, O_RDONLY);
	if (fp == -1)
		return (0);

	buffer =  malloc(letters);

	r = read(fp, buffer, letters);

	if (r == -1)
		return (0);

	w = write(STDOUT_FILENO, buffer, r);
	if (w == -1)
		return (0);

	free(buffer);
	close(fp);

	return (w);
}
