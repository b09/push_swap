# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 16:52:44 by bprado         #+#    #+#                 #
#    Updated: 2020/03/02 19:16:11 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


# NAME 			= checker push_swap

# # CFLAGS	= -Wall -Wextra -Werror -g
# CFLAGS	= #-Wall -Wextra -Werror -g

# SRC 	= $(wildcard src/*.c)

# # CHECKER_ SRC	= src/checker.c src/ps_operation.c

# LIB 			= ./libft

# LIB_A			= ./libft/libft.a

# INC 			= -I inc -I libft/includes

# OBJ				= $(patsubst src/%.c,obj/%.o,$(SRC))


# all: $(NAME)

# checker: $(OBJ) libft/libft.a
# 	@echo "compiling ..."
# 	$(CC) -o $@ $(CFLAGS) $(INC) $(SRC) $(LIB_A)
# 	@echo "Done !!!"

# push_swap:

# obj/%.o: src/%.c inc/ft_push_swap.h
# 	@mkdir -p obj
# 	$(CC) -c $(CFLAGS) $(INC) -o $@ $<
# 	@echo "obj files done ..."

# libft/libft.a: $(wildcard libft/*.c)
# 	@$(MAKE) -C $(LIB)

# clean:
# 	@echo "cleaning ..."
# 	@make clean -C $(LIB)
# 	@rm -rf obj

# fclean:	clean
# 	@make fclean -C $(LIB)
# 	@rm -rf $(NAME) test

# test: test.c $(NAME)
# 	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

# re:	fclean all







NAME			= checker

# CFLAGS	= -Wall -Wextra -Werror -g
CFLAGS	= #-Wall -Wextra -Werror -g

NAME_PS 		= push_swap

# SRC 	= $(wildcard src/*.c)
SRC_C 	=	src/checker.c \
			src/ps_operation.c \
			src/shared_funcs.c \

SRC_PS	=	src/push_swap.c \
			src/shared_funcs.c \
			src/push_swap_extra.c

# CHECKER_ SRC	= src/checker.c src/ps_operation.c

LIB 			= ./libft

LIB_A			= ./libft/libft.a

INC 			= -I inc -I libft/includes

OBJ				= $(patsubst src/%.c,obj/%.o,$(SRC_C))


all: $(NAME) $(NAME_PS)

# $(NAME) must be used to comply to norminette

$(NAME): $(OBJ) libft/libft.a
	@echo "compiling ..."
	$(CC) -o $@ $(CFLAGS) $(INC) $(OBJ) $(LIB_A)
	@echo "Done !!!"
	# $(CC) -o $@ $(CFLAGS) $(INC) $(CHECKER_SRC) $(LIB_A)

$(NAME_PS): $(OBJ) libft/libft.a
	@echo "compiling ..."
	$(CC) -o $@ $(CFLAGS) $(INC) $(SRC_PS) $(LIB_A)
	@echo "Done !!!"
	# $(CC) -o $@ $(CFLAGS) $(INC) $(CHECKER_SRC) $(LIB_A)

obj/%.o: src/%.c inc/ft_push_swap.h
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
	@rm -rf $(NAME) test
	@rm -rf $(NAME_PS) test

test: test.c $(NAME)
	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

re:	fclean all
