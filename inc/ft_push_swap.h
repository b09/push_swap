/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:13:22 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/05 20:19:15 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H

# define FT_PUSHSWAP_H

# include "libft.h"

// # define ARGV			obj->argv
// # define STCK_A			obj->stck_a
// # define STCK_B			obj->stck_b
// # define LEN			obj->len
// # define LEN_B			obj->len_b
# define SORTED			obj->sorted
# define PIVOT			obj->pivot
# define ARRAY			obj->array
# define HOLDER			obj->holder
// # define UNSORTED		obj->len - obj->sorted
# define UNSRT_BTTM_A	obj->unsorted_bottom_a
# define UNSRT_BTTM_B	obj->unsorted_bottom_b
# define MEDS			obj->medians
# define MED_I			obj->med_i
# define DATA_A			obj->stck_a->data
# define DATA_B			obj->stck_b->data
# define NEXT_A			obj->stck_a->next
# define NEXT_B			obj->stck_b->next
# define PREV_A			obj->stck_a->previous
# define PREV_B			obj->stck_b->previous

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

typedef struct		s_ps_obj
{
	int				pivot;
	int				len;
	int				len_b;
	int				sorted;
	int				holder;
	int				med_i;
	int				unsorted_bottom_a;
	int				unsorted_bottom_b;
	int				medians[20];
	t_node			*stck_a;
	t_node			*stck_b;
	char			**argv;
	int				*array;
}					t_ps_obj;

/*
**	ps_operation.c
*/

int					swap(t_node *stack, char swap_going_down_list, t_ps_obj *obj);
void				push(t_node **src, t_node **dest, t_ps_obj *obj);
int					rotate(t_node **node, char insert_at_end, t_ps_obj *obj);

/*
**	push_swap_extra.c
*/

void				delete_sorted_array(t_ps_obj *obj);
void				create_and_srt_array(t_ps_obj *obj, int i);
int					check_if_unsorted(t_ps_obj *obj, int i);
int					repeats_in_sorted_array(t_ps_obj *obj);
void				navigate_thru_lnkd_lst(t_node **node, char go_to_end);

/*
**	shared_funcs.c
*/

void				sort_lnkd_lst(t_ps_obj *obj);
void				delete_lnkd_list(t_ps_obj *obj, t_node **list);
int					validate_argv(int argc, char **argv);
t_node				*create_lnkd_lst_single_string(t_ps_obj *obj);
t_node				*create_lnkd_lst(t_ps_obj *obj, int size, t_node *head);

#endif
