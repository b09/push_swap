/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/05 20:12:13 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
 ** swap(), unlink_node(), insert_node(), and rotate() may be useful for
 **	push_swap.c
*/

int				swap(t_node *stack, char swap_going_down_list, t_ps_obj *obj)
{
	if (ft_strcmp(obj->argv[0], "./checker"))
		stack == obj->stck_a ? ft_putstr("sa\n") : ft_putstr("sb\n");
	if (stack == NULL)
		return (0);
	if (swap_going_down_list && stack->next != NULL)
	{
		stack->data ^= stack->next->data;
		stack->next->data ^= stack->data;
		stack->data ^= stack->next->data;
	}
	return (1);
}

/*
**	must account for final node
*/

static t_node	*unlink_node(t_node **node, char get_first_node)
{
	t_node		*unlinked_node;

	unlinked_node = *node;
	if (*node == NULL || ((*node)->next == NULL && (*node)->previous == NULL))
		*node = NULL;
	else if (get_first_node)
	{
		if ((*node)->next != NULL)
			(*node)->next->previous = NULL;
		*node = (*node)->next;
		unlinked_node->next = NULL;
	}
	else if (!get_first_node)
	{
		if ((*node)->previous != NULL)
			(*node)->previous->next = NULL;
		*node = (*node)->previous;
	}
	return (unlinked_node);
}

static void		insert_node(t_node *loose_node, t_node **dest, char add_to_end)
{
	if (loose_node == NULL)
		return ;
	if (*dest != NULL && !add_to_end)
	{
		loose_node->next = *dest;
		loose_node->previous = NULL;
		(*dest)->previous = loose_node;
		*dest = loose_node;
	}
	else if (*dest != NULL && add_to_end)
	{
		loose_node->previous = *dest;
		loose_node->next = NULL;
		(*dest)->next = loose_node;
		*dest = loose_node;
	}
	else
	{
		loose_node->next = NULL;
		loose_node->previous = NULL;
		*dest = loose_node;
	}
}

void			push(t_node **src, t_node **dest, t_ps_obj *obj)
{
	insert_node(unlink_node(src, 1), dest, 0);
	if (*src == obj->stck_a)
	{
		if (ft_strcmp(obj->argv[0], "./checker"))
			ft_putstr("pb\n");
		++(MEDS[MED_I]);
		--obj->len;
		++obj->len_b;
	}
	else
	{
		if (ft_strcmp(obj->argv[0], "./checker"))
			ft_putstr("pa\n");
		--obj->len_b;
		++obj->len;
	}
}

int				rotate(t_node **node, char insert_at_end, t_ps_obj *obj)
{
	t_node		*loose_node;

	if (*node == NULL || ((*node)->next == NULL && (*node)->previous == NULL))
		return (0);
	if (!insert_at_end)
		navigate_thru_lnkd_lst(node, 1);
	loose_node = unlink_node(node, insert_at_end);
	navigate_thru_lnkd_lst(node, insert_at_end);
	insert_node(loose_node, node, insert_at_end);
	navigate_thru_lnkd_lst(node, 0);
	if (ft_strcmp(obj->argv[0], "./checker"))
	{
		if (*node != NULL && insert_at_end == 0)
			ft_putchar('r');
		(*node == obj->stck_a) ? ft_putstr("ra\n") : ft_putstr("rb\n");
	}
	insert_at_end && *node == obj->stck_a && ++UNSRT_BTTM_A;
	insert_at_end && *node == obj->stck_b && ++UNSRT_BTTM_B;
	!insert_at_end && *node == obj->stck_a && --UNSRT_BTTM_A;
	return (1);
}
