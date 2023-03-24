#include "monty.h"

/**
 * _add - add the top two elements of the stack
 * @head: head of the stack
 * @count: line_number
 *
 * Return: Nothing
 */
void _add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int value;

	if (!(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *head;
		value = temp->n + temp->next->n;
		*head = (*head)->next;
		(*head)->n = value;
		free(temp);
	}
}
