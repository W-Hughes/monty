#include "monty.h"

/**
 *validate_int - Validates if an argument is an int
 *@arg: pointer to argument passed
 *@line_number: line number
 */

void validate_int(char *arg, unsigned int line_number)
{
	int i;

	if (arg == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
