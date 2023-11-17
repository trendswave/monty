#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: ponter to the list stack
 * @l_num: unused variable
 * Return: Returns address of the first node
 */
stack_t *swap(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *head;
	int temp;

	head = *stack;

	if (head != NULL && head->nxt != NULL)
	{
		temp = head->n;
		head->n = head->nxt->n;
		head->nxt->n = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	return (*stack);
}
