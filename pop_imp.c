#include "monty.h"

/**
 * pop - This function deletes the node at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the file
 * Return: Pointer to the stack
 */

stack_t *pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	/* Head points to head of stack */
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (*stack == NULL)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Stack now points to the next node */
	*stack = (*stack)->next;

	/* Free head node */
	free(head);

	/* If stack exists already, set it's prev pointer to NULL */
	if (*stack)
		(*stack)->prev = NULL;

	return (*stack);
}
