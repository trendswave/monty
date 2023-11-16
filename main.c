include "monty.h"

/* Global variable initialized */
int token = 1;

/**
 * main - Interprets bytecode
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Return  0 on success
 */
int main(int argc, char **argv)
{
	const char *filename;
	char *str = NULL, *opcode, *num_str;
	size_t nbytes = 1;
	FILE *file;
	unsigned int line_num = 0, i = 0;
	ssize_t read_c = 0;
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
	while (read_c != EOF)
	{
		token = 1;
		i = 0;
		if (str != NULL)
			free(str);
		str = NULL;

		read_c = getline(&str, &nbytes, file);

		if (read_c == -1)
		{
			free(str;
			if (stack != NULL)
				free_stack(&stack);
			fclose(file);
			return (0);
		}

		/* Keep count of the number of lines */
		line_num++;

		/* Continue if line or string is NULL */
		if (read_c == 0)
			continue;

		/* Continue if line had only the new line character */
		if (read_c == 1)
			continue;

		/* Parse the first elements of the line */
		opcode = strtok(str, " \n");

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
				fprintf(stderr, "L%d: usage: push integer\n",
					line_num);
				free(str);
				free_stack(&stack);
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
					fprintf(stderr,
						"L%d: usage: push integer\n",
						line_num);
					free(str);
					free_stack(&stack);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}

			token = atoi(num_str);
		}
		op_func(opcode, &stack, line_num)(&stack, line_num);
	}
	/* Free memory and close the file */
	free(str);
	free_stack(&stack);
	fclose(file);

	return (0);
}
