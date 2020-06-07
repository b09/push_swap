/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 18:47:24 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/07 17:05:11 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			helper_sort_lnkd_lst(t_ps *ps)
{
	ps->m_i -= ps->m_i > 0 ? 1 : 0;
	ps->holder = ps->len_b - (ps->meds[ps->m_i] < 0 ?\
	-ps->meds[ps->m_i] : ps->meds[ps->m_i]);
}

/*
**	argv may contain a single string of multiple ints, in which case
**	ps.len will be reassigned by create_lnkd_lst_single_string() later on
*/

int				main(int argc, char **argv)
{
	t_ps		ps;
	t_node		*head;

	head = NULL;
	ft_bzero(&ps, sizeof(ps));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (-1);
	ps.len = argc - 1;
	ps.argv = argv;
	ps.stck_a = create_lnkd_lst(&ps, argc - 1, head);
	if (check_if_unsorted(&ps, 0))
	{
		create_and_srt_array(&ps, 0);
		if (!repeats_in_sorted_array(&ps))
			sort_lnkd_lst(&ps);
	}
	delete_sorted_array(&ps);
	delete_lnkd_list(&ps, &(ps.stck_a));
	return (0);
}
