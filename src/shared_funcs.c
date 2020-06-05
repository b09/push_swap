/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/05 20:12:23 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** add everything to stack_a in order to delete all links
** it is possible to create the linked list and have invalid instructions
** from stdin, in which case, all nodes should be added back to stack_a
** in order to
*/

void			delete_lnkd_list(t_ps_obj *obj, t_node **list)
{
	while (obj->stck_b != NULL)
	{
		push(&obj->stck_b, &obj->stck_a, obj);
		navigate_thru_lnkd_lst(&obj->stck_a, 0);
		navigate_thru_lnkd_lst(&obj->stck_b, 0);
	}
	if (*list != NULL)
	{
		if ((*list)->next)
			delete_lnkd_list(obj, &(*list)->next);
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

t_node			*create_lnkd_lst_single_string(t_ps_obj *obj)
{
	t_node		*head;
	t_node		*temp;
	int			i;

	head = ft_memalloc(sizeof(t_node));
	obj->stck_a = head;
	PREV_A = NULL;
	i = 0;
	while (obj->argv[1][i] != 0)
	{
		DATA_A = ft_atoi(&obj->argv[1][i]);
		i += remove_spaces_digits_minus(&obj->argv[1][i]);
		if (obj->argv[1][i])
		{
			++obj->len;
			temp = ft_memalloc(sizeof(t_node));
			NEXT_A = temp;
			temp->previous = obj->stck_a;
			obj->stck_a = NEXT_A;
		}
	}
	if (i == 0 && ft_strlen(obj->argv[1]))
		DATA_A = ft_atoi(&obj->argv[1][i]);
	NEXT_A = NULL;
	return (head);
}

t_node			*create_lnkd_lst(t_ps_obj *obj, int size, t_node *head)
{
	t_node		*temp;
	int			i;

	if (size != 1)
	{
		head = ft_memalloc(sizeof(t_node));
		obj->stck_a = head;
		PREV_A = NULL;
		i = 1;
		--size;
		while (size)
		{
			DATA_A = ft_atoi(obj->argv[i]);
			NEXT_A = ft_memalloc(sizeof(t_node));
			NEXT_A->previous = obj->stck_a;
			obj->stck_a = NEXT_A;
			++i;
			--size;
		}
		DATA_A = ft_atoi(obj->argv[i]);
		NEXT_A = NULL;
	}
	else
		head = create_lnkd_lst_single_string(obj);
	return (head);
}
