/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/05 20:09:05 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		execute_op_code2(char *operation, t_ps_obj *obj)
{
	if (!ft_memcmp("ra", operation, 3))
		rotate(&obj->stck_a, 1, obj);
	else if (!ft_memcmp("rb", operation, 3))
		rotate(&obj->stck_b, 1, obj);
	else if (!ft_memcmp("rr", operation, 3))
	{
		rotate(&obj->stck_a, 1, obj);
		rotate(&obj->stck_b, 1, obj);
	}
	else if (!ft_memcmp("rra", operation, 4))
		rotate(&obj->stck_a, 0, obj);
	else if (!ft_memcmp("rrb", operation, 4))
		rotate(&obj->stck_b, 0, obj);
	else if (!ft_memcmp("rrr", operation, 4))
	{
		rotate(&obj->stck_a, 0, obj);
		rotate(&obj->stck_b, 0, obj);
	}
	else
		return (0);
	return (1);
}

static int		execute_op_code(char *operation, t_ps_obj *obj)
{
	if (!ft_memcmp("sa", operation, 3))
		swap(obj->stck_a, 1, obj);
	else if (!ft_memcmp("sb", operation, 3))
		swap(obj->stck_b, 1, obj);
	else if (!ft_memcmp("ss", operation, 3))
	{
		swap(obj->stck_a, 1, obj);
		swap(obj->stck_b, 1, obj);
	}
	else if (!ft_memcmp("pa", operation, 3))
		push(&obj->stck_b, &obj->stck_a, obj);
	else if (!ft_memcmp("pb", operation, 3))
		push(&obj->stck_a, &obj->stck_b, obj);
	else
		return (execute_op_code2(operation, obj));
	return (1);
}

/*
**	add "print_content_lnkd_list(obj)" right after
**	"i = execute_op_code(operation, obj);" to view stack after every
**	operation
*/

static int		manipulate_stacks(t_ps_obj *obj)
{
	char		*operation;
	char		i;

	i = 1;
	while (get_next_line(0, &operation) > 0 && i)
		i = execute_op_code(operation, obj);
	if (i == 0)
	{
		delete_lnkd_list(obj, &obj->stck_a);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static void		verify_order_of_data(t_ps_obj *obj)
{
	int			i;

	i = obj->stck_a->data;
	while (obj->stck_a->next != NULL)
	{
		if (i >= obj->stck_a->next->data)
		{
			ft_putstr("KO\n");
			return ;
		}
		obj->stck_a = obj->stck_a->next;
		i = obj->stck_a->data;
	}
	if (obj->stck_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

/*
**	must validate strings of input; "1 2 3 4" as well as "1" "2" "3" "4"
**	print_content_lnkd_list(&obj);
*/

int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	t_node		*head;

	head = NULL;
	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (0);
	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1, head);
	if (!manipulate_stacks(&obj))
		return (0);
	verify_order_of_data(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	return (0);
}
