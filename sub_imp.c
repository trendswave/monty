#include "monty.h"

/**
 * sub - This function subtracts the top two nodes of the stack, stores it in
 * the second node, and pops off the top node
 * @stack: The stack list
 * @line_number: The line number of the file
 * Return: Retuns the edited stack
 */

stack_t *sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->nxt)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't sub, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Sum first two nodes, and store it in second node */
	diff = (head->nxt->n) - (head->n);
	head->nxt->n = diff;
	pop(stack, 0);

	return (*stack);
}
