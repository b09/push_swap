/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_extra.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 19:00:19 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/03 18:54:21 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			delete_sorted_array(t_ps_obj *obj)
{
	if (obj->array != NULL)
	{
		free(obj->array);
		obj->array = NULL;
	}
}

void			create_and_srt_array(t_ps_obj *obj, int i)
{
	int			*array;
	t_node		*head;

	head = STCK_A;
	array = ft_memalloc(sizeof(int) * LEN);
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

int				check_if_unsorted(t_ps_obj *obj, int i)
{
	t_node		*unsorted_input;

	unsorted_input = STCK_A;
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
