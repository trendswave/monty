#include "monty.h"

/**
 * pall - The function that print all
 * @stack: pointer to the list stack
 * @l_numb: unused variable(line number)
 * Return: the address of the first node
 */
stack_t *pall(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	size_t node = 0;

	temp = *stack;

	if (*stack == NULL)
	{
		return (NULL);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->nxt;
		node++;
	}

	return (*stack);
}
