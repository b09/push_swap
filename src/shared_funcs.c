/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 19:32:58 by bprado         #+#    #+#                */
/*   Updated: 2020/03/03 18:06:22 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** add everything to stack_a in order to delete all links
** it is possible to create the linked list and have invalid instructions
** from stdin, in which case, all nodes should be added back to stack_a
** in order to 
*/
void			delete_lnkd_list(t_ps_obj *obj, t_node **list)
{
	while (STCK_B != NULL)
		insert_node(unlink_node(&STCK_B), &STCK_A);
	if (*list != NULL)
	{
		if ((*list)->next)
			delete_lnkd_list(obj, &(*list)->next);
		free(*list);
		*list = NULL;

	}
}

// must be able to take in a single string containing all args
// argc is at least 2 at this point
int				validate_argv(int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc && argc > 2)
	{
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
		{
			ft_putstr_fd("Error 1\n", 2);
			return (0);
		}
		++i;
	}
	i = 0;
	while (argc == 2 && argv[1][i] != 0)
	{
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
		{
			ft_putstr_fd("Error 2\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}

int				remove_spaces_digits_minus(char *str)
{
	int			i;

	i = 0;
	while (ft_isdigit(str[i]))
		++i;
	while (str[i] == ' ')
		++i;
	if (str[i] == '-')
		++i;
	return (i);
}

// LEN must be increased to know the correct number of nodes
t_node			*create_lnkd_lst_single_string(t_ps_obj *obj)
{
	t_node 		*head;
	t_node		*temp;
	int			i;

	head = ft_memalloc(sizeof(t_node));
	STCK_A = head;
	PREV_A = NULL;
	i = 0;
	while (ARGV[1][i] != 0)
	{
		DATA_A = ft_atoi(&ARGV[1][i]);
		i += remove_spaces_digits_minus(&ARGV[1][i]);
		if (ARGV[1][i])
		{
			++LEN;
			temp = ft_memalloc(sizeof(t_node));
			NEXT_A = temp;
			temp->previous = STCK_A;
			STCK_A = NEXT_A;
		}
	}
	if (i == 0 && ft_strlen(ARGV[1]))
		DATA_A = ft_atoi(&ARGV[1][i]);
	NEXT_A = NULL;
	return (head);
}

t_node			*create_lnkd_lst(t_ps_obj *obj, int size)
{
	t_node		*head;
	t_node		*temp;
	int			i;

	if (size != 1)
	{
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
	}
	else
		head = create_lnkd_lst_single_string(obj);
	return (head);
}

void		print_content_lnkd_list(t_ps_obj *obj)
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


/*
 ** swap(), unlink_node(), insert_node(), and rotate() may be useful for
 **	push_swap.c
*/
void    		swap(t_node *stack, char io)
{
	if (stack == NULL)
		return ;
	if (io && stack->next != NULL)
	{
		stack->data ^= stack->next->data;
		stack->next->data ^= stack->data;
		stack->data ^= stack->next->data;
		return ;
	}
	stack->data ^= stack->previous->data;
	stack->previous->data ^= stack->data;
	stack->data ^= stack->previous->data;
}


t_node			*unlink_node(t_node **node, char forward)
{
	t_node		*unlinked_node;

	unlinked_node = *node;
	if (*node == NULL)
		return (NULL);
	if (forward)
	{
		if ((*node)->next != NULL)
			(*node)->next->previous = NULL;
		*node = (*node)->next;
	}
	else
	{
		if ((*node)->previous != NULL)
			(*node)->previous->next = NULL;
		*node = (*node)->previous;
	}
	return (unlinked_node);
}

void			insert_node(t_node *src, t_node **dest, char forward)
{
	if (src == NULL)
		return ;
	if (*dest != NULL && forward)
	{
		src->next = *dest;
		src->previous = NULL;
		(*dest)->previous = src;
		*dest = src;
	}
	else if (*dest != NULL && !forward)
	{
		src->previous = *dest;
		src->next = NULL;
		(*dest)->next = src;
		*dest = src;
	}
	else
	{
		src->next = NULL;
		src->previous = NULL;
		*dest = src;
	}
}

void			push(t_node **src, t_node **dest)
{
	insert_node(unlink_node(src, 1), dest, 1);
}

void			rotate(t_node **node, char io)
{
	t_node		*head;
	t_node		*temp;
	
	if (*node == NULL)
		return ;
	if (io)
	{
		head = unlink_node(node, 1);
		temp = (*node)->next;
		head->next = NULL;
		while ((*node)->next != NULL)
			*node = (*node)->next;
		(*node)->next = head;
		*node = temp;
		return ;
	}
	else
	{
		while ((*node)->next != NULL)
			*node = (*node)->next;
		head = unlink_node(node, 0);
		temp = (*node)->next;
		head->next = NULL;
		while ((*node)->next != NULL)
			*node = (*node)->next;
		(*node)->next = head;
		*node = temp;
		return ;
	}
	*node = head;
}

void			rotate(t_node **node, char io)
{
	t_node		*head;

	head = *node;
	if (*node == NULL)
		return ;
	if (io)
	{
		while ((*node)->next != NULL)
		{
			swap(*node, 1);
			*node = (*node)->next;
		}
		*node = head;
		return ;
	}
	while ((*node)->next != NULL)
		*node = (*node)->next;
	while ((*node)->previous != NULL)
	{
		swap(*node, 0);
		*node = (*node)->previous;
	}
	*node = head;
}




