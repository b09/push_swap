/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado         #+#    #+#                */
/*   Updated: 2020/02/25 18:00:19 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		init_checker(t_checker *checker, int argc, char **argv);
t_node		*first_node(t_node *head, t_checker *checker);
t_node		*create_lnkd_lst(t_checker *checker, int size);
void		print_content_lnkd_list(t_checker *checker);
char		*read_stdin(void);
void		manipulate_stacks(t_checker *checker);
int			validate_argv(int argc, char **argv);
void		delete_lnkd_list(t_node **list);



// first argument is the top of the stack
int			main(int argc, char **argv)
{
	t_checker   checker;
	char 		*str;

	ft_bzero(&checker, sizeof(checker));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	checker.len_a = argc - 1;
	checker.argv = argv;
	checker.stck_a = create_lnkd_lst(&checker, argc - 1);

	print_content_lnkd_list(&checker);
	manipulate_stacks(&checker);

	delete_lnkd_list(&(checker.stck_a));

	printf("address of stack_a after freeing list: %p\n", checker.stck_a);
	return (0);
}

void		delete_lnkd_list(t_node **list)
{
	if ((*list)->next)
		delete_lnkd_list(&(*list)->next);
	free(*list);
	*list = NULL;
}


int			validate_argv(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
			return (0);
		++i;
	}
	return (1);
}




// argv has been checked for non-numbers as well as having at least one arg
t_node		*create_lnkd_lst(t_checker *checker, int size)
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




char	*read_stdin(void)
{
	char *str;

	str = NULL;
	while (get_next_line(0, &str) > 0)
		return (str);
	return (NULL);
}






//*********************  print linked list  ************************************

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
