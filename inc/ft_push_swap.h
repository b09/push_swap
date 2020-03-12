/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:13:22 by bprado         #+#    #+#                */
/*   Updated: 2020/03/12 19:35:35 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP

# define FT_PUSHSWAP

#include "libft.h"
#include <stdio.h>


# define ARGV			obj->argv
# define STCK_A			obj->stck_a
# define STCK_B			obj->stck_b
# define LEN			obj->len
# define LEN_B			obj->len_b
# define SORTED			obj->sorted
# define PIVOT			obj->pivot
# define ARRAY			obj->array
# define UNSORTED		LEN - SORTED
# define UNSRT_BTTM_A	obj->unsorted_bottom_a
# define UNSRT_BTTM_B	obj->unsorted_bottom_b
# define MEDIANS		obj->medians
# define MED_I			obj->med_i
# define DATA_A			STCK_A->data
# define DATA_B			STCK_B->data
# define NEXT_A			STCK_A->next
# define NEXT_B			STCK_B->next
# define PREV_A			STCK_A->previous
# define PREV_B			STCK_B->previous

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
	int				med_i;
	int				unsorted_bottom_a;
	int				unsorted_bottom_b;
	int				*medians;
	t_node			*stck_a;
	t_node			*stck_b;
	char			**argv;
	int				*array;
}					t_ps_obj;

void			verify_order_of_data(t_ps_obj *obj);
char			*read_stdin(void);
void			delete_lnkd_list(t_ps_obj *obj, t_node **list); //
int				validate_argv(int argc, char **argv);
t_node			*create_lnkd_lst(t_ps_obj *obj, int size);
void			print_content_lnkd_list(t_ps_obj *obj);
// void    		swap(t_node *stack, char io);	
void    		swap(t_node *stack, char swap_going_down_list, t_ps_obj *obj);
// t_node			*unlink_node(t_node **node, char forward);
t_node			*unlink_node(t_node **node, char get_first_node);
// void			insert_node(t_node *src, t_node **dest, char forward);
void			insert_node(t_node *loose_node, t_node **dest, char add_to_end);
// void			rotate(t_node **node, char io);
void			rotate(t_node **node, char insert_at_end, t_ps_obj *obj);

int				manipulate_stacks(t_ps_obj *obj);
int				execute_op_code2(char *operation, t_ps_obj *obj);
int				execute_op_code(char *operation, t_ps_obj *obj);

// ******************************************* push_swap funcs
void			print_array(t_ps_obj *obj);
void			delete_sorted_array(t_ps_obj *obj);
void			create_and_srt_array(t_ps_obj *obj);
void			return_to_head(t_ps_obj *obj);
void			sort_lnkd_lst(t_ps_obj *obj);
int				remove_spaces_digits_minus(char *str);
t_node			*create_lnkd_lst_single_string(t_ps_obj *obj);
void			push(t_node **src, t_node **dest, t_ps_obj *obj);
void			navigate_thru_lnkd_lst(t_node **node, char go_to_end);
void			sort_three_or_less(t_ps_obj *obj);










#endif


/*
	validate_argv
	create_linked_list
	create_and_sort_array
	sort_linked_list
		divide_a
			sort_three_or_less
		divide_b
*/