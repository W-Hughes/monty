#include "monty.h"

/**
 *pall - Prints all the values on the stack, starting from the top of the stack
 *@stack: Double pointer to the stack dat Monty operations manipulate.
 *@line_number: line number of the bytecode file.
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (!current)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
