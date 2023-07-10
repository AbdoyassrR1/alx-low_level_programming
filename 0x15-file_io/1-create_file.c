#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: the name of file to create.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
*/

int create_file(const char *filename, char *text_content)
{
	int fd;
	int w;
	int length;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT, O_WRONLY, O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	while (text_content)
	{
		for (length = 0; text_content[0];)
		{
			length++;
		}
	}

	w = write(fd, text_content, length);

	if (w == -1)
		return (-1);

	close(fd);
	return (1);
}