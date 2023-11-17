#include "monty.h"

/**
 * push - adds a node with the value token on the stack
 * @stack: ponter to the list stack
 * @l_num: unused variable
 * Return:Retuns  address of a new node
 */
stack_t *push(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *n_node;

	/* Create new node */
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node with the value of token */
	n_node->n = token;
	/* New node is placed at the beginning of the list */
	n_node->prv = NULL;
	n_node->nxt = *stack;

	/* If new node is not alone, update the following one */
	if (*stack != NULL)
		(*stack)->prv = n_node;

	/* head points to the new node */
	*stack = n_node;

	return (n_node);
}
