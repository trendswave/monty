#ifndef _MONTY_H_
#define _MONTY_H_

/* Libraries */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Declaration of the global variables */
extern int token;

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer variable
 * @prv: points to the previous element of the stack
 * @nxt: points to the next element of the stack
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prv;
    struct stack_s *nxt;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @fun: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct instruction_s
{
	char *opcode;
	stack_t *(*fun)(stack_t **stack, unsigned int l_numb);
} instruction_t;

/*List of Prototypes */
stack_t *pop(stack_t **stack, unsigned int l_num);
stack_t *pall(stack_t **stack, unsigned int l_num);
void free_stack(stack_t **stack);
stack_t *nop(stack_t **stack, unsigned int l_num);
stack_t *(*op_func(char *s, stack_t **stack,
		   unsigned int l_num))(stack_t **stack,
					      unsigned int l_num);	stack_t *pint(stack_t **stack, unsigned int l_num);
stack_t *push(stack_t **stack, unsigned int l_num);
stack_t *swap(stack_t **stack, unsigned int l_num);
stack_t *add(stack_t **stack, unsigned int l_num);
stack_t *nop(stack_t **stack, unsigned int l_num);
stack_t *div_op(stack_t **stack, unsigned int l_num);
stack_t *sub(stack_t **stack, unsigned int l_num);
stack_t *mod(stack_t **stack, unsigned int l_num);
stack_t *mul_op(stack_t **stack, unsigned int l_num);
stack_t *pchar(stack_t **stack, unsigned int l_num);
stack_t *pstr(stack_t **stack, unsigned int l_num);

#endif /* _MONTY_H_ */
