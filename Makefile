# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 16:52:44 by bprado        #+#    #+#                  #
#    Updated: 2020/06/11 17:34:11 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= 	checker

CFLAGS		= 	-Wall -Wextra -Werror

NAME_PS 	= 	push_swap

SRC_C 		=	src/checker.c \
				src/shared_core_operations.c \
				src/shared_input_validation.c \
				src/shared_array_delete_funcs.c

SRC_PS		=	src/push_swap.c \
				src/push_swap_helpers.c \
				src/shared_core_operations.c \
				src/shared_input_validation.c \
				src/shared_array_delete_funcs.c\
				src/print_functions.c

LIB 		= 	./libft

LIB_A		= 	./libft/libft.a

INC 		= 	-I inc -I libft/inc

OBJ			= 	$(patsubst src/%.c,obj/%.o,$(SRC_C))

CC			=	gcc

# Colors
PURPLE		= \033[95m
CYAN		= \033[96m
DARKCYAN	= \033[36m
BLUE		= \033[94m
GREEN		= \033[92m
YELLOW		= \033[93m
RED			= \033[91m
END			= \033[0m

# tput commands
BOLD		:= `tput bold`
UNDERLINE	:= `tput smul`
END_TPUT	:= `tput sgr0`

all: $(NAME) $(NAME_PS)

# $(NAME) must be used to comply to norminette

begin_statement:
	@printf "$(BOLD) *** Compiling $(NAME) & $(NAME_PS) ***$(END_TPUT)\n"

$(NAME): begin_statement $(OBJ) libft/libft.a
	@$(CC) -o $@ $(CFLAGS) $(INC) $(OBJ) $(LIB_A)
	@printf " $(CYAN)$(BOLD)$(UNDERLINE)./$(NAME)$(END)$(END_TPUT) created\n"


$(NAME_PS): $(OBJ) libft/libft.a
	@$(CC) -o $@ $(CFLAGS) $(INC) $(SRC_PS) $(LIB_A)
	@printf " $(CYAN)$(BOLD)$(UNDERLINE)./$(NAME_PS)$(END)$(END_TPUT) created\n"

obj/%.o: src/%.c inc/ft_push_swap.h
	@mkdir -p obj
	@$(CC) -c $(CFLAGS) $(INC) -o $@ $<
	@printf " $(GREEN)$(BOLD)✔$(END)$(END_TPUT) Object file for $(PURPLE)$<\
	$(END)\n"

libft/libft.a: $(wildcard libft/*.c)
	@$(MAKE) -C $(LIB)

clean:
	@printf "Cleaning$(BOLD)   $(NAME_PS) object files$(END_TPUT)\n"
	@make clean -C $(LIB)
	@rm -rf obj

# removed prerequisite of clean to fclean to eliminte repeated printf text
fclean:
	@printf "Cleaning$(BOLD)   $(NAME_PS) object files$(END_TPUT)\n"
	@printf "Deleting$(YELLOW)$(BOLD)   ./$(NAME) & ./$(NAME_PS)$(END) \
	binaries$(END_TPUT)\n"
	@rm -rf obj
	@rm -rf $(wildcard *.dSYM)
	@rm -rf $(NAME) test
	@rm -rf $(NAME_PS) test
	@make fclean -C $(LIB)
	@printf "$(GREEN)$(BOLD)Complete!$(END)$(END_TPUT)\n"

test: test.c $(NAME)
	@$(CC) -o $@ -Wall -Wextra -g $(INC) $^

re:	fclean all
