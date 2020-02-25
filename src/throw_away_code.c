
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
