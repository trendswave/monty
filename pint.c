#include "monty.h"

/**
 * pint - The function prints the integer of the head
 * @stack: Pointer to the stack variable
 * @l_num: Line number of the file
 * Return: Returns Pointer to the stack
 */

stack_t *pint(stack_t **stack, unsigned int l_num)
{
	stack_t *head;

	head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", head->n);

	return (*stack);
}
