/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado         #+#    #+#                */
/*   Updated: 2020/02/24 20:49:18 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		init_checker(t_checker *checker, int argc, char **argv);
t_node		*first_node(t_node *head, t_checker *checker);
t_node		*create_lnkd_lst(t_checker *checker, int size);
void		print_content_lnkd_list(t_checker *checker);
char		*read_stdin(void);
void		manipulate_stacks(t_checker *checker);




int			main(int argc, char **argv)
{
	t_checker   checker;
	char 		*str;

	ft_bzero(&checker, sizeof(checker));
	if (argc < 2 || !argv)
	{
		printf("Error\n");
		return (0);
	}
	checker.len_a = argc - 1;
	checker.argv = argv;
	checker.stck_a = create_lnkd_lst(&checker, argc - 1);
	// init_checker(&checker, argc, argv);
	print_content_lnkd_list(&checker);


	manipulate_stacks(&checker);

	print_content_lnkd_list(&checker);


	return (0);
}

// must delete old node, reconnect links of old node correctly
// and create new node, connect new links of new node correctly
// t_node		*delete_and_create_node(t_node *old, t_node *new)
// {
// 	t_node		*head;
// 	t_node		*temp;
// 	int			i;

// 	// new malloced node, head is address
// 	head = malloc(sizeof(t_node));
// 	ft_bzero(STCK_A, sizeof(t_node));
// 	head->data = old->data;

// 	temp = malloc(sizeof(t_node));
// 	NEXT_A = temp;
// 	temp->previous = STCK_A;
// 	STCK_A = temp;
// 	DATA_A = ft_atoi(ARGV[i]);
// 	NEXT_A = head;
// 	NEXT_A->previous = STCK_A;
// 	return (head);

// }




t_node		*create_lnkd_lst(t_checker *checker, int size)
{
	t_node		*head;
	t_node		*temp;
	int			i;

	head = malloc(sizeof(t_node));
	STCK_A = head;
	ft_bzero(STCK_A, sizeof(t_node));
	i = 1;
	--size;
	while (size)
	{
		DATA_A = ft_atoi(ARGV[i]);
		temp = malloc(sizeof(t_node));
		NEXT_A = temp;
		temp->previous = STCK_A;
		STCK_A = temp;
		--size;
		++i;
	}
	DATA_A = ft_atoi(ARGV[i]);
	NEXT_A = head;
	NEXT_A->previous = STCK_A;
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
	while (STCK_A != head && STCK_A != NULL && i < 100)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_A", i++, DATA_A, STCK_A);
		STCK_A = STCK_A->next;
	}
	printf("\n\n");

	i = 0;
	// head = STCK_B;
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
	// STCK_B = STCK_B->next;
	// printf("HEAD address: %p\nSTCK address: %p data: %d\n\n\n", head, STCK_B, DATA_B);
}



/*
	assign data
	if b not empty
		

 */
