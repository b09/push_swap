/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado         #+#    #+#                */
/*   Updated: 2020/03/13 16:04:48 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// fuctions:
void			sort_lnkd_lst(t_ps_obj *obj);
void			divide_a(t_ps_obj *obj, char next_or_previous);
void			sort_three_or_less(t_ps_obj *obj);
void			divide_b(t_ps_obj *obj, char next_or_previous);



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
	sort_lnkd_lst(&obj);
	// sort_three_or_less(&obj);
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

	while (UNSORTED || LEN_B)
	{
		while (UNSORTED > 3)
		{
			// if there are no presorted nodes at bottom of stack_a from previous
			// rotations, ensure divide_a() divides going forward & not backward
			divide_a(obj, UNSRT_BTTM_A ? 0 : 1);
			// header must be moved if any elements are in place in stack_a (sorted)
		}
		sort_three_or_less(obj);
		if (LEN_B)
			divide_b(obj, UNSRT_BTTM_A ? 0 : 1);
		// j = j ? 0 : 1;
	}
}



/*
**	func() requires a stop point because some parts of stack_a will start to be
**	sorted, so the entirety of stack_a does not need to be divided
**	pivot will become increasingly smaller
**	must stop dividing until sorted nodes have been reached
**	must reverse rotate as nodes will be behind head from previous rotations
**	cases:
**		- first iteration


		print_content_lnkd_list(obj);
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		// printf("Press enter to continue...");
		// getchar();
		printf("pivot: %d, unsorted: %d, data_a: %d\n", PIVOT, UNSORTED, DATA_A);
*/
void			divide_a(t_ps_obj *obj, char next_or_previous)
{
	int			current_len;
	t_node		*temp;

	if (ARRAY)
		PIVOT = obj->array[((UNSORTED) / 2) + SORTED - 1];
	current_len = 0;
	temp = next_or_previous ? NEXT_A : PREV_A;


	// only sort part of stack that needs sorting
	while (temp != NULL && current_len < UNSORTED)
	{
		// depending on interation, func will rotate or reverse rotate
		temp = next_or_previous ? NEXT_A : PREV_A;

		if (DATA_A < PIVOT)
			push(&STCK_A, &STCK_B, obj);
		else
		{
			rotate(&STCK_A, next_or_previous ? 1 : 0, obj);
			// keep record of presorted stack pushed to bottom of same stack
			UNSRT_BTTM_A += next_or_previous ? 1 : -1;
		}
	printf("pivot index in array: %d	unsorted: %d\n", ((UNSORTED) / 2), SORTED);
		// increase int in array representing presorted segments in stack_b
		// obj->medians[obj->med_i] +=	DATA_A < PIVOT ? 1 : 0;
		// incrementer compared with unsorted int, unsorted int decrease by other func
		++current_len;
		STCK_A = temp;
	}
	// increase index of int array represeting presorted segments in stack_b
	++(obj->med_i);
}



// func should be called where the number of unsorted nodes in stack_a is 
// three or less
// reverse rotate UNSRT_BTTM times to ensure data being manipulted by func()
// is at top of stack
void			sort_three_or_less(t_ps_obj *obj)
{
	t_node		*temp;

	temp = 0;
	if (LEN == 1)
		SORTED = LEN;
	else if (UNSORTED == 2)
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
void			divide_b(t_ps_obj *obj, char next_or_previous)
{
	int			current_len;
	t_node		*temp;

	// median[med_i] will have increase from every push() to stk_b
	// and med_i will have increased on every exit of divide_a, at which point
	// in will have increased to a null terminated section of the array of ints
	if (!MEDIANS[MED_I] && MED_I > 0)
		--MED_I;
	if (ARRAY)
		PIVOT = obj->array[LEN + (MEDIANS[MED_I] / 2) - 1];

	current_len = 0;
	temp = next_or_previous ? NEXT_B : PREV_B;

	// only sort part of stack that needs sorting
	while (temp != NULL && current_len < MEDIANS[MED_I])
	{
		// depending on interation, func will rotate or reverse rotate
		temp = next_or_previous ? NEXT_B : PREV_B;

		if (DATA_B >= PIVOT)
			push(&STCK_B, &STCK_A, obj);
		else
		{
			rotate(&STCK_B, next_or_previous ? 1 : 0, obj);
			// keep record of presorted stack pushed to bottom of same stack
			UNSRT_BTTM_B += next_or_previous ? 1 : -1;
		}
		// increase int in array representing presorted segments in stack_b
		// MEDIANS[MED_I] += DATA_A < PIVOT ? 1 : 0;
		// incrementer compared with unsorted int, unsorted int decrease by other func
		++current_len;
		STCK_A = temp;
	}
	MEDIANS[MED_I] = UNSRT_BTTM_B ? UNSRT_BTTM_B : 0;
	// increase index of int array represeting presorted segments in stack_b
	MED_I -= MEDIANS[MED_I] ? 0 : 1;

}

















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
