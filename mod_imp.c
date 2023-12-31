#include "monty.h"

/**
 * mod - This function computes the rest of the division of the
 * second top element of the stack by the top element of the stack
 * @stack: The pointer to the stack
 * @line_number: The current line number in the file
 * Return: The pointer to the stack
 */
stack_t *mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int mod_int = 0;

	if (!head || !(head->nxt))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	mod_int = (head->nxt->n) % (head->n);
	head->nxt->n = mod_int;
	pop(stack, 0);

	return (*stack);
}
