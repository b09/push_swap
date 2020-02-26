/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado         #+#    #+#                */
/*   Updated: 2020/02/26 17:06:05 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int				main(int argc, char **argv)
{
	t_checker	checker;
	char		*str;

	ft_bzero(&checker, sizeof(checker));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (0);
	checker.len_a = argc - 1;
	checker.argv = argv;
	checker.stck_a = create_lnkd_lst(&checker, argc - 1);
	print_content_lnkd_list(&checker);
	if (!manipulate_stacks(&checker))
		return (0);
	verify_order_of_data(&checker);
	delete_lnkd_list(&checker);
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

/*
** add everything to stack_a in order to delete all links
** it is possible to create the linked list and have invalid instructions
** from stdin, in which case, all nodes should be added back to stack_a
** in order to 
*/
void			delete_lnkd_list(t_checker *checker)
{
	while (STCK_B != NULL)
		insert_node(unlink_node(&STCK_B), &STCK_A);
	if (STCK_A != NULL)
	{
		if (STCK_A->next)
			delete_lnkd_list(&STCK_A->next);
		free(STCK_A);
		STCK_A = NULL;

	}
}

int				validate_argv(int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
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



void		print_content_lnkd_list(t_checker *checker)
{
	t_node		*head;


	head = STCK_A;
	printf("STCK_A[0]:%d addr: %p\n", DATA_A, STCK_A);
	STCK_A = STCK_A->next;

	int i = 1;
	while (STCK_A != NULL && i < 100)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_A", i++, DATA_A, STCK_A);
		STCK_A = STCK_A->next;
	}
	printf("\n\n");

	STCK_A = head;
	i = 0;
	head = STCK_B;
	// printf("STCK_B[0]addr: %p", STCK_B);
	// if (STCK_B != NULL)
	// 	printf(" data: %d  next: %p\n", DATA_B, STCK_B->next);
	// else
	// 	printf("\n");
	// // STCK_B = STCK_B->next;
	// // printf("head of b: %p\n", STCK_B);
	while (STCK_B != NULL && i < 10)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_B", i++, DATA_B, STCK_B);
		STCK_B = STCK_B->next;
	}
	STCK_B = head;
	// STCK_B = STCK_B->next;
	// printf("HEAD address: %p\nSTCK address: %p data: %d\n\n\n", head, STCK_B, DATA_B);
}
