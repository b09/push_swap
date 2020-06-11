/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_helpers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 18:46:27 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/11 17:32:25 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			helper_sort_lnkd_lst(t_ps *ps)
{
	ps->m_i -= ps->m_i > 0 ? 1 : 0;
	ps->holder = ps->len_b - (ps->meds[ps->m_i] < 0 ?\
	-ps->meds[ps->m_i] : ps->meds[ps->m_i]);
}

void			helper_sort_three(t_ps *ps, t_node *temp)
{
	if (temp == ps->stck_a)
	{
		swap(ps->stck_a, 1, ps);
		if (ps->len == 3)
		{
			rotate(&ps->stck_a, 0, ps);
			return ;
		}
	}
	rotate(&ps->stck_a, 1, ps);
	swap(ps->stck_a, 1, ps);
	rotate(&ps->stck_a, 0, ps);
}

int				helper_for_divide(t_ps *ps, t_node **node, char io)
{
	if (io)
	{
		if (((node == &ps->stck_a && (*node)->data < ps->pivot) || \
		(node == &ps->stck_b && (*node)->data >= ps->pivot)))
		{
			push(node, node == &ps->stck_a ? &ps->stck_b : &ps->stck_a, ps);
			return (1);
		}
		return (0);
	}
	else
	{
		if ((ps->unsrt_btm_a == ps->len ||\
		ps->unsrt_btm_b == ps->len_b))
		{
			if (node == &ps->stck_a)
				ps->unsrt_btm_a = 0;
			else if (node == &ps->stck_b)
				ps->unsrt_btm_b = 0;
			return (1);
		}
		return (0);
	}
}
