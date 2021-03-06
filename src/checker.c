/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/19 15:01:30 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		execute_op_code2(char *operation, t_ps *ps)
{
	if (!ft_memcmp("ra", operation, 3))
		rotate(&ps->stck_a, 1, ps);
	else if (!ft_memcmp("rb", operation, 3))
		rotate(&ps->stck_b, 1, ps);
	else if (!ft_memcmp("rr", operation, 3))
	{
		rotate(&ps->stck_a, 1, ps);
		rotate(&ps->stck_b, 1, ps);
	}
	else if (!ft_memcmp("rra", operation, 4))
		rotate(&ps->stck_a, 0, ps);
	else if (!ft_memcmp("rrb", operation, 4))
		rotate(&ps->stck_b, 0, ps);
	else if (!ft_memcmp("rrr", operation, 4))
	{
		rotate(&ps->stck_a, 0, ps);
		rotate(&ps->stck_b, 0, ps);
	}
	else
		return (0);
	return (1);
}

static int		execute_op_code(char *operation, t_ps *ps)
{
	if (!ft_memcmp("sa", operation, 3))
		swap(ps->stck_a, 1, ps);
	else if (!ft_memcmp("sb", operation, 3))
		swap(ps->stck_b, 1, ps);
	else if (!ft_memcmp("ss", operation, 3))
	{
		swap(ps->stck_a, 1, ps);
		swap(ps->stck_b, 1, ps);
	}
	else if (!ft_memcmp("pa", operation, 3))
		push(&ps->stck_b, &ps->stck_a, ps);
	else if (!ft_memcmp("pb", operation, 3))
		push(&ps->stck_a, &ps->stck_b, ps);
	else
		return (execute_op_code2(operation, ps));
	return (1);
}

/*
**	add "print_content_lnkd_list(obj)" right after
**	"i = execute_op_code(operation, obj);" to view stack after every
**	operation
*/

static int		manipulate_stacks(t_ps *ps)
{
	char		*operation;
	char		i;

	i = 1;
	while (get_next_line(0, &operation) > 0 && i)
	{
		i = execute_op_code(operation, ps);
		if (i == 0)
		{
			ft_memdel((void*)&operation);
			delete_everything(ps, &ps->stck_a);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		ft_memdel((void*)&operation);
	}
	if (operation)
		ft_memdel((void*)&operation);
	return (1);
}

static void		verify_order_of_data(t_ps *ps)
{
	int			i;

	i = 0;
	if (ps->stck_a)
		i = ps->stck_a->data;
	while (ps->stck_a && ps->stck_a->next != NULL)
	{
		if (i >= ps->stck_a->next->data)
		{
			ft_putstr("KO\n");
			return ;
		}
		ps->stck_a = ps->stck_a->next;
		i = ps->stck_a->data;
	}
	if (ps->stck_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

/*
**	must validate strings of input; "1 2 3 4" as well as "1" "2" "3" "4"
**	print_content_lnkd_list(&obj);
**	notes:
**		min int				// done
**		valgrind leaking 24 bytes		// done
**		./checker 22 32 asdf    not catching error   // done
*/

int				main(int argc, char **argv)
{
	t_ps		ps;
	t_node		*head;

	head = NULL;
	ft_bzero(&ps, sizeof(ps));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
	{
		if (argc != 1)
			ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ps.len = argc - 1;
	ps.argv = argv;
	ps.stck_a = create_lnkd_lst(&ps, argc - 1, head);
	create_and_srt_array(&ps, 0);
	if (!repeats_in_sorted_array(&ps) && manipulate_stacks(&ps))
		verify_order_of_data(&ps);
	delete_everything(&ps, &(ps.stck_a));
}
