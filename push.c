#include "monty.h"

/**
 * _push - adds a node to the stack
 * @head: head of the stack
 * @count: line_number
 *
 * Return: Nothing
 */
void _push(stack_t **head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			j++;
		for (; global.arg[j] != '\0'; j++)
		{
			if (global.arg[j] > 57 || global.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integeri\n", count);
			fclose(global.file);
			free(global.content);
			freeStack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(global.file);
		free(global.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(global.arg);
	if (global.lifi == 0)
		addnode(head, n);

}
