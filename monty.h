fndef _MONTY_H_
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
