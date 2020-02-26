/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:58:41 by bprado         #+#    #+#                */
/*   Updated: 2020/02/26 19:59:47 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_push_swap.h"

// int				main(int argc, char **argv)
// {
// 	t_ps_obj	obj;
// 	char		*str;

// 	ft_bzero(&obj, sizeof(obj));
// 	if (argc < 2 || !argv || !validate_argv(argc, argv))
// 		return (0);
// 	obj.len = argc - 1;
// 	obj.argv = argv;
// 	obj.stck_a = create_lnkd_lst(&obj, argc - 1);
// 	print_content_lnkd_list(&obj);
// 	// if (!manipulate_stacks(&obj))
// 	// 	return (0);
// 	// verify_order_of_data(&obj);
// 	delete_lnkd_list(&obj, &(obj.stck_a));
// 	printf("address of stack_a after freeing list: %p\n", obj.stck_a);
// 	return (0);
// }


/*

NAME_C			= checker

# CFLAGS	= -Wall -Wextra -Werror -g
CFLAGS	= #-Wall -Wextra -Werror -g

NAME_PS 		= push_swap

# SRC 	= $(wildcard src/*.c)
SRC_C 	=	src/checker.c \
			src/ps_operation.c \
			src/shared_funcs.c \

SRC_PS	=	src/push_swap.c
			src/shared_funcs.c \

# CHECKER_ SRC	= src/checker.c src/ps_operation.c

LIB 			= ./libft

LIB_A			= ./libft/libft.a

INC 			= -I inc -I libft/includes

OBJ				= $(patsubst src/%.c,obj/%.o,$(SRC))


all: $(NAME_C)

$(NAME_C): $(OBJ) libft/libft.a
	@echo "compiling ..."
	$(CC) -o $@ $(CFLAGS) $(INC) $(SRC_C) $(LIB_A)
	@echo "Done !!!"
	# $(CC) -o $@ $(CFLAGS) $(INC) $(CHECKER_SRC) $(LIB_A)

# $(NAME_PS): $(OBJ) libft/libft.a
# 	@echo "compiling ..."
# 	$(CC) -o $@ $(CFLAGS) $(INC) $(SRC_PS) $(LIB_A)
# 	@echo "Done !!!"
# 	# $(CC) -o $@ $(CFLAGS) $(INC) $(CHECKER_SRC) $(LIB_A)

obj/%.o: src/%.c inc/ft_pushswap.h
	@mkdir -p obj
	$(CC) -c $(CFLAGS) $(INC) -o $@ $<
	@echo "obj files done ..."

libft/libft.a: $(wildcard libft/*.c)
	@$(MAKE) -C $(LIB)

clean:
	@echo "cleaning ..."
	@make clean -C $(LIB)
	@rm -rf obj

fclean:	clean
	@make fclean -C $(LIB)
	@rm -rf $(NAME_C) test
	@rm -rf $(NAME_PS) test

test: test.c $(NAME)
	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

re:	fclean all

 */