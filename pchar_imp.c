#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: The stack list
 * @l_num: The line number of the file
 * Return: Returns head of the stack
 */

stack_t *pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	/* if stack is NULL */
	if (!head)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}

	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr,
			"L%d: can't pchar, value out of range\n", l_num);
		exit(EXIT_FAILURE);
	}

	putchar(head->n);
	putchar('\n');

	return (*stack);
}
