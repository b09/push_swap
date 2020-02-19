/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado         #+#    #+#                */
/*   Updated: 2020/02/19 21:06:30 by bprado        ########   odam.nl         */
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



	// once string has content, perform op code on stack
	// str = "";
	// while (str != NULL)
	// {
	// 	printf("%s\n", str);
	// 	str = read_stdin();
	// }

	manipulate_stacks(&checker);



	return (0);
}


void		manipulate_stacks(t_checker *checker)
{
	char 		*operation;

	operation = read_stdin();
	while (operation != NULL)
	{
		if (!ft_memcmp("sa", operation, 2))
			swap()
	}
}



// printf("line: %s, size: %d, argv: %d\n", __func__, LEN_A, ft_atoi(ARGV[1]));


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
	printf("first number:%d\n", DATA_A);
	STCK_A = STCK_A->next;


	while (STCK_A != head)
	{
		printf("number:%d\n", DATA_A);
		STCK_A = STCK_A->next;
	}

	printf("HEAD address: %p\nSTCK address: %p\n", head, STCK_A);
	
}
