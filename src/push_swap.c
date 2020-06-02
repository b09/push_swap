/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado         #+#    #+#                */
/*   Updated: 2020/06/02 18:26:53 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	argv may contain a single string of multiple ints, in which case
**	obj.len will be reassigned by create_lnkd_lst_single_string() later on
*/

int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	char		*str;

	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (-1);
	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
	create_and_srt_array(&obj);
	sort_lnkd_lst(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	delete_sorted_array(&obj);
	return (0);
}

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
	if (stack == STCK_A && ARRAY)
	{
		PIVOT = obj->array[((UNSORTED) / 2) + SORTED - 1];
		if (UNSORTED <= 5 && UNSORTED >= 3)
			PIVOT = obj->array[LEN - (UNSORTED - 2)];
		else if (UNSORTED < 3)
			PIVOT = obj->array[LEN - 1];
	}
	else if (stack == STCK_B && ARRAY)
	{
		i = MEDS[MED_I] >= 0 ? MEDS[MED_I] : -MEDS[MED_I];
		PIVOT = obj->array[LEN + (i / 2) - 1];
		if (i == 5)
			PIVOT = obj->array[LEN + 3];
		else if (i <= 3)
			PIVOT = obj->array[LEN_B < 3 ? LEN + LEN_B - 1 : LEN + i - 1];
	}
}

static void		sort_three_or_less(t_ps_obj *obj)
{
	t_node		*temp;

	temp = 0;
	if (LEN == 1 || UNSORTED == 2 || UNSORTED == 1)
	{
		if (UNSORTED == 2 && DATA_A > NEXT_A->data)
			swap(STCK_A, 1, obj);
		SORTED = LEN;
	}
	else if (SORTED != LEN)
	{
		temp = DATA_A > NEXT_A->data ? STCK_A : NEXT_A;
		temp = temp->data > NEXT_A->next->data ? temp : NEXT_A->next;
		++SORTED;
		if (temp == STCK_A || temp == NEXT_A)
		{
			if (temp == STCK_A)
				swap(STCK_A, 1, obj);
			rotate(&STCK_A, 1, obj);
			swap(STCK_A, 1, obj);
			rotate(&STCK_A, 0, obj);
		}
		sort_three_or_less(obj);
	}
}

static int		helper_for_divide(t_ps_obj *obj, t_node **node)
{
	if (((node == &STCK_A && (*node)->data < PIVOT) || \
		(node == &STCK_B && (*node)->data >= PIVOT)))
		return (1);
	return (0);
}

static void		divide(t_ps_obj *obj, char one_zero, t_node **node)
{
	int			length;
	int			i;

	i = 0;
	assign_pivot(obj, *node);
	length = node == &STCK_A ? LEN - SORTED : MEDS[MED_I];
	length = MEDS[MED_I] < 0 ? -length : length;
	one_zero = length <= 3 && MED_I == 0 && node == &STCK_B ? 1 : one_zero;
	while (*node != NULL && i < length)
	{
		if (one_zero)
		{
			if (helper_for_divide(obj, node))
				push(node, node == &STCK_A ? &STCK_B : &STCK_A, obj);
			else
				rotate(node, one_zero, obj);
		}
		else
		{
			rotate(node, one_zero, obj);
			if (helper_for_divide(obj, node))
				push(node, node == &STCK_A ? &STCK_B : &STCK_A, obj);
		}
		++i;
	}
}

static void		sort_lnkd_lst(t_ps_obj *obj)
{
	int			current_len;

	current_len = LEN;
	while (SORTED != current_len)
	{
		while (UNSORTED > 3)
		{
			divide(obj, UNSRT_BTTM_A ? 0 : 1, &STCK_A);
			++MED_I;
		}
		while (UNSORTED <= 3 && UNSRT_BTTM_A && LEN > 3 && SORTED != 0)
			rotate(&STCK_A, 0, obj);
		sort_three_or_less(obj);
		UNSRT_BTTM_A = LEN == 3 && SORTED == 3 ? 0 : UNSRT_BTTM_A;
		if (LEN_B)
		{
			MED_I -= MED_I > 0 ? 1 : 0;
			HOLDER = LEN_B - (MEDS[MED_I] < 0 ? -MEDS[MED_I] : MEDS[MED_I]);
			divide(obj, MEDS[MED_I] < 0 && MED_I > 0 ? 0 : 1, &STCK_B);
			HOLDER = LEN_B - HOLDER;
			MEDS[MED_I] = UNSRT_BTTM_B != 0 ? -HOLDER : HOLDER;
			MED_I += MEDS[MED_I] != 0 ? 1 : 0;
			UNSRT_BTTM_B = 0;
		}
	}
}
