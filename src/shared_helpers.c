/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 19:20:16 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/10 20:12:33 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	{
		push(&ps->stck_b, &ps->stck_a, ps);
		navigate_thru_lnkd_lst(&ps->stck_a, 0);
		navigate_thru_lnkd_lst(&ps->stck_b, 0);
	}
	if (*list != NULL)
	{
		if ((*list)->next)
			delete_lnkd_list(ps, &(*list)->next);
		free(*list);
		*list = NULL;
	}
}