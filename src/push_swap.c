/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/10 12:59:23 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	the executable will receive a list of unsorted ints. a copy of all ints
**	is made into a sorted array, and assign_pivot() will access that sorted
**	array to find the best median when trying to sort (according
**	to project specs) a segment of the unsorted array of ints
**	ex: 4, 2, 5, 3, 1	<-- 3 is the median
**	ex: 1, 2 (<- already sorted), 4, 5, 3	<-- 4 is the median
*/

static void		assign_pivot(t_ps *ps, t_node *stack)
{
	int			i;

	i = 0;
	if (stack == ps->stck_a && ps->array)
	{
		ps->pivot = ps->array[((ps->len - ps->srtd) / 2) + ps->srtd - 1];
		if (ps->len - ps->srtd <= 5 && ps->len - ps->srtd >= 3)
			ps->pivot = ps->array[ps->len - (ps->len - ps->srtd - 2)];
		else if (ps->len - ps->srtd < 3)
			ps->pivot = ps->array[ps->len - 1];
	}
	else if (stack == ps->stck_b && ps->array)
	{
		i = ps->meds[ps->m_i] >= 0 ? ps->meds[ps->m_i] : -ps->meds[ps->m_i];
		ps->pivot = ps->array[ps->len + (i / 2) - 1];
		if (i == 5)
			ps->pivot = ps->array[ps->len + 3];
		else if (i <= 3)
			ps->pivot = ps->array[ps->len_b < 3 ? ps->len + ps->len_b - 1 :\
			ps->len + i - 1];
	}
}

static void		sort_three_or_less(t_ps *ps)
{
	t_node		*temp;

	temp = 0;
	if (ps->len == 1 || ps->len - ps->srtd == 2 || ps->len - ps->srtd == 1)
	{
		ps->len - ps->srtd == 2 && ps->stck_a->data > ps->stck_a->next->data &&\
		swap(ps->stck_a, 1, ps);
		ps->srtd = ps->len;
	}
	else if (ps->srtd != ps->len)
	{
		temp = ps->stck_a->data > ps->stck_a->next->data ? ps->stck_a :\
		ps->stck_a->next;
		temp = temp->data > ps->stck_a->next->next->data ? temp :\
		ps->stck_a->next->next;
		++ps->srtd;
		if (temp == ps->stck_a || temp == ps->stck_a->next)
			helper_sort_three(ps, temp);
		sort_three_or_less(ps);
	}
}

static int		helper_for_divide(t_ps *ps, t_node **node, char io)
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

static void		dvid(t_ps *ps, char one_zro, t_node **node)
{
	int			length;
	int			i;

	i = 0;
	assign_pivot(ps, *node);
	length = node == &ps->stck_a ? ps->len - ps->srtd : ps->meds[ps->m_i];
	length = ps->meds[ps->m_i] < 0 ? -length : length;
	one_zro = length <= 3 && ps->m_i == 0 && node == &ps->stck_b ? 1 : one_zro;
	if (helper_for_divide(ps, node, 0))
		one_zro = 1;
	while (*node != NULL && i < length)
	{
		if (ps->len + ps->len_b <= 6 && ps->len == 3 && node == &ps->stck_a)
			return ;
		if (one_zro)
			!helper_for_divide(ps, node, 1) && rotate(node, one_zro, ps);
		else
			rotate(node, one_zro, ps) && helper_for_divide(ps, node, 1);
		++i;
	}
}

void			sort_lnkd_lst(t_ps *ps)
{
	int			current_len;

	current_len = ps->len;
	while (ps->srtd != current_len)
	{
		while (ps->len - ps->srtd > 3)
		{
			dvid(ps, ps->unsrt_btm_a ? 0 : 1, &ps->stck_a);
			++ps->m_i;
		}
		while (ps->len - ps->srtd <= 3 && ps->unsrt_btm_a && ps->len > 3 &&\
		ps->srtd != 0)
			rotate(&ps->stck_a, 0, ps);
		sort_three_or_less(ps);
		ps->unsrt_btm_a = ps->len == 3 && ps->srtd == 3 ? 0 : ps->unsrt_btm_a;
		if (ps->len_b)
		{
			helper_sort_lnkd_lst(ps);
			dvid(ps, ps->meds[ps->m_i] < 0 && ps->m_i > 0 ? 0 : 1, &ps->stck_b);
			ps->holder = ps->len_b - ps->holder;
			ps->meds[ps->m_i] = ps->unsrt_btm_b != 0 ? -ps->holder : ps->holder;
			ps->m_i += ps->meds[ps->m_i] != 0 ? 1 : 0;
			ps->unsrt_btm_b = 0;
		}
	}
}
