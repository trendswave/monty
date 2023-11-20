#include "monty.h"
/**
 * pop - This function deletes the node at the toap of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the file
 * Return: Return Pointer to the stack
 */

stack_t *pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	/* pointer to head of stack */
	stack_t *head = *stack;

	/* Check NULL stack */
	if (*stack == NULL)
	{
		/* Prints error, free, and exit */
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Stack pointing to the next node */
	*stack = (*stack)->nxt;

	/* Free beginning head node */
	free(head);

	/*Set it's previous pointer to NULL if available*/
	if (*stack)
		(*stack)->prv = NULL;

	return (*stack);
}
