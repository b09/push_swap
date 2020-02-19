/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pushswap.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:13:22 by bprado         #+#    #+#                */
/*   Updated: 2020/02/19 19:27:20 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP

# define FT_PUSHSWAP

#include "libft.h"
#include <stdio.h>

# define A			checker->a_stack
# define B			checker->b_stack
# define A_pos		checker->pos_a
# define B_pos		checker->pos_b
# define LEN_A		checker->len_a
# define LEN_B		checker->len_b
# define ARGV		checker->argv
# define IND_A		(A_pos % LEN_A)
# define IND_B		(B_pos % LEN_B)
# define STCK_A		checker->stck_a
# define NODE_B		checker->node_b
# define DATA_A		STCK_A->data
# define DATA_B		NODE_B->data
# define NEXT_A		STCK_A->next
# define NEXT_B		NODE_B->next
# define PREV_A		STCK_A->previous
# define PREV_B		NODE_B->previous
# define HASH		1 << 3
// # define SWAP(a, b) \
//     { \
//         (a) ^= (b); \
//         (b) ^= (a); \
//         (a) ^= (b); \
//     }

// # define SWAP22(a, b) ((a) ^= (b)) + ((b) ^= (a)) + ((a) ^= (b))

// # define MULP(a, b) a * b
typedef	struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct		s_checker
{
	int				*a_stack;
	int				*b_stack;
	int				pos_a;
	int				pos_b;
	int				len_a;
	int				len_b;
	t_node			*stck_a;
	t_node			*node_b;
	char			**argv;
}					t_checker;

struct				s_pushswap
{
	int				number;
	void			*prev;
	void			*next;
}					t_pushswap;



typedef int (*func_pointer)(t_checker *);

#endif



