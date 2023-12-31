#include "monty.h"

/**
 * div_op - This function divides the second top nodes of the stack by the top
 * @stack: The stack list
 * @line_number: The line number of the file
 * Return: The new stack
 */

stack_t *div_op(stack_t **stack, unsigned int line_number)
{
	int outcome = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->nxt)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* stores result in first node */
	outcome = (head->nxt->n) / (head->n);
	head->nxt->n = outcome;
	pop(stack, 0);

	return (*stack);
}
