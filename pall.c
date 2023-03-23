#include "monty.h"

/**
 * _pall - displays the content of the stack
 * @head: stack head
 * @count: unused
 * Return: Nothing
 */
void _pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;

	while (*head)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
