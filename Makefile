# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 16:52:44 by bprado         #+#    #+#                 #
#    Updated: 2020/02/10 17:20:30 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= checker

CFLAGS	= -Wall -Wextra -Werror -g

SRC 	= $(wildcard src/*.c)

LIB 	= ./libft

LIB_A	= ./libft/libft.a

INC 	= -I inc -I libft/includes

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))


all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@echo "compiling ..."
	$(CC) -o $@ $(CFLAGS) $(INC) $(SRC) $(LIB_A)
	@echo "Done !!!"

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
	@rm -rf $(NAME) test

test: test.c $(NAME)
	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

re:	fclean all
