#include "monty.h"

/**
 * _mod - modulus of the top elements of the stack
 * @head: head of the stack
 * @count: line_number
 *
 * Return: Nothing
 */
void _mod(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int value;

	if (!(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *head;
		value = temp->next->n % temp->n;
		*head = (*head)->next;
		(*head)->n = value;
		free(temp);
	}
	
}
