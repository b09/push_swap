/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado         #+#    #+#                */
/*   Updated: 2020/03/02 21:00:31 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			sorted_array(t_ps_obj *obj);
void			divide_a(t_ps_obj *obj);




int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	char		*str;
	int			medians[20];

	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (0);
	printf("push_swap(): %s\n", argv[0]);
	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
	// print_content_lnkd_list(&obj);
	sorted_array(&obj);
	// print_array(&obj);

	divide_a(&obj);
	print_content_lnkd_list(&obj);



	// if (!manipulate_stacks(&obj))
	// 	return (-1);
	// verify_order_of_data(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	delete_array_of_sorted_ints(&obj);
	printf("address of stack_a after freeing list: %p\n", obj.stck_a);
	printf("address of stack_a after freeing list: %p\n", obj.array);
	return (0);
}


// push_to_b, which is not a function rather a call to insertnode() and
// unlink_node() needs to be rewritten, as it is not relinking nodes
// in stack_a as it should
void			divide_a(t_ps_obj *obj)
{
	int			pivot;
	int			current_len;
	t_node		*temp;
	if (ARRAY)
		pivot = obj->array[((LEN - SORTED) / 2) + SORTED - 1];
	current_len = 0;
	while (NEXT_A != NULL)
	{
		temp = NEXT_A;
		if (DATA_A >= pivot)
			insert_node(unlink_node(&STCK_A), &STCK_B);
		// ++current_len;
		STCK_A = temp;
		printf("line:%d, address:%p, data:%d pivot:%d\n", __LINE__, STCK_A, DATA_A, pivot);
	}
	// return_to_head(obj);
}


















// void			select_sort(t_ps_obj *obj)
// {
// 	int			i;

// 	i = 0;
// 	if (STCK_A != NULL)
// 		i = 1; // to quiet warning in vscode

// }







/*
**	bubble sort of data
**	length of linked list should be updated for each stack
**	
**	for now, add elements to stack_b from smallest to largest
**	once complete, push everything back to stach_a (everything should be
**	in correct order)
**	
**	malloc array, add pointer to struct, free once done
**	
**	func() will search for each number that is in the array in the stack
**	
**	other funcs() that print string for each action that is taken on the stack
**	should be written
**	
**	***********************************
**	push to b all elements that are above median
**	
**	
**	
**	
**	
**	
*/
