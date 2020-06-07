/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/07 16:35:28 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** add everything to stack_a in order to delete all links
** it is possible to create the linked list and have invalid instructions
** from stdin, in which case, all nodes should be added back to stack_a
** in order to
*/

void			delete_lnkd_list(t_ps *ps, t_node **list)
{
	while (ps->stck_b != NULL)
	{
		push(&ps->stck_b, &ps->stck_a, ps);
		navigate_thru_lnkd_lst(&ps->stck_a, 0);
		navigate_thru_lnkd_lst(&ps->stck_b, 0);
	}
	if (*list != NULL)
	{
		if ((*list)->next)
			delete_lnkd_list(ps, &(*list)->next);
		free(*list);
		*list = NULL;
	}
}

/*
**	must be able to take in a single string containing all args
**	argc is at least 2 at this point
*/

int				validate_argv(int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc && argc > 2)
	{
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		++i;
	}
	i = 0;
	while (argc == 2 && argv[1][i] != 0)
	{
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}

static int		remove_spaces_digits_minus(char *str)
{
	int			i;

	i = 0;
	while (ft_isdigit(str[i]))
		++i;
	while (str[i] == ' ')
		++i;
	if (str[i] == '-')
		++i;
	return (i);
}

t_node			*create_lnkd_lst_single_string(t_ps *ps)
{
	t_node		*head;
	t_node		*temp;
	int			i;

	head = ft_memalloc(sizeof(t_node));
	ps->stck_a = head;
	ps->stck_a->previous = NULL;
	i = 0;
	while (ps->argv[1][i] != 0)
	{
		ps->stck_a->data = ft_atoi(&ps->argv[1][i]);
		i += remove_spaces_digits_minus(&ps->argv[1][i]);
		if (ps->argv[1][i])
		{
			++ps->len;
			temp = ft_memalloc(sizeof(t_node));
			ps->stck_a->next = temp;
			temp->previous = ps->stck_a;
			ps->stck_a = ps->stck_a->next;
		}
	}
	if (i == 0 && ft_strlen(ps->argv[1]))
		ps->stck_a->data = ft_atoi(&ps->argv[1][i]);
	ps->stck_a->next = NULL;
	return (head);
}

t_node			*create_lnkd_lst(t_ps *ps, int size, t_node *head)
{
	int			i;

	if (size != 1)
	{
		head = ft_memalloc(sizeof(t_node));
		ps->stck_a = head;
		ps->stck_a->previous = NULL;
		i = 1;
		--size;
		while (size)
		{
			ps->stck_a->data = ft_atoi(ps->argv[i]);
			ps->stck_a->next = ft_memalloc(sizeof(t_node));
			ps->stck_a->next->previous = ps->stck_a;
			ps->stck_a = ps->stck_a->next;
			++i;
			--size;
		}
		ps->stck_a->data = ft_atoi(ps->argv[i]);
		ps->stck_a->next = NULL;
	}
	else
		head = create_lnkd_lst_single_string(ps);
	return (head);
}
