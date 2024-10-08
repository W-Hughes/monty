#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation
 *		of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Helper Functions */
int _isdigit(int c);
char *_trim(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *find_first_digit(char *s);
int _strncmp(char *s1, char *s2, int n);

/* Doubly Linked list Operations */
void free_stack(stack_t *stack);
stack_t *add_nodeint(stack_t **stack, const int n);

/* Opscodes */
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, char *line, unsigned int line_number);


size_t _getline(char **lineptr, size_t *n, FILE *stream);
void execute_opcode(stack_t **stack, char *line, unsigned int line_number);


#endif /* MONTY_H */
