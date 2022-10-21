#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				nbr;
	struct	s_node	*nxt;
}					t_node;

void
	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->nbr);
		current = current->nxt;
	}
}

void
	push(t_node **head, int nbr)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->nbr = nbr;
	new_node->nxt = *head;
	*head = new_node;
}

int
	pop(t_node **head)
{
	t_node	*nxt_node;
	int	popped_nbr;

	if (*head == NULL)
		return (-1);
	nxt_node = (*head)->nxt;
	popped_nbr = (*head)->nbr;
	free(*head);
	*head = nxt_node;
	return (popped_nbr);
}

void
	free_list(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->nxt;
		free(tmp);
	}
}

int
	main(void)
{
	t_node	*head;
	int		nbr;

	head = NULL;
	nbr = -1;
	while (++nbr <= 30)
		push(&head, nbr);
	print_list(head);
	nbr = pop(&head);
	printf("I popped %d\n", nbr);
	print_list(head);
	free_list(head);
	return (0);
}
