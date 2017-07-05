# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 15:16:35 by rlecart           #+#    #+#              #
#    Updated: 2017/06/20 00:03:08 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	GRAPHICS
NAME		=	graphics.a
BINDIR		=	bin/
SRCDIR		=	src/
SRC			=	drawline.c \
				img.c \
				color.c \
				pixel.c \
				print.c
OBJ			=	$(addprefix $(BINDIR),$(SRC:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -O2 -Ofast

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: $(NAME)

$(NAME): $(BINDIR) $(OBJ)
	@printf "\r$(GREEN)[$(PROJECT)] Bin compilation done.                                                  \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) compiled.                                           \n$(NO_COLOR)"

$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@                                                       \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(BINDIR):
	@mkdir bin

clean:
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Obj removed.                                                \n$(NO_COLOR)"

fclean: clean
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                            \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
