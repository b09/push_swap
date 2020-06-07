/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_extra.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:00:19 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/07 15:18:52 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			delete_sorted_array(t_ps *ps)
{
	if (ps->array != NULL)
	{
		free(ps->array);
		ps->array = NULL;
	}
}

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
			ft_putstr("Error: Multiple integers with same value\n");
			return (1);
		}
		i++;
	}
	return (0);
}

/*
**	should rewrite to traverse linked list up to specified point, which would be
**	necessary for the divide_a && divide_b funcs to not interate over the entire
**	linked list, rather just the sections that are unsorted
*/

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
