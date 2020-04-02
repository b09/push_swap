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