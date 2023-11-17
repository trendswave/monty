#include "monty.h"

/**
 * add - This function adds the top two nodes of the stack, stores it in
 * the second node, and pops off the top node
 * @stack: The stack list
 * @l_num: The line number of the file
 * Return: Returns the added stack
 */

stack_t *add(stack_t **stack, unsigned int l_num)
{
	int sum = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->nxt)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't add, stack too short\n",
l_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Adds first two nodes, and store it in second node */
	sum = (head->n) + (head->nxt->n);
	head->nxt->n = sum;
	pop(stack, 0);

	return (*stack);
}
