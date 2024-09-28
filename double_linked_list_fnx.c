#include "monty.h"

/**
 *add_nodeint - Adds a new node at the beginning of a dlistint_t list.
 *@head: Double pointer to the head of the list.
 *@n: integer value to insert into the new list.
 *
 * Return: Address of the new elements, otherwise NULL on failure.
 */

stack_t *add_nodeint(stack_t **stack, const int n)
{
	stack_t *new_node;
	
	if (!stack)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 *free_stack - Frees a dlistint)_t list.
 *@head: pointer to the head of the doubly linked list.
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
