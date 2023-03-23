#include "monty.h"

/**
 * addnode - add a node to the head of the stack
 * @head: head of the stack
 * @n: value (int) to be added to stack
 *
 * Return: Nothing
 */
void addnode(stack_t **head, int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Errorn");
		exit(0);
	}

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	if (*head != NULL)
		(*head)->prev = newNode;
	*head = newNode;
}
