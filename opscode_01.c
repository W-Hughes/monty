#include "monty.h"

/**
 *swap - Swaps the top two elements of the stack
 *@stack: Double pointer to the stack.
 *@line_number: Line number of the current code.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;

	if (first->next)
		first->next->prev = first;

	*stack = second;
}


/**
 *add - Adds the top two elements of the stack.
 *@stack: Double pointer to the stack
 *@line_number: Line number of the opcode .
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: cant't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);


}


/**
 *nop - Doesn't do anything.
 *@stack: Double pointer to the stack.
 *@line_number: Line numer of the current opcode.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}


/**
 *pop - Delete the top of list
 *@stack: Double pointer to the stack.
 *@line_number: line of the current opcode.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}



/**
 *pint - Prints the value of the top of the stack, folowed
 *	by a new line.
 *@stack: The stack to print the top number of.
 *@line_number: line number of the stack.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}



/**
 *push - Pushes an element to the stack.
 *@stack: Double point to the stack that Monty operations manipulate
 *@line_number: Line number of the bytecode file.
 *@arg: Pointer to the argument passed to the opcode
 */

void push(stack_t **stack, char *line, unsigned int line_number)
{

	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");


	if (!arg || !_isdigit(*arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;  
}
