/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_input_validation.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/18 19:29:08 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	func() will ensure that string of ints is not more characters than what
**	INT_MAX and INT_MIN could be. It also ensures that there is at least one
**	character which is a number. func() is recursive until it reaches the end
**	of string, as multiple ints could be in a string
**	ex: "434384 222222222222" <== second int in str exceeds permitted length
*/

int				check_length_of_input(char *str, int iterations)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] && !ft_isdigit(str[i]) && str[i] != '-')
		++i;
	j += str[i] == '-' ? 1 : 0;
	i += str[i] == '-' ? 1 : 0;
	while (str[i] && ft_isdigit(str[i]) && j < 13)
	{
		++i;
		++j;
	}
	if ((j > 11) || (j == 0 && !str[i] && iterations == 0))
		return (0);
	if (ft_atol(&str[i - j]) > INT32_MAX || ft_atol(&str[i - j]) < INT32_MIN)
		return (0);
	if (str[i])
		return (check_length_of_input(&str[i], iterations + 1));
	return (1);
}

/*
**	must be able to take in a single string containing all args
**	argc is at least 2 at this point
**	the first while has to check whether the current line is nothing(ex: "")
**	an escape if so, but if not, continue checking subsequent lines
**	this means the assigment of j = 0 should be at the end of the first while
**	loop instead of right after it.
*/

int				validate_argv(int argc, char **argv)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (i < argc && argv[i][j] != 0)
	{
		while (argv[i][j] != 0)
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] !=\
			'-') || (j > 0 && argv[i][j] == '-' && argv[i][j - 1] != ' '))
				return (0);
			++j;
		}
		if (check_length_of_input(argv[i], 0) == 0)
			return (0);
		++i;
		j = 0;
	}
	if (i != argc)
		return (0);
	return (1);
}

static int		assign_data(char *str, t_ps *ps)
{
	int			i;

	i = 0;
	while (str[i] == ' ')
		++i;
	if (str[i] == '-' || ft_isdigit(str[i]))
		ps->stck_a->data = ft_atoi(&str[i]);
	if (str[i] == '-')
		++i;
	while (ft_isdigit(str[i]))
		++i;
	while (str[i] == ' ')
		++i;
	return (i);
}

static void		create_lnkd_list_help(t_ps *ps, char *str)
{
	t_node		*temp;
	int			i;

	i = 0;
	while (str[i] == ' ')
		++i;
	if (str[i])
	{
		++ps->len;
		temp = ft_memalloc(sizeof(t_node));
		ps->stck_a->next = temp;
		temp->previous = ps->stck_a;
		ps->stck_a = ps->stck_a->next;
	}
}

/*
**	validate_argv() has ensured that at least one character is every str is
**	an int, if statement in main has ensured that there is at least one str
**	(represented by argument argv_lines if func()), so the malloced 'head'
**	will always go through both while loops  on its first iteration and reach
**	assign_data(), where the head's final member 'data' will be assigned.
*/

t_node			*create_lnkd_lst(t_ps *ps, int argv_lines, t_node *head)
{
	int			i;
	int			j;

	head = ft_memalloc(sizeof(t_node));
	ps->stck_a = head;
	ps->stck_a->previous = NULL;
	i = 1;
	ps->len = 1;
	while (i <= argv_lines)
	{
		j = 0;
		while (ps->argv[i][j] != 0)
		{
			j += assign_data(&ps->argv[i][j], ps);
			ps->stck_a->next = NULL;
			if (ps->argv[i][j])
				create_lnkd_list_help(ps, &ps->argv[i][j]);
		}
		++i;
		if (i <= argv_lines && ps->argv[i])
			create_lnkd_list_help(ps, ps->argv[i]);
	}
	ps->stck_a->next = NULL;
	return (head);
}
