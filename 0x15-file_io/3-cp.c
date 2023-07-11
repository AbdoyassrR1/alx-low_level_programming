#include "main.h"

char *createBuffer(char *file);
void closeFile(int fd);


/**
 * createBuffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return:ptr to the new buffer.
 */
char *createBuffer(char *file)
{
	char *buff;

	buff = malloc(1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}


/**
 * closeFile - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void closeFile(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * main - program that copies the content of a file to another file.
 * @argc: number of argument
 * @argv: arguments list.
 *
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{

	int file_from;
	int file_to;
	int r;
	int w;
	char *buffer;


	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = createBuffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	r = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(file_to, buffer, r);

		if (file_to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	closeFile(file_from);
	closeFile(file_to);

	return (0);

}
