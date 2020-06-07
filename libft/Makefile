# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/29 17:19:55 by bprado        #+#    #+#                  #
#    Updated: 2020/04/10 17:15:50 by macbook       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= 	libft.a

FLAGS=	-Wall -Wextra -Werror -02

SRC=	$(wildcard src/*.c)

OBJ=	$(patsubst src/%.c,obj/%.o,$(SRC))

CC=		gcc

# Colors
PURPLE = \033[95m
CYAN = \033[96m
DARKCYAN = \033[36m
BLUE = \033[94m
GREEN = \033[92m
YELLOW = \033[93m
RED = \033[91m
BOLD = \033[1m
# UNDERLINE = \033[4m
END = \033[0m

# tput commands
BOLD := `tput bold`
UNDERLINE := `tput smul`
END_TPUT := `tput sgr0`


all: $(NAME)

begin_statement:
	@printf "$(BOLD) *** Compiling $(NAME) ***$(END_TPUT)\n"

$(NAME): begin_statement $(OBJ)
	@printf " -- libft obj files done. --\n"
	@ar rcs $(NAME) $(OBJ)
	@printf " $(CYAN)$(BOLD)$(UNDERLINE)$(NAME)$(END)$(END_TPUT) created\n"

obj/%.o: src/%.c inc/libft.h
	@mkdir -p obj
	@printf " $(GREEN)$(BOLD)✔$(END)$(END_TPUT) Object file for $(PURPLE)$<$(END)\n"
	@$(CC) -o $@ -c $< $(CFLAGS) -I inc -I .

clean:
	@printf "Cleaning $(YELLOW)$(BOLD)$(NAME)$(END)$(END_TPUT)..."
	@rm -rf obj
	@printf " complete!\n"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

# %.o: %.c
# 	@gcc $(FLAG) -c $< -o $@

# The name of the first prerequisite
# The file name of the target of the rule.
