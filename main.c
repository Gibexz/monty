#include "monty.h"
prop_t global = {NULL, NULL, NULL, 0};
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
	char *content;
	FILE *file;
	size_t buff = 0;
	ssize_t read_check = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

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
	while (read_check > 0)
	{
		content = NULL;
		read_check = getline(&content, &buff, file);
		global.content = content;
		count++;
		if (read_check > 0)
		{
			checkNexec(&stack, content, count, file);
		}
		free(content);
	}
	freeStack(stack);
	fclose(file);

	return (0);
}
