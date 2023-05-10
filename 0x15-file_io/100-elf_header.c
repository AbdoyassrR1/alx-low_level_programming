#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

void print_osabi_more(Elf64_Ehdr h);

/**
 * print_magic - prints ELF magic byte
 * @h: the ELF header struct
 */
void print_magic(Elf64_Ehdr h)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
		printf("%2.2x%s", h.e_ident[index], index == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - print ELF class
 * @h: the ELF header struct
 */
void print_class(Elf64_Ehdr h)
{
	printf("  Class:                             ");
	switch (h.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
		break;
		case ELFCLASS32:
			printf("ELF32");
		break;
		case ELFCLASSNONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_data - print ELF data
 * @h: the ELF header struct.
 */
void print_data(Elf64_Ehdr h)
{
	printf("  Data:                              ");
	switch (h.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
		break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
		break;
		case ELFDATANONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_version - print ELF version
 * @h: the ELF header struct.
 */
void print_version(Elf64_Ehdr h)
{
	printf("  Version:                           %d", h.e_ident[EI_VERSION]);
	switch (h.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
		break;
		case EV_NONE:
			printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * print_osabi - print ELF osabi
 * @h: the ELF header struct.
 */
void print_osabi(Elf64_Ehdr h)
{
	printf("  OS/ABI:                            ");
	switch (h.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			print_osabi_more(h);
			break;
	}
	printf("\n");
}


/**
 * print_osabi_more - print ELF osabi more
 * @h: the ELF header struct.
 */
void print_osabi_more(Elf64_Ehdr h)
{
	switch (h.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", h.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion  - print ELF ABI version
 * @h: the ELF header struct.
 */
void print_abiversion(Elf64_Ehdr h)
{
	printf("  ABI Version:                       %d\n",
		h.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - print the ELF type
 * @h: the ELF header struct.
 */
void print_type(Elf64_Ehdr h)
{
	char *p = (char *)&h.e_type;
	int index = 0;

	printf("  Type:                              ");
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		index = 1;
	switch (p[index])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", p[index]);
		break;
	}
	printf("\n");
}

/**
 * print_entry - prints the ELF entry point address
 * @h: the ELF header struct
 */
void print_entry(Elf64_Ehdr h)
{
	int index = 0, length = 0;
	unsigned char *p = (unsigned char *)&h.e_entry;

	printf("  Entry point address:               0x");
	if (h.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		index = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[index])
			index--;
		printf("%x", p[index--]);
		for (; index >= 0; index--)
			printf("%02x", p[index]);
		printf("\n");
	}
	else
	{
		index = 0;
		length = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[index])
			index++;
		printf("%x", p[index++]);
		for (; index <= length; index++)
			printf("%02x", p[index]);
		printf("\n");
	}
}

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 1 on success 0 on failure.
 */
int main(int ac, char **av)
{
	int fd;
	Elf64_Ehdr head;
	ssize_t b;

	if (ac != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Can't open file: %s\n", av[1]), exit(98);
	b = read(fd, &head, sizeof(head));
	if (b < 1 || b != sizeof(head))
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", av[1]), exit(98);
	if (head.e_ident[0] == 0x7f && head.e_ident[1] == 'E' && head.e_ident[2] == 'L' &&
			head.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", av[1]), exit(98);

	print_magic(head);
	print_class(head);
	print_data(head);
	print_version(head);
	print_osabi(head);
	print_abiversion(head);
	print_type(head);
	print_entry(head);
	if (close(fd))
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", fd), exit(98);
	return (0);
}
