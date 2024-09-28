#include "monty.h"

/**
 *execute_opcode - Executes opcodes
 *@stack: Double pointer to the stack that Monty operation manipulates.
 *@line: The line to read command and operations from.
 *@line_number: The line number of the bytecode file where the instruction
 *		is found, used for error messages.
 */
void execute_opcode(stack_t **stack, char *line, unsigned int line_number)
{
	instruction_t inst[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	int i = 0;
	char *cmd_start;

	cmd_start = _trim(line);
	if (cmd_start == NULL)
		return;

	if (_strncmp(cmd_start, "push", _strlen("push")) == 0)
	{
		push(stack, line, line_number);
		return;
	}

	while (inst[i].opcode)
	{
		if (_strncmp(cmd_start, inst[i].opcode, _strlen(inst[i].opcode)) == 0)
		{
			inst[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd_start);
	exit(EXIT_FAILURE);
}
