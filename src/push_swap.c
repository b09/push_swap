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
void			divide(t_ps_obj *obj, char next_or_previous, t_node **node);
void			assign_pivot(t_ps_obj *obj, t_node *stack);




// len is dependant on argv having individual strings for each argument
// if all args are contained whithin the first line, LEN will be incorrect
int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	char		*str;
	// int			medians[20];

	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (-1);
	// printf("push_swap(): %s\n", argv[0]);

	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
	// obj.medians = medians;
	// if (obj.len < 4)
	// 	return (solve_for_three());

	create_and_srt_array(&obj);

	print_content_lnkd_list(&obj);
	// print_array(&obj);
	sort_lnkd_lst(&obj);
	// sort_three_or_less(&obj);
	// printf("After sort_three_or_less(&obj)\n");
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




// void			sort_lnkd_lst(t_ps_obj *obj)
// {
// 	int pivot;
// 	int current_len;
// 	int ch;

// 	current_len = LEN;
// 	while (current_len - SORTED || LEN_B)
// 	{
// 		while ((ch = getchar()) != '\n' && ch != EOF);
// 		// current_len = LEN;
// 		while (UNSORTED > 3)
// 		{	
// 			while ((ch = getchar()) != '\n' && ch != EOF);
// 			// if there are no presorted nodes at bottom of stack_a from previous
// 			// rotations, ensure divide_a() divides going forward & not backward
// 			// divide_a(obj, 1);
// 			divide_a(obj, UNSRT_BTTM_A ? 0 : 1);
// 			// header must be moved if any elements are in place in stack_a (sorted)
// 		}
// 		// print_content_lnkd_list(obj);
// 		while (UNSORTED <= 3 && UNSRT_BTTM_A)
// 		{
// 			while ((ch = getchar()) != '\n' && ch != EOF);
// 			rotate(&STCK_A, 0, obj);
// 			--UNSRT_BTTM_A;			
// 		}
// 		sort_three_or_less(obj);
// 		if (LEN_B)
// 			divide_b(obj, UNSRT_BTTM_B ? 0 : 1);
// 		// j = j ? 0 : 1;
// 		printf("%s -- current_len:%d sorted:%d len_b:%d\n", __func__, current_len, SORTED, LEN_B);
// 	}
// }



// // func should be called where the number of unsorted nodes in stack_a is 
// // three or less
// // reverse rotate UNSRT_BTTM times to ensure data being manipulted by func()
// // is at top of stack
// void			sort_three_or_less(t_ps_obj *obj)
// {
// 	t_node		*temp;
// 	printf("inside %s unsorted: %d sorted:%d length:%d data:%d nextdata:%d\n", __func__, UNSORTED, SORTED, LEN, DATA_A, NEXT_A->data);
// 	int ch;
// 	while ((ch = getchar()) != '\n' && ch != EOF);

// 	temp = 0;
// 	if (LEN == 1 || UNSORTED == 0)
// 		SORTED = LEN;
// 	else if (UNSORTED == 2)
// 	{
// 		if (DATA_A > NEXT_A->data)
// 			swap(STCK_A, 1, obj);
// 		SORTED = LEN;
// 	}
// 	else if (SORTED != LEN && LEN_B != 0)
// 	{
// 		temp = DATA_A > NEXT_A->data ? STCK_A : NEXT_A;
// 		temp = temp->data > NEXT_A->next->data ? temp : NEXT_A->next;
// 		++SORTED; // both if and else will increase sorted, so placed here
// 		if (temp == STCK_A)
// 		{
// 			swap(STCK_A, 1, obj);
// 			rotate(&STCK_A, 1, obj);
// 			swap(STCK_A, 1, obj);
// 			rotate(&STCK_A, 0, obj);
// 		}
// 		else if (temp == NEXT_A)
// 		{
// 			// printf("line: %d with stack:\n", __LINE__);
// 			// print_content_lnkd_list(obj);
// 			rotate(&STCK_A , 1, obj);
// 			// printf("line: %d with stack:\n", __LINE__);
// 			// print_content_lnkd_list(obj);
// 			swap(STCK_A, 1, obj);
// 			// printf("line: %d with stack:\n", __LINE__);
// 			// print_content_lnkd_list(obj);
// 			rotate(&STCK_A , 0, obj);
// 			// printf("line: %d with stack:\n", __LINE__);
// 			// print_content_lnkd_list(obj);
// 		}
// 		// printf("recusive sort_three_or_less\n");
// 		sort_three_or_less(obj);
// 	}
// 	printf("exiting %s, current stacks are:\n", __func__);
// 	print_content_lnkd_list(obj); // for debugging
// }




// void	assign_pivot(t_ps_obj *obj, t_node *stack)
// {
// 	if (stack == STCK_A && ARRAY)
// 	{
// 		PIVOT = obj->array[((UNSORTED) / 2) + SORTED - 1];
// 		if (UNSORTED == 5)
// 			PIVOT = obj->array[LEN - 3];
// 		else if (UNSORTED == 4)
// 			PIVOT = obj->array[LEN - 2];
// 		else if (UNSORTED <= 3)
// 			PIVOT = obj->array[LEN - 1];

// 	}
// 	else if (stack == STCK_B && ARRAY)
// 	{
// 		/* code */
// 	}
// }


// /*
// **	func() requires a stop point because some parts of stack_a will start to be
// **	sorted, so the entirety of stack_a does not need to be divided
// **	pivot will become increasingly smaller
// **	must stop dividing until sorted nodes have been reached
// **	must reverse rotate as nodes will be behind head from previous rotations
// **	cases:
// **		- first iteration


// 		print_content_lnkd_list(obj);
// 		// printf("Press enter to continue...");
// 		// getchar();
// 		printf("pivot: %d, unsorted: %d, data_a: %d\n", PIVOT, UNSORTED, DATA_A);
// */
// void			divide_a(t_ps_obj *obj, char next_or_previous)
// {
// 	printf("inside %s sorted:%d\n", __func__, SORTED);
// 	int			current_len;
// 	t_node		*temp;

// 	// if (ARRAY)
// 	// 	PIVOT = obj->array[((UNSORTED) / 2) + SORTED - 1];
// 	assign_pivot(obj, STCK_A);
// 	current_len = LEN;
// 	// temp = next_or_previous ? NEXT_A : PREV_A;
// 	temp = STCK_A; // temp needs to be assigned accoring to next element of 
// 	// current element

// 	printf("LEN:%d address next: %p prev: %p stack_a address: %p UN_BTTM:%d SORTED:%d PIVOT:%d\n", LEN, NEXT_A, PREV_A, STCK_A, UNSRT_BTTM_A, SORTED, PIVOT);
// 	// only sort part of stack that needs sorting
// 	while (temp != NULL && current_len - SORTED)
// 	{
// 		if (next_or_previous)
// 		{
// 			// depending on interation, func will rotate or reverse rotate
// 			temp = next_or_previous ? NEXT_A : STCK_A;
// 			// printf("DATA:%d\n", DATA_A);
// 			if (DATA_A < PIVOT)
// 				push(&STCK_A, &STCK_B, obj);
// 			else
// 			{
// 				rotate(&STCK_A, 1, obj);
// 				// keep record of presorted stack pushed to bottom of same stack
// 				UNSRT_BTTM_A += next_or_previous ? 1 : -1;
// 			}
// 		}
// 		else
// 		{
// 			printf("data before rotate:%d\n", DATA_A);
// 			rotate(&STCK_A, 0, obj);
// 			if (DATA_A < PIVOT)
// 				push(&STCK_A, &STCK_B, obj);
// 			--UNSRT_BTTM_A;
// 			temp = LEN > 1 ? STCK_A : NULL;
// 		}
		
// 		// printf("UNSRT_BTTM:%d\nPIVOT:%d\nUNSORTED:%d\ntemp&:%p\ncurrent_len:%d\n\n", UNSRT_BTTM_A, PIVOT, UNSORTED, temp, current_len);
// 		// increase int in array representing presorted segments in stack_b
// 		// obj->medians[obj->med_i] +=	DATA_A < PIVOT ? 1 : 0;
// 		// incrementer compared with unsorted int, unsorted int decrease by other func
// 		--current_len;
// 		STCK_A = temp;
// 	}
// 	printf("exiting %s DATA_A: %d UN_BTTM: %d current stacks:\n\n", __func__, DATA_A, UNSRT_BTTM_A);
// 	print_content_lnkd_list(obj);
// 	// increase index of int array represeting presorted segments in stack_b
// 	++(obj->med_i);
// }




// // /*
// // **	smallest ints should be added last to stack_a, to keep smallest ints in
// // **	stack_b
// // */
// void			divide_b(t_ps_obj *obj, char next_or_previous)
// {
// 	int			current_len;
// 	t_node		*temp;

// 	// median[med_i] will have increased from every push() to stk_b
// 	// and med_i will have increased on every exit of divide_a, at which point
// 	// in will have increased to a null terminated section of the array of ints
// 	if (!MEDIANS[MED_I] && MED_I > 0)
// 		--MED_I;
// 	if (ARRAY)
// 		PIVOT = obj->array[LEN + (MEDIANS[MED_I] / 2)];

// 	// print_medians(obj); // for debugging
// 	printf("inside %s pivot:%d len_b:%d median:%d median index: %d address:%p next_previous:%d (MEDIANS[MED_I] / 2): %d UNSRT_BTTM:%d current stacks are:\n", __func__, PIVOT, LEN_B, MEDIANS[MED_I], MED_I, STCK_B, next_or_previous, (MEDIANS[MED_I] / 2), UNSRT_BTTM_B);
// 	print_content_lnkd_list(obj); // for debugging
	
// 	current_len = 0;
// 	// printf("pivot:%d\n", PIVOT);
// 	// print_medians(obj);
// 	if (LEN_B == 1)
// 	{
// 		push(&STCK_B, &STCK_A, obj);
		
// 	}
// 	temp = STCK_B;
// 	// only sort part of stack that needs sorting
// 	while (temp != NULL && current_len < MEDIANS[MED_I])// && UNSRT_BTTM_B < (MEDIANS[MED_I] / 2))
// 	{
// 		// printf("%s -- current_len:%d < median: %d data_b:%d pivot:%d len_b:%d unsrtd_bttm:%d\n", __func__, current_len, MEDIANS[MED_I], DATA_B, PIVOT, LEN_B, UNSRT_BTTM_B);
// 		// depending on interation, func will rotate or reverse rotate
// 		// temp = next_or_previous ? NEXT_B : PREV_B;
// 		temp = NEXT_B;
// 		if (next_or_previous)
// 		{
// 			if (DATA_B >= PIVOT || (LEN_B == 1 && current_len == 0))
// 			{
// 				push(&STCK_B, &STCK_A, obj);
// 				// ++current_len; // if half median[med_i] elements have been pushed
// 				// this means the other half, thru to spliting everthing by a
// 				// median, should remain in stack_b. by doubling incrementing the
// 				// current_len on every push loop, i ensure an exit of the loop 
// 				// when half of the elements have been pushed to stack_a
// 			}
// 			else
// 			{
// 				// printf("unsrt_bttm:%d data:%d next_or_previous:%d st_b addr: %p\n", UNSRT_BTTM_B, DATA_B, next_or_previous, STCK_B);
// 				rotate(&STCK_B, next_or_previous ? 1 : 0, obj);
// 				// keep record of presorted stack pushed to bottom of same stack
// 				++UNSRT_BTTM_B;
// 			}

// 		}
// 		else if (!next_or_previous && UNSRT_BTTM_B)
// 		{
// 			rotate(&STCK_B, 0, obj);
// 			if (DATA_B >= PIVOT)
// 				push(&STCK_B, &STCK_A, obj);
// 			--UNSRT_BTTM_B;
// 			temp = LEN_B >= 1 ? STCK_B : NULL; // needs to be rewritten
// 			// rotate will reassign head, so when is temp = STCK_B needed?
// 			// temp = STCK_B is trying to overcome temp = NEXT_B

// 		}
		
// 		// increase int in array representing presorted segments in stack_b
// 		// MEDIANS[MED_I] += DATA_A < PIVOT ? 1 : 0;
// 		// incrementer compared with unsorted int, unsorted int decrease by other func
// 		++current_len;
// 		STCK_B = LEN_B == 1 ? STCK_B : temp;
// 	}
// 	MEDIANS[MED_I] = UNSRT_BTTM_B ? UNSRT_BTTM_B : 0;
// 	// increase index of int array represeting presorted segments in stack_b
// 	MED_I -= MEDIANS[MED_I] <= 0 && MED_I > 0 ? 1 : 0;
// 	MED_I += UNSRT_BTTM_B ? 1 : 0;
// 	printf("exiting %s, unsrt_bttm: %d stack_b addr: %p med[m_i]:%d m_i:%d current stacks are:\n", __func__, UNSRT_BTTM_B, STCK_B, MEDIANS[MED_I], MED_I);
// 	print_content_lnkd_list(obj); // for debugging
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


void			print_struct(t_ps_obj *obj)
{
	printf("a:%p b:%p len:%d len_b:%d sorted:%d pivot:%d unsorted:%d unsrt_a:%d unsrt_b:%d median[i]:%d med_i:%d\n", STCK_A, STCK_B, LEN, LEN_B, SORTED, PIVOT, UNSORTED, UNSRT_BTTM_A, UNSRT_BTTM_B, MEDIANS[MED_I], MED_I);
}


void			assign_pivot(t_ps_obj *obj, t_node *stack)
{
	int			i;

	i = 0;
	if (stack == STCK_A && ARRAY)
	{
		PIVOT = obj->array[((UNSORTED) / 2) + SORTED - 1];
		if (UNSORTED <= 5 && UNSORTED >= 3)
			PIVOT = obj->array[LEN - (UNSORTED - 2)];
		else if (UNSORTED < 3)
			PIVOT = obj->array[LEN - 1];
	}
	else if (stack == STCK_B && ARRAY)
	{
		i = MEDIANS[MED_I] >= 0 ? MEDIANS[MED_I] : -MEDIANS[MED_I];
		PIVOT = obj->array[LEN + (i / 2)];
		if (i <= 5 && i >= 3)
			PIVOT = obj->array[LEN + (i - 2)];
		if (i < 3)
			PIVOT = obj->array[LEN];

	}
}




void			sort_lnkd_lst(t_ps_obj *obj)
{
	int			current_len;

	current_len = LEN;
	while (SORTED != current_len)
	{
		printf("beginning of %s\n", __func__);
		print_content_lnkd_list(obj);
		print_struct(obj);
		while (UNSORTED > 3)
		{
			// divide_a(obj, UNSRT_BTTM_A ? 0 : 1);
			printf("divide a");
			divide(obj, UNSRT_BTTM_A ? 0 : 1, &STCK_A);
			++MED_I;
		}
		// unstr_bttm_a must be increased and decreased correctly
		while (UNSORTED <= 3 && UNSRT_BTTM_A && LEN > 3 && SORTED != 0)
		{
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF);
			print_struct(obj);
			rotate(&STCK_A, 0, obj);
		}

		sort_three_or_less(obj);
		if (LEN_B)
		{
			printf("divide b med_i:%d\n", MED_I);
			--MED_I;
			divide(obj, MEDIANS[MED_I] < 0 ? 0 : 1, &STCK_B);
			MEDIANS[MED_I] = UNSRT_BTTM_B ? -UNSRT_BTTM_B : MEDIANS[MED_I];
			MED_I += UNSRT_BTTM_B ? 1 : 0;
			UNSRT_BTTM_B = 0;
		}
		printf("end of %s\n", __func__);
		print_struct(obj);
	}
}




void			sort_three_or_less(t_ps_obj *obj)
{
	t_node		*temp;

	temp = 0;
	printf("inside %s sorted:%d len:%d len_b:%d unsorted:%d, data:%d median[i]:%d med_i:%d\n", __func__, SORTED, LEN, LEN_B, UNSORTED, DATA_A, MEDIANS[MED_I], MED_I);
	print_content_lnkd_list(obj);
	if (LEN == 1 || UNSORTED == 2)
	{
		if (UNSORTED == 2 && DATA_A > NEXT_A->data)
			swap(STCK_A, 1, obj);
		SORTED = LEN;
	}
	else if (SORTED != LEN && LEN_B != 0)
	{
		temp = DATA_A > NEXT_A->data ? STCK_A : NEXT_A;
		temp = temp->data > NEXT_A->next->data ? temp : NEXT_A->next;
		++SORTED;
		if (temp == STCK_A || temp == NEXT_A)
		{
			if (temp == STCK_A)
				swap(STCK_A, 1, obj);
			rotate(&STCK_A, 1, obj);
			swap(STCK_A, 1, obj);
			rotate(&STCK_A, 0, obj);
		}
		sort_three_or_less(obj);
	}
	printf("exiting %s sorted:%d len:%d len_b:%d unsorted:%d, data:%d median[i]:%d med_i:%d\n", __func__, SORTED, LEN, LEN_B, UNSORTED, DATA_A, MEDIANS[MED_I], MED_I);
}



void			divide(t_ps_obj *obj, char one_or_zero, t_node **node)
{
	int			length;
	int			i;
	int ch;

	i = 0;
	assign_pivot(obj, *node);
	length = node == &STCK_A ? LEN - SORTED : MEDIANS[MED_I];
	length = MEDIANS[MED_I] < 0 ? -length : length;
	printf("inside %s unsorted: %d sorted:%d len:%d data addr:%p nextdata:none pivot:%d UNSRT_BTT_A:%d UNSRT_BTTM_B:%d i:%d one_zero:%d length:%d median[i]:%d med_i:%d\n", __func__, UNSORTED, SORTED, LEN, (*node), PIVOT, UNSRT_BTTM_A, UNSRT_BTTM_B, i, one_or_zero, length, MEDIANS[MED_I], MED_I);
	while (*node != NULL && i <= length)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("inside %s unsorted: %d sorted:%d len:%d data addr:%p nextdata:none pivot:%d UNSRT_BTT_A:%d UNSRT_BTTM_B:%d i:%d one_zero:%d length:%d median[i]:%d med_i:%d\n", __func__, UNSORTED, SORTED, LEN, (*node), PIVOT, UNSRT_BTTM_A, UNSRT_BTTM_B, i, one_or_zero, length, MEDIANS[MED_I], MED_I);

		if (((!one_or_zero && i > 0) || (one_or_zero && i < length)) && \
			((node == &STCK_A && (*node)->data < PIVOT) || \
			(node == &STCK_B && (*node)->data >= PIVOT)))
		{
			printf("line:%d sorted:%d\n", __LINE__, SORTED);
			push(node, node == &STCK_A ? &STCK_B : &STCK_A, obj);
			printf("line:%d sorted:%d\n", __LINE__, SORTED);
			if (i < length && !one_or_zero)
				rotate(node, 0, obj);
		}
		else if (i < length)
			rotate(node, one_or_zero, obj);
		++i;
	}
	printf("exiting %s unsorted: %d sorted:%d length:%d node addr:%p nextdata:none pivot:%d UNSRT_BTT_A:%d UNSRT_BTTM_B: %d median[i]:%d med_i:%d stacks:\n", __func__, UNSORTED, SORTED, LEN, (*node), PIVOT, UNSRT_BTTM_A, UNSRT_BTTM_B, MEDIANS[MED_I], MED_I);
	print_content_lnkd_list(obj);
}



void			divide_a(t_ps_obj *obj, char next_or_previous)
{
	int			current_len;

	assign_pivot(obj, STCK_A);
	current_len = LEN;
	while (STCK_A != NULL && current_len - SORTED)
	{
		if (next_or_previous)
		{
			if (DATA_A < PIVOT)
				push(&STCK_A, &STCK_B, obj);
			else
				rotate(&STCK_A, 1, obj);
		}
		else
		{
			rotate(&STCK_A, 0, obj);
			if (DATA_A < PIVOT)
				push(&STCK_A, &STCK_B, obj);
		}
		--current_len;
	}
}


void			divide_b(t_ps_obj *obj, char next_or_previous)
{
	int			current_len;
	t_node		*temp;
		
	current_len = 0;

	while (STCK_B != NULL && MEDIANS[MED_I])
	{
		if (next_or_previous)
		{
			if (DATA_B >= PIVOT || (LEN_B == 1 && current_len == 0))
				push(&STCK_B, &STCK_A, obj);
			else
				rotate(&STCK_B, next_or_previous ? 1 : 0, obj);
		}
		else if (!next_or_previous && UNSRT_BTTM_B)
		{
			rotate(&STCK_B, 0, obj);
			if (DATA_B >= PIVOT)
				push(&STCK_B, &STCK_A, obj);
		}
	}
	MEDIANS[MED_I] = UNSRT_BTTM_B ? UNSRT_BTTM_B : 0;
	MED_I -= MEDIANS[MED_I] <= 0 && MED_I > 0 ? 1 : 0;
	MED_I += UNSRT_BTTM_B ? 1 : 0;
}

