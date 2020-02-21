/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado         #+#    #+#                */
/*   Updated: 2020/02/21 19:13:55 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		swap(t_node *stack, int length);
void		push(t_node **stack1, t_node **stack2);


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
	{
		printf("%s\n", operation);
		push(&STCK_A, &STCK_B);
	}
	else if (!ft_memcmp("pb", operation, 2))
	{
		printf("%s\n", operation);
		push(&STCK_B, &STCK_A);
		printf("stack a: %p  stack b: %p\n", STCK_A, STCK_B);
	}
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


// void		push(t_node *stack, t_checker *checker)
// {
// 	t_node		*temp;

// 	temp = malloc(sizeof(t_node));
// 	// assign data
// 	temp->data = DATA_B;
// 	temp->next = STCK_A;
// 	// adjust stack_a pointers
// 	temp->previous = PREV_A;
// 	PREV_A->next = temp;
// 	PREV_A = temp;
// 	// head of stack_a placed on new node
// 	STCK_A = temp;
// 	// adjust stack_b pointers
// 	PREV_B->next = NEXT_B;
// 	NEXT_B->previous = PREV_B;
// 	// free loose node
// 	temp = STCK_B;
// 	free(temp);
// 	// head of stack_b placed on next node;
// 	STCK_B = NEXT_B;
// }


// 			push(		STCK_B, 		STCK_A);
void		push(t_node **stack1, t_node **stack2)
{
	t_node		*temp;

	if (*stack2 != NULL)
	{
		// assign data
		temp->data = (*stack2)->data;
		// adjust stack_a pointers
		if (*stack1 != NULL)
		{
			temp->next = *stack1;
			temp->previous = (*stack1)->previous;
			(*stack1)->previous->next = temp;
			(*stack1)->next->previous = temp;
			(*stack1)->previous = temp;
		}
		else
		{
			temp->previous = temp;
			temp->next = temp;
		}
		// head of stack_1 placed on new node
		*stack1 = temp;
		// adjust stack_2 pointers
		(*stack2)->previous->next = (*stack2)->next;
		(*stack2)->next->previous = (*stack2)->previous;
		// free loose node
		temp = *stack2;
		// head of stack_b placed on next node;
		if ((*stack2)->next != *stack2)
			*stack2 = (*stack2)->next;
		else if ((*stack2)->next == *stack2)
			*stack2 = NULL;
	}
}