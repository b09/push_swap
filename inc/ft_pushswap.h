/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pushswap.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:13:22 by bprado         #+#    #+#                */
/*   Updated: 2020/02/13 20:56:40 by bprado        ########   odam.nl         */
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
# define LENGTH		checker->len
# define ARGV		checker->argv



typedef struct	s_checker
{
	int		*a_stack;
	int		*b_stack;
	int		pos_a;
	int		pos_b;
	int		len;
	char	**argv;
}				t_checker;

struct	s_pushswap
{
	int		number;
	void	*prev;
	void	*next;
}		t_pushswap;

#endif



