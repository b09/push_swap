/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 18:47:24 by bprado        #+#    #+#                 */
/*   Updated: 2020/06/05 18:48:03 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	argv may contain a single string of multiple ints, in which case
**	obj.len will be reassigned by create_lnkd_lst_single_string() later on
*/

int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	t_node		*head;

	head = NULL;
	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (-1);
	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1, head);
	if (check_if_unsorted(&obj, 0))
	{
		create_and_srt_array(&obj, 0);
		if (!repeats_in_sorted_array(&obj))
			sort_lnkd_lst(&obj);
	}
	delete_sorted_array(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	return (0);
}
