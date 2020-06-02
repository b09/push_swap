/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado         #+#    #+#                */
/*   Updated: 2020/06/02 18:28:04 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				manipulate_stacks(t_ps_obj *obj)
{
	char		*operation;
	char		i;

	i = 1;
	while (get_next_line(0, &operation) > 0 && i)
	{
		i = execute_op_code(operation, obj);
		print_content_lnkd_list(obj);
	}
	if (i == 0)
	{
		delete_lnkd_list(obj, &STCK_A);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int				execute_op_code2(char *operation, t_ps_obj *obj)
{
	if (!ft_memcmp("ra", operation, 3))
		rotate(&STCK_A, 1, obj);
	else if (!ft_memcmp("rb", operation, 3))
		rotate(&STCK_B, 1, obj);
	else if (!ft_memcmp("rr", operation, 3))
	{
		rotate(&STCK_A, 1, obj);
		rotate(&STCK_B, 1, obj);
	}
	else if (!ft_memcmp("rra", operation, 4))
		rotate(&STCK_A, 0, obj);
	else if (!ft_memcmp("rrb", operation, 4))
		rotate(&STCK_B, 0, obj);
	else if (!ft_memcmp("rrr", operation, 4))
	{
		rotate(&STCK_A, 0, obj);
		rotate(&STCK_B, 0, obj);
	}
	else
		return (0);
	return (1);
}

int				execute_op_code(char *operation, t_ps_obj *obj)
{
	if (!ft_memcmp("sa", operation, 3))
		swap(STCK_A, 1, obj);
	else if (!ft_memcmp("sb", operation, 3))
		swap(STCK_B, 1, obj);
	else if (!ft_memcmp("ss", operation, 3))
	{
		swap(STCK_A, 1, obj);
		swap(STCK_B, 1, obj);
	}
	else if (!ft_memcmp("pa", operation, 3))
		push(&STCK_B, &STCK_A, obj);
	else if (!ft_memcmp("pb", operation, 3))
		push(&STCK_A, &STCK_B, obj);
	else
		return (execute_op_code2(operation, obj));
	return (1);
}
