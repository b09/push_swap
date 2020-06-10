/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/10 13:00:06 by bprado        ########   odam.nl         */
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
	int			j;

	i = 1;
	while (i < argc && argv[i][j] != 0)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] !=\
			'-') || (j > 0 && argv[i][j] == '-' && argv[i][j - 1] != ' '))
				return (0);
			++j;
		}
		++i;
	}
	if (i == 1 && j == 0)
		return (0);
	return (1);
}

static int		remove_spaces_digits_minus(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-')
		++i;
	while (ft_isdigit(str[i]))
		++i;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

static void		create_lnkd_list_help(t_ps *ps)
{
	t_node		*temp;

	++ps->len;
	temp = ft_memalloc(sizeof(t_node));
	ps->stck_a->next = temp;
	temp->previous = ps->stck_a;
	ps->stck_a = ps->stck_a->next;
}

t_node			*create_lnkd_lst(t_ps *ps, int k, t_node *head)
{
	int			i;
	int			j;

	head = ft_memalloc(sizeof(t_node));
	ps->stck_a = head;
	ps->stck_a->previous = NULL;
	i = 1;
	ps->len = 1;
	while (i <= k)
	{
		j = 0;
		while (ps->argv[i][j] != 0)
		{
			ps->stck_a->data = ft_atoi(&ps->argv[i][j]);
			j += remove_spaces_digits_minus(&ps->argv[i][j]);
			ps->stck_a->next = NULL;
			if (ps->argv[i][j])
				create_lnkd_list_help(ps);
		}
		++i;
		if (i <= k && ps->argv[i])
			create_lnkd_list_help(ps);
	}
	ps->stck_a->next = NULL;
	return (head);
}
