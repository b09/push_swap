/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado         #+#    #+#                */
/*   Updated: 2020/02/25 19:40:01 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int				main(int argc, char **argv)
{
	t_checker	checker;
	char		*str;

	ft_bzero(&checker, sizeof(checker));
	if (argc < 2 || !argv)
		return (0);
	if (!validate_argv(argc, argv))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	checker.len_a = argc - 1;
	checker.argv = argv;
	checker.stck_a = create_lnkd_lst(&checker, argc - 1);
	print_content_lnkd_list(&checker);
	manipulate_stacks(&checker);
	verify_order_of_data(&checker);
	delete_lnkd_list(&(checker.stck_a));
	printf("address of stack_a after freeing list: %p\n", checker.stck_a);
	return (0);
}

void			verify_order_of_data(t_checker *checker)
{
	int			i;

	i = STCK_A->data;
	while (STCK_A->next != NULL)
	{
		if (i >= STCK_A->next->data)
		{
			ft_putstr("KO\n");
			return ;
		}
		STCK_A = STCK_A->next;
		i = STCK_A->data;
	}
	if (STCK_B == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void			delete_lnkd_list(t_node **list)
{
	if ((*list)->next)
		delete_lnkd_list(&(*list)->next);
	free(*list);
	*list = NULL;
}

int				validate_argv(int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
			return (0);
		++i;
	}
	return (1);
}

t_node			*create_lnkd_lst(t_checker *checker, int size)
{
	t_node		*head;
	t_node		*temp;
	int			i;

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
	return (head);
}

char			*read_stdin(void)
{
	char		*str;

	str = NULL;
	while (get_next_line(0, &str) > 0)
		return (str);
	return (NULL);
}
