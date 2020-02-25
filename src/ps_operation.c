/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado         #+#    #+#                */
/*   Updated: 2020/02/25 19:28:49 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			manipulate_stacks(t_checker *checker)
{
	char		*operation;
	char		i;

	i = 1;
	while (get_next_line(0, &operation) > 0 && i)
	{
		i = execute_op_code(operation, checker);
		print_content_lnkd_list(checker);
	}
	if (i == 0)
		write(2, "Error\n", 7);
}

int				execute_op_code2(char *operation, t_checker *checker)
{
	if (!ft_memcmp("ra", operation, 2))
		rotate(&STCK_A, 0);
	else if (!ft_memcmp("rb", operation, 2))
		rotate(&STCK_B, 0);
	else if (!ft_memcmp("rr", operation, 2))
	{
		rotate(&STCK_A, 0);
		rotate(&STCK_B, 0);
	}
	else if (!ft_memcmp("rra", operation, 3))
		rotate(&STCK_A, 1);
	else if (!ft_memcmp("rrb", operation, 3))
		rotate(&STCK_B, 1);
	else if (!ft_memcmp("rrr", operation, 3))
	{
		rotate(&STCK_A, 1);
		rotate(&STCK_B, 1);
	}
	else
		return (0);
	return (1);
}

int				execute_op_code(char *operation, t_checker *checker)
{
	if (!ft_memcmp("sa", operation, 2))
		swap(STCK_A, 1);
	else if (!ft_memcmp("sb", operation, 2))
		swap(STCK_B, 1);
	else if (!ft_memcmp("ss", operation, 2))
	{
		swap(STCK_A, 1);
		swap(STCK_B, 1);
	}
	else if (!ft_memcmp("pa", operation, 2))
		insert_node(unlink_node(&STCK_B), &STCK_A);
	else if (!ft_memcmp("pb", operation, 2))
		insert_node(unlink_node(&STCK_A), &STCK_B);
	else
		return (execute_op_code2(operation, checker));
	return (1);
}

static void		swap(t_node *stack, char io)
{
	if (stack == NULL)
		return ;
	if (io && stack->next != NULL)
	{
		stack->data ^= stack->next->data;
		stack->next->data ^= stack->data;
		stack->data ^= stack->next->data;
		return ;
	}
	stack->data ^= stack->previous->data;
	stack->previous->data ^= stack->data;
	stack->data ^= stack->previous->data;
}

static t_node	*unlink_node(t_node **node)
{
	t_node		*unlinked_node;

	unlinked_node = *node;
	if (*node == NULL)
		return (NULL);
	if ((*node)->next != NULL)
		(*node)->next->previous = NULL;
	*node = (*node)->next;
	return (unlinked_node);
}

static void		insert_node(t_node *src, t_node **dest)
{
	if (src == NULL)
		return ;
	if (*dest != NULL)
	{
		src->next = *dest;
		src->previous = NULL;
		(*dest)->previous = src;
		*dest = src;
	}
	else
	{
		src->next = NULL;
		src->previous = NULL;
		*dest = src;
	}
}

static void		rotate(t_node **node, char io)
{
	t_node		*head;

	head = *node;
	if (*node == NULL)
		return ;
	if (io)
	{
		while ((*node)->next != NULL)
		{
			swap(*node, 1);
			*node = (*node)->next;
		}
		*node = head;
		return ;
	}
	while ((*node)->next != NULL)
		*node = (*node)->next;
	while ((*node)->previous != NULL)
	{
		swap(*node, 0);
		*node = (*node)->previous;
	}
	*node = head;
}
