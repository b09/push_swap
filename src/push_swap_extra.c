/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_extra.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:00:19 by bprado         #+#    #+#                */
/*   Updated: 2020/03/03 16:38:59 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			print_array(t_ps_obj *obj)
{
	int		i;

	i = 0;
	while (LEN && i < LEN)
	{
		printf("array[%d]:%d  LEN:%d\n", i, obj->array[i], LEN);
		i++;
	}
}

void			delete_sorted_array(t_ps_obj *obj)
{
	if (obj->array != NULL)
	{
		free(obj->array);
		obj->array = NULL;
	}
}

void			create_and_srt_array(t_ps_obj *obj)
{
	int			*array;
	int			i;
	t_node		*head;

	head = STCK_A;
	array = ft_memalloc(sizeof(int) * LEN);
	i = 0;
	while (i < LEN && STCK_A != NULL)
	{
		array[i] = DATA_A;
		STCK_A = NEXT_A;
		i++;
	}
	i = 0;
	while (LEN && i < (LEN - 1))
	{
		if (array[i] > array[i + 1])
		{
			array[i] ^= array[i + 1];
			array[i + 1] ^= array[i];
			array[i] ^= array[i + 1];
			i = -1;
		}
		i++;
	}
	obj->array = array;
	STCK_A = head;
}