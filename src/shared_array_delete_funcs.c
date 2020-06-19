/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_array_delete_funcs.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:00:19 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/17 14:22:57 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			create_and_srt_array(t_ps *ps, int i)
{
	int			*array;
	t_node		*head;

	head = ps->stck_a;
	array = ft_memalloc(sizeof(int) * ps->len);
	while (i < ps->len && ps->stck_a != NULL)
	{
		array[i] = ps->stck_a->data;
		ps->stck_a = ps->stck_a->next;
		i++;
	}
	i = 0;
	while (ps->len && i < (ps->len - 1))
	{
		if (array[i] < array[i + 1])
		{
			array[i] ^= array[i + 1];
			array[i + 1] ^= array[i];
			array[i] ^= array[i + 1];
			i = -1;
		}
		i++;
	}
	ps->array = array;
	ps->stck_a = head;
}

int				check_if_unsorted(t_ps *ps, int i)
{
	t_node		*unsorted_input;

	unsorted_input = ps->stck_a;
	i = 0;
	while (unsorted_input)
	{
		if (unsorted_input->next && \
			unsorted_input->data > unsorted_input->next->data)
			return (1);
		unsorted_input = unsorted_input->next;
	}
	return (0);
}

int				repeats_in_sorted_array(t_ps *ps)
{
	int			i;
	int			*array;

	i = 0;
	array = ps->array;
	while (ps->len && i < (ps->len - 1))
	{
		if (array[i] == array[i + 1])
		{
			ft_putstr_fd("Error: Multiple integers with same value\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** add everything to stack_a in order to delete all links
** it is possible to create the linked list and have invalid instructions
** from stdin, in which case, all nodes should be added back to stack_a
** in order to
*/

void			delete_everything(t_ps *ps, t_node **list)
{
	if (ps->array != NULL)
	{
		free(ps->array);
		ps->array = NULL;
	}
	while (ps->stck_b != NULL)
		push(&ps->stck_b, &ps->stck_a, ps);
	if (*list != NULL)
	{
		if ((*list)->next)
			delete_everything(ps, &(*list)->next);
		free(*list);
		*list = NULL;
	}
}

void			navigate_thru_lnkd_lst(t_node **node, char go_to_end)
{
	if (go_to_end)
	{
		while ((*node)->next != NULL)
			*node = (*node)->next;
		return ;
	}
	else
	{
		while ((*node)->previous != NULL)
			*node = (*node)->previous;
		return ;
	}
}
