/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:05:47 by bprado         #+#    #+#                */
/*   Updated: 2020/02/13 20:56:42 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

// void	read_stdin(void)
// {
// 	char *str;

// 	str = NULL;
// 	while (get_next_line(0, &str) > 0)
// 		printf("%s\n", str);
// 	// use ft_printf above


// }


void	create_stack(t_checker *checker)
{
	int 	i;

	i = LENGTH;
	A = malloc(sizeof(int) * LENGTH);
	B = malloc(sizeof(int) * LENGTH);

	// populate a_stack
	while (i > 0)
	{
		if (ft_atoi(ARGV[i] == 0 && ARGV[i][0] != '0'))
		{
			// malloced content must be freed
			break ; 
		}
		A[i - 1] = ft_atoi(ARGV[i]);
		i--;
	}

	// check instructions are valid
	// then perform instruction

	// i = 0;
	while (i < 6)
		printf("%d\n", A[i++]);
}

int		main(int argc, char** argv)
{
	// int		*a_stack;
	// int		*b_stack;
	t_checker	checker;
	ft_bzero(&checker, sizeof(t_checker));
	// checker = {0};
	checker.len = argc - 1;
	checker.argv = argv;
	if (argc < 2 && !argv)
		return (0);

	// create array of ints from command line args
	create_stack(&checker);
	




	// read_stdin();

	return (1);
}

