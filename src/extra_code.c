
// void		push(t_node *stack, t_checker *checker)
// {
// 	t_node		*temp;

// 	temp = malloc(sizeof(t_node));
// 	// assign data
// 	temp->data = DATA_B;
// 	temp->next = STCK_A;
// 	// adjust stack_a pointers
// 	temp->previous = PREV_A;
// 	PREV_A->next = temp;
// 	PREV_A = temp;
// 	// head of stack_a placed on new node
// 	STCK_A = temp;
// 	// adjust stack_b pointers
// 	PREV_B->next = NEXT_B;
// 	NEXT_B->previous = PREV_B;
// 	// free loose node
// 	temp = STCK_B;
// 	free(temp);
// 	// head of stack_b placed on next node;
// 	STCK_B = NEXT_B;
// }


// 			push(		STCK_B, 		STCK_A);
// void		push(t_node **dest, t_node **src)
// {
// 	t_node		*temp;

// 	// printf("dest: %p  src: %p\n", *dest, *src);
// 	if (*src != NULL)
// 	{

// 		// temp->data = (*src)->data;

// 		if (*dest != NULL)
// 		{

// 			temp->next = *dest;
// 			temp->previous = (*dest)->previous;
// 			(*dest)->previous->next = temp;

// 			(*dest)->previous = temp;
// 		}
// 		else
// 		{

// 			temp->previous = temp;
// 			temp->next = temp;
// 		}

// 		*dest = temp;

// 		(*src)->previous->next = (*src)->next;
// 		(*src)->next->previous = (*src)->previous;

// 		if ((*src)->next != *src)
// 			*src = (*src)->next;
// 		else if ((*src)->next == *src)
// 			*src = NULL;
// 	}
// }



// void		push(t_node **dest, t_node **src)
// {
// 	t_node		**temp;

// 	// printf("dest: %p  src: %p\n", *dest, *src);
// 	if (*src != NULL)
// 	{
// 		temp = src;

// 		if (*dest != NULL)
// 		{

// 			(*temp)->next = *dest;
// 			(*temp)->previous = (*dest)->previous;
// 			(*dest)->previous->next = (*temp);

// 			(*dest)->previous = (*temp);
// 		}
// 		else
// 		{

// 			(*temp)->previous = (*temp);
// 			(*temp)->next = (*temp);
// 		}

// 		*dest = *temp;

// 		(*src)->previous->next = (*src)->next;
// 		(*src)->next->previous = (*src)->previous;

// 		if ((*src)->next != *src)
// 			*src = (*src)->next;
// 		else if ((*src)->next == *src)
// 			*src = NULL;
// 	}
// }


// void		push(t_checker *checker)
// {
// 	t_node		*temp;

// 	// printf("dest: %p  src: %p\n", *dest, *src);
// 	if (STCK_A != NULL)
// 		return ;
// 		// temp->data = (*src)->data;
// 	temp = STCK_A;
// 	if (STCK_B != NULL)
// 	{
// 		temp->next = STCK_B;
// 		temp->previous = STCK_B->previous;
// 		STCK_B->previous->next = temp;
// 		STCK_B->previous = temp;
// 	}
// 	else
// 	{
// 		temp->previous = temp;
// 		temp->next = temp;
// 	}

// 	STCK_B = temp;

// 	STCK_A->previous->next = STCK_A->next;
// 	STCK_A->next->previous = STCK_A->previous;

// 	if (STCK_A->next != STCK_A)
// 		STCK_A = STCK_A->next;
// 	else if (STCK_A->next == STCK_A)
// 		STCK_A = NULL;
// }


/*




//*********************  print linked list  ************************************

void		print_content_lnkd_list(t_checker *checker)
{
	t_node		*head;


	head = STCK_A;
	printf("STCK_A[0]:%d addr: %p\n", DATA_A, STCK_A);
	STCK_A = STCK_A->next;

	int i = 1;
	while (STCK_A != NULL && i < 100)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_A", i++, DATA_A, STCK_A);
		STCK_A = STCK_A->next;
	}
	printf("\n\n");

	STCK_A = head;
	i = 0;
	head = STCK_B;
	// printf("STCK_B[0]addr: %p", STCK_B);
	// if (STCK_B != NULL)
	// 	printf(" data: %d  next: %p\n", DATA_B, STCK_B->next);
	// else
	// 	printf("\n");
	// // STCK_B = STCK_B->next;
	// // printf("head of b: %p\n", STCK_B);
	while (STCK_B != NULL && i < 10)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_B", i++, DATA_B, STCK_B);
		STCK_B = STCK_B->next;
	}
	STCK_B = head;
	// STCK_B = STCK_B->next;
	// printf("HEAD address: %p\nSTCK address: %p data: %d\n\n\n", head, STCK_B, DATA_B);
}

 */
