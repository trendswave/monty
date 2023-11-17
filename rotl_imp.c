#include "monty.h"

/**
 * rotl - The purpose of this function is to rotate the stack to the top
 * @stack: The pointer to the top of the stack
 * @line_number: The current line number in the file
 * Return: The pointer to the stack
 */

stack_t *rotl(stack_t **stack,
	      unsigned int l_num __attribute__ ((unused)))
{
	stack_t *head = *stack;

	while (!head)
		head = head->nxt;

	/* points to the second node */
	*stack = (*stack)->nxt;
	head->nxt = (*stack)->prv;
	(*stack)->prv = NULL;
	head->nxt->prv = head;
	head = head->nxt;
	head->nxt = NULL;

	return (*stack);
}
