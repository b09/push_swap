/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado         #+#    #+#                */
/*   Updated: 2020/02/27 20:00:16 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				main(int argc, char **argv)
{
	t_ps_obj	obj;
	char		*str;

	ft_bzero(&obj, sizeof(obj));
	if (argc < 2 || !argv || !validate_argv(argc, argv))
		return (0);
	printf("push_swap(): %s\n", argv[0]);
	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
	print_content_lnkd_list(&obj);
	// if (!manipulate_stacks(&obj))
	// 	return (0);
	// verify_order_of_data(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	printf("address of stack_a after freeing list: %p\n", obj.stck_a);
	return (0);
}

void			select_sort(t_ps_obj *obj)
{
	int			i;

	i = 0;
	if (STCK_A != NULL)
		i = 1; // to quiet warning in vscode

}
