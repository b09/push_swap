/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/05 20:17:38 by bprado        ########   odam.nl         */
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

static void		assign_pivot(t_ps_obj *obj, t_node *stack)
{
	int			i;

	i = 0;
	if (stack == obj->stck_a && ARRAY)
	{
		PIVOT = obj->array[((obj->len - obj->sorted) / 2) + obj->sorted - 1];
		if (obj->len - obj->sorted <= 5 && obj->len - obj->sorted >= 3)
			PIVOT = obj->array[obj->len - (obj->len - obj->sorted - 2)];
		else if (obj->len - obj->sorted < 3)
			PIVOT = obj->array[obj->len - 1];
	}
	else if (stack == obj->stck_b && ARRAY)
	{
		i = MEDS[MED_I] >= 0 ? MEDS[MED_I] : -MEDS[MED_I];
		PIVOT = obj->array[obj->len + (i / 2) - 1];
		if (i == 5)
			PIVOT = obj->array[obj->len + 3];
		else if (i <= 3)
			PIVOT = obj->array[obj->len_b < 3 ? obj->len + obj->len_b - 1 : obj->len + i - 1];
	}
}

static void		sort_three_or_less(t_ps_obj *obj)
{
	t_node		*temp;

	temp = 0;
	if (obj->len == 1 || obj->len - obj->sorted == 2 || obj->len - obj->sorted == 1)
	{
		obj->len - obj->sorted == 2 && DATA_A > NEXT_A->data && swap(obj->stck_a, 1, obj);
		obj->sorted = obj->len;
	}
	else if (obj->sorted != obj->len)
	{
		temp = DATA_A > NEXT_A->data ? obj->stck_a : NEXT_A;
		temp = temp->data > NEXT_A->next->data ? temp : NEXT_A->next;
		++obj->sorted;
		if (temp == obj->stck_a || temp == NEXT_A)
		{
			temp == obj->stck_a && swap(obj->stck_a, 1, obj);
			rotate(&obj->stck_a, 1, obj) && swap(obj->stck_a, 1, obj);
			rotate(&obj->stck_a, 0, obj);
		}
		sort_three_or_less(obj);
	}
}

static int		helper_for_divide(t_ps_obj *obj, t_node **node, char io)
{
	if (io)
	{
		if (((node == &obj->stck_a && (*node)->data < PIVOT) || \
		(node == &obj->stck_b && (*node)->data >= PIVOT)))
		{
			push(node, node == &obj->stck_a ? &obj->stck_b : &obj->stck_a, obj);
			return (1);
		}
		return (0);
	}
	else
	{
		if ((UNSRT_BTTM_A == obj->len || UNSRT_BTTM_B == obj->len_b))
		{
			if (node == &obj->stck_a)
				UNSRT_BTTM_A = 0;
			else if (node == &obj->stck_b)
				UNSRT_BTTM_B = 0;
			return (1);
		}
		return (0);
	}
}

static void		divide(t_ps_obj *obj, char one_zero, t_node **node)
{
	int			length;
	int			i;

	i = 0;
	assign_pivot(obj, *node);
	length = node == &obj->stck_a ? obj->len - obj->sorted : MEDS[MED_I];
	length = MEDS[MED_I] < 0 ? -length : length;
	one_zero = length <= 3 && MED_I == 0 && node == &obj->stck_b ? 1 : one_zero;
	if (helper_for_divide(obj, node, 0))
		one_zero = 1;
	while (*node != NULL && i < length)
	{
		if (obj->len + obj->len_b <= 6 && obj->len == 3 && node == &obj->stck_a)
			return ;
		if (one_zero)
			!helper_for_divide(obj, node, 1) && rotate(node, one_zero, obj);
		else
			rotate(node, one_zero, obj) && helper_for_divide(obj, node, 1);
		++i;
	}
}

void			sort_lnkd_lst(t_ps_obj *obj)
{
	int			current_len;

	current_len = obj->len;
	while (obj->sorted != current_len)
	{
		while (obj->len - obj->sorted > 3)
		{
			divide(obj, UNSRT_BTTM_A ? 0 : 1, &obj->stck_a);
			++MED_I;
		}
		while (obj->len - obj->sorted <= 3 && UNSRT_BTTM_A && obj->len > 3 && obj->sorted != 0)
			rotate(&obj->stck_a, 0, obj);
		sort_three_or_less(obj);
		UNSRT_BTTM_A = obj->len == 3 && obj->sorted == 3 ? 0 : UNSRT_BTTM_A;
		if (obj->len_b)
		{
			MED_I -= MED_I > 0 ? 1 : 0;
			HOLDER = obj->len_b - (MEDS[MED_I] < 0 ? -MEDS[MED_I] : MEDS[MED_I]);
			divide(obj, MEDS[MED_I] < 0 && MED_I > 0 ? 0 : 1, &obj->stck_b);
			HOLDER = obj->len_b - HOLDER;
			MEDS[MED_I] = UNSRT_BTTM_B != 0 ? -HOLDER : HOLDER;
			MED_I += MEDS[MED_I] != 0 ? 1 : 0;
			UNSRT_BTTM_B = 0;
		}
	}
}
