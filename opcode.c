#include "monty.h"

/**
 * op_func - This function selects the correct func to
 * perform the operation
 * @p: The operator passed as argument to program
 * @stack: The pointer to the stack
 * @l_num: The line number in the file
 * Return: Return corresponding pointer to the operator
 */

stack_t *(*op_func(char *p, stack_t **stack, unsigned int l_num))(stack_t
**stack, unsigned int l_num)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"swap", swap},
		{"sub", sub},
		{"mod", mod},
		{"div", div_op},
		{"mul", mul_op},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL}
	};
	char *opcode;
	int i = 0;

	while (i < 14)
	{
		opcode = (ops[i]).opcode;
		/* if the opcode is in the list */
		if (strcmp(p, opcode) == 0)
		{
			/* return that value */
			return (*(ops[i]).f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", l_num, p);
	free_stack(stack);
	exit(EXIT_FAILURE);

}
