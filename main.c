#include "monty.h"
#include <ctype.h>

char *flag = "stack";

/**
 * main - main function to run monty
 * @ac: number of arguments
 * @av: list of arguments as strings
 *
 * Return: 0
 */

int is_line_empty(const char *line);

int main(int ac, char **av)
{
	stack_t *h;
	unsigned int line_number;
	int status;
	char *line;
	size_t length;
	FILE *fp;

	if (ac != 2)
	{
		printf("USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}
	h = NULL;
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}


	line_number = 0;
	do {
		++line_number;
		line = NULL;
		length = 0;
		status = _getline(&line, &length, fp);
		if (status > 0)
			execute_opcode(&h, line, line_number);
		else
			free(line);
	} while (status >= 0);

	fclose(fp);
	free_stack(h);

	return (0);
}
