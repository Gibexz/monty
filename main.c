#include "monty.h"

prop_t global = {NULL, NULL, NULL};

/**
 * main - monty code interpreter entry point
 * @argc: num. of arguments to main
 * @argv: array of arguments containing the bytecode
 * directory or file.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	unsigned int count = 0;
	FILE *file;
	char *content;
	size_t bufsize = 0;
	ssize_t check = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	global.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (check > 0)
	{
		content = NULL;
		check = getline(&content, &bufsize, file);
		global.content = content;
		count++;
		if (check > 0)
			checkNexec(&stack, content, count, file);
		free(content);
	}
	freeStack(stack);
	fclose(file);

	return (0);
}
