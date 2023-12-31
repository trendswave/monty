#include "monty.h"

/**
 * pstr - This function prints the string starting at the top of
 * the stack
 * @stack: The pointer to the stack
 * @line_number: The current line number in the file
 * Return: The pointer to the stack
 */
stack_t *pstr(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		if (head->n < 32 || head->n > 127)
			break;
		putchar(head->n);
		head = head->nxt;
	}
	putchar('\n');

	return (*stack);
}
