/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado         #+#    #+#                */
/*   Updated: 2020/06/02 18:25:25 by bprado        ########   odam.nl         */
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
	while (STCK_B != NULL)
	{
		push(&STCK_B, &STCK_A, obj);
		navigate_thru_lnkd_lst(&STCK_A, 0);
		navigate_thru_lnkd_lst(&STCK_B, 0);
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
			ft_putstr_fd("Error 1\n", 2);
			return (0);
		}
		++i;
	}
	i = 0;
	while (argc == 2 && argv[1][i] != 0)
	{
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
		{
			ft_putstr_fd("Error 2\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}

int				remove_spaces_digits_minus(char *str)
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
	STCK_A = head;
	PREV_A = NULL;
	i = 0;
	while (ARGV[1][i] != 0)
	{
		DATA_A = ft_atoi(&ARGV[1][i]);
		i += remove_spaces_digits_minus(&ARGV[1][i]);
		if (ARGV[1][i])
		{
			++LEN;
			temp = ft_memalloc(sizeof(t_node));
			NEXT_A = temp;
			temp->previous = STCK_A;
			STCK_A = NEXT_A;
		}
	}
	if (i == 0 && ft_strlen(ARGV[1]))
		DATA_A = ft_atoi(&ARGV[1][i]);
	NEXT_A = NULL;
	return (head);
}

t_node			*create_lnkd_lst(t_ps_obj *obj, int size)
{
	t_node		*head;
	t_node		*temp;
	int			i;

	if (size != 1)
	{
		head = ft_memalloc(sizeof(t_node));
		STCK_A = head;
		PREV_A = NULL;
		i = 1;
		--size;
		while (size)
		{
			DATA_A = ft_atoi(ARGV[i]);
			temp = ft_memalloc(sizeof(t_node));
			NEXT_A = temp;
			temp->previous = STCK_A;
			STCK_A = NEXT_A;
			--size;
			++i;
		}
		DATA_A = ft_atoi(ARGV[i]);
		NEXT_A = NULL;
	}
	else
		head = create_lnkd_lst_single_string(obj);
	return (head);
}

/*
 ** swap(), unlink_node(), insert_node(), and rotate() may be useful for
 **	push_swap.c
*/

void			swap(t_node *stack, char swap_going_down_list, t_ps_obj *obj)
{
	if (stack == STCK_A)
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
	if (stack == NULL)
		return ;
	if (swap_going_down_list && stack->next != NULL)
	{
		stack->data ^= stack->next->data;
		stack->next->data ^= stack->data;
		stack->data ^= stack->next->data;
		return ;
	}
	stack->data ^= stack->previous->data;
	stack->previous->data ^= stack->data;
	stack->data ^= stack->previous->data;
}

/*
**	must account for final node
*/

t_node			*unlink_node(t_node **node, char get_first_node)
{
	t_node		*unlinked_node;

	unlinked_node = *node;
	if (*node == NULL || ((*node)->next == NULL && (*node)->previous == NULL))
	{
		*node = NULL;
	}
	else if (get_first_node)
	{
		if ((*node)->next != NULL)
			(*node)->next->previous = NULL;
		*node = (*node)->next;
		unlinked_node->next = NULL;
	}
	else if (!get_first_node)
	{
		if ((*node)->previous != NULL)
			(*node)->previous->next = NULL;
		*node = (*node)->previous;
	}
	return (unlinked_node);
}

void			insert_node(t_node *loose_node, t_node **dest, char add_to_end)
{
	if (loose_node == NULL)
		return ;
	if (*dest != NULL && !add_to_end)
	{
		loose_node->next = *dest;
		loose_node->previous = NULL;
		(*dest)->previous = loose_node;
		*dest = loose_node;
	}
	else if (*dest != NULL && add_to_end)
	{
		loose_node->previous = *dest;
		loose_node->next = NULL;
		(*dest)->next = loose_node;
		*dest = loose_node;
	}
	else
	{
		loose_node->next = NULL;
		loose_node->previous = NULL;
		*dest = loose_node;
	}
}

void			push(t_node **src, t_node **dest, t_ps_obj *obj)
{
	insert_node(unlink_node(src, 1), dest, 0);
	if (*src == STCK_A)
	{
		ft_putstr("pb\n");
		++(MEDS[MED_I]);
		--LEN;
		++LEN_B;
	}
	else
	{
		ft_putstr("pa\n");
		--LEN_B;
		++LEN;
	}
}

/*
**	should rewrite to traverse linked list up to specified point, which would be
**	necessary for the divide_a && divide_b funcs to not interate over the entire
**	linked list, rather just the sections that are unsorted
*/

void			navigate_thru_lnkd_lst(t_node **node, char go_to_end)
{
	if (go_to_end)
	{
		while ((*node)->next != NULL)
			*node = (*node)->next;
		return ;
	}
	else
	{
		while ((*node)->previous != NULL)
			*node = (*node)->previous;
		return ;
	}
}

void			unsrt_bttm_macro(t_node **node, char insert_end, t_ps_obj *obj)
{
	if (insert_end)
	{
		if (*node == STCK_A)
			++UNSRT_BTTM_A;
		else if (*node == STCK_B)
			++UNSRT_BTTM_B;
	}
	else
	{
		if (*node == STCK_A)
			--UNSRT_BTTM_A;
	}
}

void			rotate(t_node **node, char insert_at_end, t_ps_obj *obj)
{
	t_node		*loose_node;

	if (*node == NULL || ((*node)->next == NULL && (*node)->previous == NULL))
		return ;
	if (!insert_at_end)
		navigate_thru_lnkd_lst(node, 1);
	loose_node = unlink_node(node, insert_at_end);
	navigate_thru_lnkd_lst(node, insert_at_end);
	insert_node(loose_node, node, insert_at_end);
	navigate_thru_lnkd_lst(node, 0);
	if (*node != NULL && insert_at_end == 0)
		ft_putchar('r');
	(*node == STCK_A) ? ft_putstr("ra\n") : ft_putstr("rb\n");
	unsrt_bttm_macro(node, insert_at_end, obj);
}

void			print_medians(t_ps_obj *obj)
{
	int			i;

	i = 0;
	while (i < 10)
	{
		printf("median[%d]:%d\n", i, MEDS[i]);
		i++;
	}
}

void			print_content_lnkd_list(t_ps_obj *obj)
{
	t_node		*head;
	int			i;

	i = 1;
	head = STCK_A;
	printf("STCK_A[0]:%d addr: %p\n", DATA_A, STCK_A);
	STCK_A = STCK_A->next;
	while (STCK_A != NULL)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_A", i++, DATA_A, STCK_A);
		STCK_A = STCK_A->next;
	}
	printf("\n\n");
	STCK_A = head;
	i = 0;
	head = STCK_B;
	while (STCK_B != NULL && i < 100)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_B", i++, DATA_B, STCK_B);
		STCK_B = STCK_B->next;
		if (STCK_B == NULL)
			printf("\n");
	}
	STCK_B = head;
}
