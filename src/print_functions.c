/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 19:17:22 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/10 19:17:36 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		print_content_lnkd_list(t_ps *ps)
{
	t_node		*head;


	head = ps->stck_a;
	printf("STCK_A[0]:%d addr: %p\n", ps->stck_a->data, ps->stck_a);
	ps->stck_a = ps->stck_a->next;

	int i = 1;
	while (ps->stck_a != NULL)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_A", i++, ps->stck_a->data, ps->stck_a);
		ps->stck_a = ps->stck_a->next;
	}
	printf("\n\n");

	ps->stck_a = head;
	i = 0;
	head = ps->stck_b;
	while (ps->stck_b != NULL && i < 100)
	{
		printf("%s[%d]:%d addr: %p\n", "STCK_B", i++, ps->stck_b->data, ps->stck_b);
		ps->stck_b = ps->stck_b->next;
		if (ps->stck_b == NULL)
			printf("\n");
	}
	ps->stck_b = head;
}
