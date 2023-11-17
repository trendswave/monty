#include "monty.h"

/* Initialize the global variable */
int token = 1;

#define MAX_LINE_LENGTH 100

/**
 * main - Interprets bytecode
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    const char *filename;
    char line[MAX_LINE_LENGTH];
    char *opcode, *num_str;
    size_t line_length;
    FILE *file;
    unsigned int line_num = 0, i = 0;
    stack_t *stack;

    stack = NULL;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    filename = argv[1];

    /* Open File with the bytecodes */
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Read file line by line */
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_num++;

        /* Remove the newline character at the end of the line */
        line_length = strlen(line);
        if (line[line_length - 1] == '\n')
            line[line_length - 1] = '\0';

        /* Skip empty lines */
        if (line[0] == '\0')
            continue;

        /* Parse the first elements of the line */
        opcode = strtok(line, " \n");

        /* If string is empty, let's continue */
        if (opcode == NULL)
            continue;

        if (opcode[0] == '#')
        {
            nop(&stack, line_num);
            continue;
        }

        /* Check whether the first token is the opcode 'push' */
        if (strcmp(opcode, "push") == 0)
        {
            num_str = strtok(NULL, " \n");

            /* Check if token is a digit or NULL */
            if (num_str == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_num);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            if (num_str[0] == '-' && num_str[1] != '\0')
                i = 1;

            /* Make sure string isn't garbage */
            for (; num_str[i] != '\0'; i++)
            {
                if (isdigit(num_str[i]) == 0)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_num);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
            }

            token = atoi(num_str);
        }

        op_func(opcode, &stack, line_num)(&stack, line_num);
    }

    /* Close the file */
    fclose(file);

    return 0;
}
