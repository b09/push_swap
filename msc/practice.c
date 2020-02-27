/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:05:47 by bprado         #+#    #+#                */
/*   Updated: 2020/02/27 14:03:58 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// char	*read_stdin(void)
// {
// 	char *str;

// 	str = NULL;
// 	while (get_next_line(0, &str) > 0)
// 		return (str);
// 	return (NULL);

// }


// int		swap(int *a, int length)
// {
// 	if (a && length > 1)
// 	{
// 		a[0] ^= a[1];
// 		a[1] ^= a[0];
// 		a[0] ^= a[1];
// 	}
// 	return (1);
// }





// int		swap2(int *a, int *b, int pos)
// {
// 	// at index [(pos % len)]
// 	if (a && length > 1)
// 	{
// 		*a ^= *b;
// 		*b ^= *a;
// 		*a ^= *b;
// 	}
// 	return (1);
// }





// int		push(char push, t_checker *checker)
// {
// 	// if push, then pa, esle pb
// 	// at index [(pos % len)]
// 	if (push && LEN_A > 0 && LEN_B > 0)
// 	{
// 		(A[IND_A] ^= B[IND_B]) + (A[IND_A] ^= B[IND_B]) + (A[IND_A] ^= B[IND_B]);
// 		--LEN_B;
// 		++B_pos;
// 	}
// 	else if (!push && LEN_A > 0 && LEN_B > 0)
// 	{
// 		(A[IND_A] ^= B[IND_B]) + (A[IND_A] ^= B[IND_B]) + (A[IND_A] ^= B[IND_B]);
// 		--LEN_B;
// 		++B_pos;
// 	}
// 	return (1);
// }

// // how can swap be used if the position variable is at the end of the int array?
// void	rotate(char rotate, int *pos, int len)
// {
// 	if (rotate)
// 	{
// 		if (*pos < len)
// 			++(*pos);
// 		else if (*pos == len)
// 			*pos = 0;
// 	}
// 	else
// 	{
// 		if (*pos > 0)
// 			--(*pos);
// 		else if (*pos == 0)
// 			*pos == len;
// 	}
// }






// // perform operations from stdin
// void	lots_of_ifs(t_checker *checker, char *str)
// {
// 	(*(short*)str == *(short*)"sa") && swap(A, LEN_A);
// 	(*(short*)str == *(short*)"sb") && swap(B, LEN_B);
// 	(*(short*)str == *(short*)"ss") && swap(A, LEN_A) && swap(B[0], B[1]);
// 	// (*(short*)str == *(short*)"pa") && swap(A[0], A[1]);
// 	// (*(short*)str == *(short*)"pb") && swap(A[0], A[1]);
// 	// (*(short*)str == *(short*)"ra") && swap(A[0], A[1]);
// 	// (*(short*)str == *(short*)"rb") && swap(A[0], A[1]);
// 	return ;
// // func_pointer	populate_func_pointer(char *str)
// // {
// // 	func_pointer arrpointer[INT16_MAX] = {
// // 	arrpointer[*(short*)"sa"] = swap_a,
// // 	arrpointer[*(short*)"sb"] = test_func_pointer_aa,
// // 	arrpointer[*(short*)"ss"] = test_func_pointer_aa,
// // 	arrpointer[*(short*)"pa"] = test_func_pointer_aa,
// // 	arrpointer[*(short*)"pb"] = test_func_pointer_aa,
// // 	arrpointer[*(short*)"ra"] = test_func_pointer_aa,
// // 	arrpointer[*(short*)"rb"] = test_func_pointer_aa,
// // 	arrpointer[*(short*)"rr"] = test_func_pointer_aa,
// // 	};
// // 	return (arrpointer[*(short*)str]);
// // }
// }

// // create 2 arrays stacks for ints received as command line args
// void	create_stack(t_checker *checker)
// {
// 	int 			i;
// 	func_pointer	func_pointer;

// 	i = LENGTH;
// 	A = malloc(sizeof(int) * LENGTH);
// 	B = malloc(sizeof(int) * LENGTH);


// 	// populate a_stack
// 	while (i > 0)
// 	{
// 		if (ft_atoi(ARGV[i]) == 0 && ARGV[i][0] != '0')
// 		{
// 			// malloced content must be freed
// 			break ; 
// 		}
// 		A[i - 1] = ft_atoi(ARGV[i]);
// 		i--;
// 	}

// 	i = LENGTH;
// 	while (i--)
// 		printf("first: %d\n", A[i]);


// 	// printf("string is: %s", read_stdin());
// 	lots_of_ifs(checker, read_stdin());


// 	// if (func_pointer != NULL)
// 	// 	func_pointer(checker);
// 	// else
// 	// 	printf("Not valid command\n");


// 	i = LENGTH;
// 	while (i--)
// 		printf("second: %d\n", A[i]);
	
// 	// check instructions are valid
// 	// then perform instruction

	

// }

// void 		*create_node(t_node *node, size_t size)
// {
// 	while (size > 0)
// 	{
// 		node = malloc(sizeof(t_node));
// 		node->data = 0;
// 		node->next = NULL;
// 		--size;
// 	}
// }
// /*
// 	starting node is created
// 	function is made to create the next node and connect it to the first

//  */
// void		create_linked_list(t_checker *checker)
// {
// 	t_node *node_a;
// 	t_node *node_b;

// 	node_a = malloc(sizeof(t_node));
// 	node_a->prev = NULL;



// 	// function malloc each node

// }




// int		main(int argc, char** argv)
// {
// 	t_checker	checker;
// 	ft_bzero(&checker, sizeof(t_checker));

// 	checker.len = argc - 1;
// 	checker.argv = argv;
// 	if (argc < 2 && !argv)
// 		return (0);

// 	// create array of ints from command line args
// 	create_stack(&checker);
	

// 	return (1);
// }


