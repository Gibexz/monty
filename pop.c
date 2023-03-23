#include "monty.h"

/**
 * _pop -  can't pop an empty stack
 * @head: head of the stack
 * @count: line_number
 *
 * Return: Nothing
 */
void _pop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		fclose(global.file);
		free(global.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}
