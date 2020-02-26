/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado         #+#    #+#                */
/*   Updated: 2020/02/26 17:18:17 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int				manipulate_stacks(t_checker *checker)
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
	{
		delete_lnkd_list(checker);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int				execute_op_code2(char *operation, t_checker *checker)
{
	if (!ft_memcmp("ra", operation, 3))
		rotate(&STCK_A, 0);
	else if (!ft_memcmp("rb", operation, 3))
		rotate(&STCK_B, 0);
	else if (!ft_memcmp("rr", operation, 3))
	{
		rotate(&STCK_A, 0);
		rotate(&STCK_B, 0);
	}
	else if (!ft_memcmp("rra", operation, 4))
		rotate(&STCK_A, 1);
	else if (!ft_memcmp("rrb", operation, 4))
		rotate(&STCK_B, 1);
	else if (!ft_memcmp("rrr", operation, 4))
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
	if (!ft_memcmp("sa", operation, 3))
		swap(STCK_A, 1);
	else if (!ft_memcmp("sb", operation, 3))
		swap(STCK_B, 1);
	else if (!ft_memcmp("ss", operation, 3))
	{
		swap(STCK_A, 1);
		swap(STCK_B, 1);
	}
	else if (!ft_memcmp("pa", operation, 3))
		insert_node(unlink_node(&STCK_B), &STCK_A);
	else if (!ft_memcmp("pb", operation, 3))
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

t_node			*unlink_node(t_node **node)
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

void			insert_node(t_node *src, t_node **dest)
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
