/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_extra.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:00:19 by bprado         #+#    #+#                */
/*   Updated: 2020/06/02 18:27:21 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			print_array(t_ps_obj *obj, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		printf("array[%d]:%d\n", i, obj->array[i]);
		i++;
	}
	print_medians(obj);
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
		if (array[i] < array[i + 1])
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
