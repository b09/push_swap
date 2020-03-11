/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado         #+#    #+#                */
/*   Updated: 2020/03/11 19:33:49 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			divide_a_rotate(t_ps_obj *obj, char next);



// len is dependant on argv having individual strings for each argument
// if all args are contained whithin the first line, LEN will be incorrect
int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	char		*str;
	int			medians[20];

	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (-1);
	// printf("push_swap(): %s\n", argv[0]);

	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
	// if (obj.len < 4)
	// 	return (solve_for_three());

	create_and_srt_array(&obj);
	// print_array(&obj);

	print_content_lnkd_list(&obj);
	// sort_lnkd_lst(&obj);
	sort_three_or_less(&obj);
	printf("After sort_three_or_less(&obj)\n");
	print_content_lnkd_list(&obj);



	// if (!manipulate_stacks(&obj))
	// 	return (-1);
	// verify_order_of_data(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	delete_sorted_array(&obj);
	// printf("address of stack_a after freeing list: %p\n", obj.stck_a);
	// printf("address of array after freeing list: %p\n", obj.array);
	return (0);
}


void			sort_lnkd_lst(t_ps_obj *obj)
{
	int pivot;
	char	i;

	i = 1;
	while (LEN > 3 || LEN_B)
	{
		while (LEN > 3)
		{ 
			i = i ? 0 : 1;
			divide_a_rotate(obj, i);
			// header must be moved if any elements are in place in stack_a (sorted)
		}
		

	}
	// while (obj->unsorted_a > 3)
	// 	divide_a;
	// if (obj->unsorted_a <= 3)
	// 	sort_last_elemtents_of_a();
	
	//*********************
	//	recursive sort
	// *************
	/*
	if unsorted_a == 0 && len_b == 0
		return ;
	get_median();
	if unsorted_a > 0
		divide_a();
	else
		divide_b();
	sort_lnkd_lst();
	*/


	// divide_a(obj);
	// rotate(&STCK_A, 1);
	/*
	separate stack_a by pivot into stack_b
	int array of size of arrays, each an int element of the array
	stating the size of the pivoted section
	while stack_a is greater than 3 elements
		find a pivot for the array of unsorted elements and
		push elements to stack_b
	keep a size of the number of elements for that frame which 
		is sorted
	each sorted action will increase iterator until iterator is 
		the same size as current 
	*/
	// if not sorted before
	if (ARRAY && pivot == 0)
		pivot = obj->array[((LEN - SORTED) / 2) + SORTED - 1];
	else
	{
		pivot = 1;
	}
	

	// divide_a can be called, at which point all elements of stck_a have
	// been divided by pivot
	// while stack_a (length - sorted) is > 3
	//		new_pivot equals
	// define the end state, with three elements
	

	
}



/*
**	func() requires a stop point because some parts of stack_a will start to be
**	sorted, so the entirety of stack_a does not need to be divided
**	pivot will become increasingly smaller
**	must stop dividing until sorted nodes have been reached
**	must reverse rotate as nodes will be behind head
*/
void			divide_a_rotate(t_ps_obj *obj, char next_or_previous)
{
	// int			pivot;
	int			current_len;
	t_node		*temp;

	if (ARRAY)
		PIVOT = obj->array[((LEN - SORTED) / 2) + SORTED - 1];

	current_len = 0;
	temp = next_or_previous ? NEXT_A : PREV_A;

	while (temp != NULL && current_len < MAX_LEN)
	{
		temp = next_or_previous ? NEXT_A : PREV_A;
		DATA_A < PIVOT ? push(&STCK_A, &STCK_B, obj) : rotate(&STCK_A, 1, obj);
		obj->medians[obj->med_i] += DATA_A < PIVOT ? 1 : 0;
		++current_len;
		STCK_A = temp;
	}
	++(obj->med_i);
}



// func should be called where the number of unsorted nodes in stack_a is 
// three or less
void			sort_three_or_less(t_ps_obj *obj)
{
	t_node		*temp;

	temp = 0;
	if (LEN == 1)
		SORTED = LEN;
	else if (LEN - SORTED == 2)
	{
		if (DATA_A > NEXT_A->data)
			swap(STCK_A, 1, obj);
		SORTED = LEN;
	}
	else
	{
		temp = DATA_A > NEXT_A->data ? STCK_A : NEXT_A;
		temp = temp->data > NEXT_A->next->data ? temp : NEXT_A->next;
		++SORTED; // both if and else will increase sorted, so placed here
		if (temp == STCK_A)
		{
			swap(STCK_A, 1, obj);
			rotate(&STCK_A, 1, obj);
			swap(STCK_A, 1, obj);
			rotate(&STCK_A, 0, obj);
		}
		else if (temp == NEXT_A)
		{
			rotate(&STCK_A , 0, obj);
			swap(STCK_A, 1, obj);
		}
		sort_three_or_less(obj);
	}
}



/*
**	smallest ints should be added last to stack_a, to keep smallest ints in
**	stack_b
*/
void			divide_b(t_ps_obj *obj)
{
	// struct should have iterator which is the index of the current median in the median[]
	if (ARRAY)
		PIVOT = obj->array[((LEN_B - (median[median_index] / 2)) + SORTED - 1];

	if (median[median_index] <= 3)


	if (obj->medians[obj->med_i] <= 2)
	{
		
	}

		if (DATA_B >= PIVOT)
		{
			push(&STCK_B, &STCK_A, obj);
			--LEN_B;
			++LEN;
		}
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
