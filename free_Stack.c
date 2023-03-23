#include "monty.h"

/**
 * freeStack - function to free the doubly linked list
 * when the monty code are done been interpreted
 * @head: Head of the stack
 * Return: Nothing
 */
void freeStack(stack_t *head)
{
	stack_t *temp;

	temp = head;

	while (head != NULL) /* or just while (head) */
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
