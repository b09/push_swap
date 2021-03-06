/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:13:22 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/11 17:38:43 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include "libft.h"

/*
**	COLORS
*/
# define C_RED     		"\x1b[31m"
# define C_GREEN   		"\x1b[32m"
# define C_YELLOW  		"\x1b[33m"
# define C_BLUE    		"\x1b[34m"
# define C_MAGENTA 		"\x1b[35m"
# define C_CYAN    		"\x1b[36m"
# define C_RESET   		"\x1b[0m"

typedef	struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct		s_ps
{
	int				pivot;
	int				len;
	int				len_b;
	int				srtd;
	int				holder;
	int				m_i;
	int				unsrt_btm_a;
	int				unsrt_btm_b;
	int				meds[20];
	t_node			*stck_a;
	t_node			*stck_b;
	char			**argv;
	int				*array;
}					t_ps;

/*
**	print_functions.c
*/

void				print_content_lnkd_list(t_ps *ps);

/*
**	push_swap_helpers.c
*/

void				helper_sort_lnkd_lst(t_ps *ps);
void				helper_sort_three(t_ps *ps, t_node *temp);
int					helper_for_divide(t_ps *ps, t_node **node, char io);

/*
**	shared_array_delete_funcs.c
*/

void				create_and_srt_array(t_ps *ps, int i);
int					check_if_unsorted(t_ps *ps, int i);
int					repeats_in_sorted_array(t_ps *ps);
void				delete_everything(t_ps *ps, t_node **list);
void				navigate_thru_lnkd_lst(t_node **node, char go_to_end);

/*
**	shared_core_operations.c
*/

int					swap(t_node *stack, char swap_going_down_list, t_ps *ps);
void				push(t_node **src, t_node **dest, t_ps *ps);
int					rotate(t_node **node, char insert_at_end, t_ps *ps);

/*
**	shared_input_validation.c
*/

int					check_length_of_input(char *str, int iterations);
int					validate_argv(int argc, char **argv);
t_node				*create_lnkd_lst(t_ps *ps, int size, t_node *head);

#endif
