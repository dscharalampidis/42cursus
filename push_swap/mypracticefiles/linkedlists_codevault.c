#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int				nbr;
	struct s_node	*nxt;
};

typedef struct s_node	t_node;

void
	lst_insert_tail(t_node **head, int nbr)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->nbr = nbr;
	new_node->nxt = NULL;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->nxt)
		curr = curr->nxt;
	curr->nxt = new_node;
}

void
	lst_insert_head(t_node **head, int nbr)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->nbr = nbr;
	new_node->nxt = *head;
	*head = new_node;
}

void
	lst_dealloc(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	while (curr)
	{
		tmp = curr;
		curr = curr->nxt;
		free(tmp);
	}
	*head = NULL;
}

void
	lst_print(t_node *head)
{
	t_node	*curr;
	int		i;

	curr = head;
	i = 0;
	while (curr)
	{
		++i;
		printf("list[%d]: %d\n", i, curr->nbr);
		curr = curr->nxt;
	}
}

void lst_remove_tail(t_node **head)
{
	t_node *curr;

	if (!(*head)->nxt)
		free(*head);
	curr = *head;
	while (curr->nxt->nxt)
		curr = curr->nxt;
	free(curr->nxt);
	curr->nxt = NULL;
}

void
	lst_rotate_cw(t_node **head)
{
	t_node	*curr;

	curr = *head;
	while (curr->nxt)
		curr = curr->nxt;
	lst_insert_head(head, curr->nbr);
	lst_remove_tail(head);
}

void
	lst_rotate_ccw(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	tmp = curr;
	while (curr->nxt)
		curr = curr->nxt;
	curr->nxt = *head;
	*head = tmp->nxt;
	tmp->nxt = NULL;
}

int
	main(void)
{
	t_node	*head;

	head = NULL;
	lst_insert_tail(&head, 21);
	lst_insert_tail(&head, 22);
	lst_insert_tail(&head, 23);
	lst_insert_head(&head, 31);
	lst_insert_head(&head, 32);
	lst_insert_head(&head, 33);
	printf("--- Original list ---\n");
	lst_print(head);
	printf("--- Rotate list ---\n");
	lst_rotate_ccw(&head);
	lst_print(head);
	printf("--- Reverse rotate list ---\n");
	lst_rotate_cw(&head);
	lst_print(head);
	lst_dealloc(&head);
	return (0);
}
