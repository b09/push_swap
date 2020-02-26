/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:05:02 by bprado         #+#    #+#                */
/*   Updated: 2020/02/26 20:29:58 by bprado        ########   odam.nl         */
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
	obj.len = argc - 1;
	obj.argv = argv;
	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
	print_content_lnkd_list(&obj);
	if (!manipulate_stacks(&obj))
		return (0);
	verify_order_of_data(&obj);
	delete_lnkd_list(&obj, &(obj.stck_a));
	printf("address of stack_a after freeing list: %p\n", obj.stck_a);
	return (0);
}

void			verify_order_of_data(t_ps_obj *obj)
{
	int			i;

	i = STCK_A->data;
	while (STCK_A->next != NULL)
	{
		if (i >= STCK_A->next->data)
		{
			ft_putstr("KO\n");
			return ;
		}
		STCK_A = STCK_A->next;
		i = STCK_A->data;
	}
	if (STCK_B == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void			verify_order_of_data(t_ps_obj *obj);
char			*read_stdin(void)
{
	char		*str;

	str = NULL;
	while (get_next_line(0, &str) > 0)
		return (str);
	return (NULL);
}
