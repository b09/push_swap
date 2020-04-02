while (temp != NULL && current_len < MEDIANS[MED_I])// && UNSRT_BTTM_B < (MEDIANS[MED_I] / 2))
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