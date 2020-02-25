/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pushswap.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:13:22 by bprado         #+#    #+#                */
/*   Updated: 2020/02/25 19:43:29 by bprado        ########   odam.nl         */
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
# define STCK_B		checker->stck_b
# define DATA_A		STCK_A->data
# define DATA_B		STCK_B->data
# define NEXT_A		STCK_A->next
# define NEXT_B		STCK_B->next
# define PREV_A		STCK_A->previous
# define PREV_B		STCK_B->previous
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
	t_node			*stck_b;
	char			**argv;
}					t_checker;

struct				s_pushswap
{
	int				number;
	void			*prev;
	void			*next;
}					t_pushswap;



typedef int (*func_pointer)(t_checker *);

// ************* read stdin, call correct operation for stacks *********
int			execute_op_code2(char *operation, t_checker *checker);
int			execute_op_code(char *operation, t_checker *checker);
void		manipulate_stacks(t_checker *checker);
static void			swap(t_node *stack, char io);//, int length);
// void		push(t_node **dest, t_node **src);
void				push_b(t_checker *checker);
static void			insert_node(t_node *src, t_node **dest);
static t_node		*unlink_node(t_node **node);
static void			rotate(t_node **node, char io);
void				print_content_lnkd_list(t_checker *checker);
void		init_checker(t_checker *checker, int argc, char **argv);
t_node		*first_node(t_node *head, t_checker *checker);
t_node		*create_lnkd_lst(t_checker *checker, int size);
void		print_content_lnkd_list(t_checker *checker);
char		*read_stdin(void);
void		manipulate_stacks(t_checker *checker);
int			validate_argv(int argc, char **argv);
void		delete_lnkd_list(t_node **list);
void		verify_order_of_data(t_checker *checker);





#endif


