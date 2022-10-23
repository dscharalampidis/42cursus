#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int				nbr;
	struct s_node	*nxt;
};

typedef struct s_node	t_node;

void
	lst_insert_end(t_node **head, int nbr)
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
	lst_insert_start(t_node **head, int nbr)
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

int
	main(void)
{
	t_node	*head;
	t_node	*curr;
	int		i;

	head = NULL;
	lst_insert_end(&head, 21);
	lst_insert_end(&head, 22);
	lst_insert_end(&head, 23);
	lst_insert_start(&head, 31);
	lst_insert_start(&head, 32);
	lst_insert_start(&head, 33);
	curr = head;
	i = 0;
	while (curr)
	{
		++i;
		printf("list[%d]: %d\n", i, curr->nbr);
		curr = curr->nxt;
	}
	lst_dealloc(&head);
	return (0);
}
