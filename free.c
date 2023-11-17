#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: pointer to the stack
 * Return: returns Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *head;
	stack_t *temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->nxt;
		free(temp);
	}
}
