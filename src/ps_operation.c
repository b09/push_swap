/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado         #+#    #+#                */
/*   Updated: 2020/02/20 18:18:30 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		manipulate_stacks(t_checker *checker)
{
	char 		*operation;
	char		i;

	i = 1;
	while (get_next_line(0, &operation) > 0 && i)
		i = execute_op_code(operation, checker);
	if (i == 0)
		printf("Error\n");
}

int			execute_op_code2(char *operation, t_checker *checker)
{
	if (!ft_memcmp("ra", operation, 2))
		STCK_A = NEXT_A;
	else if (!ft_memcmp("rb", operation, 2))
		STCK_B = NEXT_B;
	else if (!ft_memcmp("rr", operation, 2))
    {
		STCK_A = NEXT_A;
		STCK_B = NEXT_B;
    }
	else if (!ft_memcmp("rra", operation, 3))
		STCK_A = PREV_A;
	else if (!ft_memcmp("rrb", operation, 3))
		STCK_B = PREV_B;
	else if (!ft_memcmp("rrr", operation, 3))
    {
		STCK_A = PREV_A;
		STCK_B = PREV_B;
    }
	else
		return (0);
	return (1);
}

int			execute_op_code(char *operation, t_checker *checker)
{
	if (!ft_memcmp("sa", operation, 2))
		swap(STCK_A, LEN_A);
	else if (!ft_memcmp("sb", operation, 2))
		swap(STCK_B, LEN_B);
	else if (!ft_memcmp("ss", operation, 2))
    {
		swap(STCK_A, LEN_A);
		swap(STCK_B, LEN_B);
    }
	else if (!ft_memcmp("pa", operation, 2))
		printf("%s\n", operation);
	else if (!ft_memcmp("pb", operation, 2))
		printf("%s\n", operation);
	else
		return (execute_op_code2(operation, checker));
	return (1);
}


void		swap(t_node *stack, int length)
{
	if (stack && length > 1)
	{
		stack->data ^= stack->next->data;
		stack->next->data ^= stack->data;
		stack->data ^= stack->next->data;
	}
}