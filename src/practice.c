/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:05:47 by bprado         #+#    #+#                */
/*   Updated: 2020/02/14 21:21:22 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

char	*read_stdin(void)
{
	char *str;

	str = NULL;
	while (get_next_line(0, &str) > 0)
		return (str);
	return (NULL);

}


void	test_func_pointer_aa(t_checker *checker)
{
	printf("special result, string value is aa!!!\n");
}

int		swap(int *a)
{
	return ((a[0] ^= a[1]) + (a[1] ^= a[0]) + (a[0] ^= a[1]));
}



// func_pointer	populate_func_pointer(char *str)
// {
// 	func_pointer arrpointer[INT16_MAX] = {
// 	arrpointer[*(short*)"sa"] = swap_a,
// 	arrpointer[*(short*)"sb"] = test_func_pointer_aa,
// 	arrpointer[*(short*)"ss"] = test_func_pointer_aa,
// 	arrpointer[*(short*)"pa"] = test_func_pointer_aa,
// 	arrpointer[*(short*)"pb"] = test_func_pointer_aa,
// 	arrpointer[*(short*)"ra"] = test_func_pointer_aa,
// 	arrpointer[*(short*)"rb"] = test_func_pointer_aa,
// 	arrpointer[*(short*)"rr"] = test_func_pointer_aa,
// 	};
// 	return (arrpointer[*(short*)str]);
// }

void	lots_of_ifs(t_checker *checker, char *str)
{
	(*(short*)str == *(short*)"sa") && swap(A);
	(*(short*)str == *(short*)"sb") && swap(B);
	// (*(short*)str == *(short*)"ss") && swap(A[0], A[1]) && swap(B[0], B[1]);
	// (*(short*)str == *(short*)"pa") && swap(A[0], A[1]);
	// (*(short*)str == *(short*)"pb") && swap(A[0], A[1]);
	// (*(short*)str == *(short*)"ra") && swap(A[0], A[1]);
	// (*(short*)str == *(short*)"rb") && swap(A[0], A[1]);
	return ;
}


void	create_stack(t_checker *checker)
{
	int 			i;
	func_pointer	func_pointer;

	i = LENGTH;
	A = malloc(sizeof(int) * LENGTH);
	B = malloc(sizeof(int) * LENGTH);
	// func_pointer = populate_func_pointer(read_stdin());


	// populate a_stack
	while (i > 0)
	{
		if (ft_atoi(ARGV[i]) == 0 && ARGV[i][0] != '0')
		{
			// malloced content must be freed
			break ; 
		}
		A[i - 1] = ft_atoi(ARGV[i]);
		i--;
	}

	i = LENGTH;
	while (i--)
		printf("first: %d\n", A[i]);


	// printf("string is: %s", read_stdin());
	lots_of_ifs(checker, read_stdin());


	// if (func_pointer != NULL)
	// 	func_pointer(checker);
	// else
	// 	printf("Not valid command\n");


	i = LENGTH;
	while (i--)
		printf("second: %d\n", A[i]);
	
	// check instructions are valid
	// then perform instruction

	

}







int		main(int argc, char** argv)
{
	t_checker	checker;
	ft_bzero(&checker, sizeof(t_checker));

	checker.len = argc - 1;
	checker.argv = argv;
	if (argc < 2 && !argv)
		return (0);

	// create array of ints from command line args
	create_stack(&checker);
	

	return (1);
}







// if strlen < 4
// 	if strlen == 3 && *(short*)str == "aa"

