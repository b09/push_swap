/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:54:11 by bprado         #+#    #+#                */
/*   Updated: 2020/02/24 20:48:44 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		swap(t_node *stack, int length);
// void		push(t_node **dest, t_node **src);
void		push_b(t_checker *checker);
void	insert_node(t_node *src, t_node **dest);
void	unlink_node(t_node **node);


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
		// push(&STCK_A, &STCK_B);
	}
	else if (!ft_memcmp("pb", operation, 2))
	{
		printf("%s\n", operation);
		t_node *node_to_push = STCK_A;
		unlink_node(&STCK_A);
		insert_node(node_to_push, &STCK_B);

		// push(&STCK_B, &STCK_A);
		// push_b(checker);
		// printf("stack a: %p  stack b: %p\n", STCK_A, STCK_B);
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
// void		push(t_node **dest, t_node **src)
// {
// 	t_node		*temp;

// 	// printf("dest: %p  src: %p\n", *dest, *src);
// 	if (*src != NULL)
// 	{

// 		// temp->data = (*src)->data;

// 		if (*dest != NULL)
// 		{

// 			temp->next = *dest;
// 			temp->previous = (*dest)->previous;
// 			(*dest)->previous->next = temp;

// 			(*dest)->previous = temp;
// 		}
// 		else
// 		{

// 			temp->previous = temp;
// 			temp->next = temp;
// 		}

// 		*dest = temp;

// 		(*src)->previous->next = (*src)->next;
// 		(*src)->next->previous = (*src)->previous;

// 		if ((*src)->next != *src)
// 			*src = (*src)->next;
// 		else if ((*src)->next == *src)
// 			*src = NULL;
// 	}
// }



// void		push(t_node **dest, t_node **src)
// {
// 	t_node		**temp;

// 	// printf("dest: %p  src: %p\n", *dest, *src);
// 	if (*src != NULL)
// 	{
// 		temp = src;

// 		if (*dest != NULL)
// 		{

// 			(*temp)->next = *dest;
// 			(*temp)->previous = (*dest)->previous;
// 			(*dest)->previous->next = (*temp);

// 			(*dest)->previous = (*temp);
// 		}
// 		else
// 		{

// 			(*temp)->previous = (*temp);
// 			(*temp)->next = (*temp);
// 		}

// 		*dest = *temp;

// 		(*src)->previous->next = (*src)->next;
// 		(*src)->next->previous = (*src)->previous;

// 		if ((*src)->next != *src)
// 			*src = (*src)->next;
// 		else if ((*src)->next == *src)
// 			*src = NULL;
// 	}
// }


// void		push(t_checker *checker)
// {
// 	t_node		*temp;

// 	// printf("dest: %p  src: %p\n", *dest, *src);
// 	if (STCK_A != NULL)
// 		return ;
// 		// temp->data = (*src)->data;
// 	temp = STCK_A;
// 	if (STCK_B != NULL)
// 	{
// 		temp->next = STCK_B;
// 		temp->previous = STCK_B->previous;
// 		STCK_B->previous->next = temp;
// 		STCK_B->previous = temp;
// 	}
// 	else
// 	{
// 		temp->previous = temp;
// 		temp->next = temp;
// 	}

// 	STCK_B = temp;

// 	STCK_A->previous->next = STCK_A->next;
// 	STCK_A->next->previous = STCK_A->previous;

// 	if (STCK_A->next != STCK_A)
// 		STCK_A = STCK_A->next;
// 	else if (STCK_A->next == STCK_A)
// 		STCK_A = NULL;
// }

// void		push(t_node **src)
void		push_b(t_checker *checker)
{
	t_node		*temp;

	if (STCK_A == NULL)
		return ;
		// temp->data = (*src)->data;

	STCK_A->previous->next = STCK_A->next;
	STCK_A->next->previous = STCK_A->previous;
	temp = STCK_A;
	STCK_A = STCK_A->next;

	
	insert_node(temp, &STCK_B);

	printf("2b: %p  2a: %p\n", STCK_A, STCK_B);

}


void	unlink_node(t_node **node)
{
	t_node *temp;

	temp = (*node)->next;
	if (*node == NULL)
		return ;
	if ((*node)->next == *node)
	{
		*node = NULL;
		return ;
	}
	(*node)->previous->next = (*node)->next;
	(*node)->next->previous = (*node)->previous;
	*node = temp;


}



void	insert_node(t_node *src, t_node **dest)
{
	if (*dest != NULL)
	{
		src->next = *dest;
		src->previous = (*dest)->previous;
		(*dest)->next->previous = src;
		(*dest)->previous->next = src;
		*dest = src;
	}
	else
	{
		src->next = src;
		src->previous = src;
		*dest = src;
	}
}




// void MoveNode(struct Node** destRef, struct Node** sourceRef)
// {
//     // if the source list empty, do nothing
//     if (*sourceRef == NULL)
//         return;
//     struct Node* newNode = *sourceRef;    // the front source node
//     *sourceRef = (*sourceRef)->next;    // Advance the source pointer
//     newNode->next = *destRef;    // Link the old dest off the new Node
//     *destRef = newNode;            // Move dest to point to the new Node
// }