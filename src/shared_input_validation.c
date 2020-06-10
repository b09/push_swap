/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_input_validation.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/10 19:02:42 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				check_length_of_input(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] && !ft_isdigit(str[i]))
		++i;
	while (str[i] && ft_isdigit(str[i]) && j < 12)
	{
		++i;
		++j;
	}
	if (j > 10)
		return (0);
	else if (ft_atol(&str[i - j]) > INT32_MAX || ft_atol(&str[i - j]) < INT32_MIN)
		return (0);
	return (1);
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
		if (check_length_of_input(argv[i]) == 0)
			return (0);
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

	while (str[i] == ' ')
		++i;
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
