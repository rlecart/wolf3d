# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 00:43:30 by rlecart           #+#    #+#              #
#    Updated: 2017/07/27 22:17:57 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	WOLF3D
NAME		=	wolf3d
BINDIR		=	bin/
SRCDIR		=	src/
SRC			=	main.c \
				init.c \
				menu.c \
				menu_hook.c \
				solo.c \
				load.c \
				multi.c \
				options.c \
				credits.c \
				display.c \
				texture.c \
				bitmap.c

MINILIBX	=	minilibx_macos/libmlx.a
SDL			=	SDL2-2.0.5/build/.libs/libSDL2.a
LIBFT		=	libft/libft.a
GRAPHICS	=	graphics/graphics.a
OBJ			=	$(addprefix $(BINDIR),$(SRC:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -O2 -Ofast $(INC)
INC			=	-I includes/ -I libft/includes/ -I graphics/includes/ -I SDL2-2.0.5/include/
MLXF		=	-framework OpenGL -framework AppKit
SDLF		=	-framework Cocoa -framework CoreAudio -framework AudioToolbox \
				-framework ForceFeedback -framework CoreVideo -framework Carbon \
				-framework IOKit -liconv

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: sdl mlx lib gra $(NAME)

$(NAME): $(SDL) $(MINILIBX) $(LIBFT) $(GRAPHICS) $(BINDIR) $(OBJ)
	@printf "\r$(GREEN)[$(PROJECT)] Bin compilation done.                                                        \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(SDLF) $(MLXF) -o $(NAME) $(OBJ) $(SDL) $(MINILIBX) $(LIBFT) $(GRAPHICS)
	@printf "\r$(GREEN)[$(PROJECT)] Compilation done.                          \n$(NO_COLOR)"

$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@                                                          \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

sdl: $(SDL)

$(SDL):
	@printf "$(YELLOW)[SDL] Configuration...                                                     \r$(NO_COLOR)"
	@cd SDL2-2.0.5/ && ./configure 2> /dev/null > /dev/null
	@printf "\r$(GREEN)[SDL] Configuration done.                                                   \n$(NO_COLOR)"
	@printf "$(YELLOW)[SDL] Compiling bin...                                                     \r$(NO_COLOR)"
	@make -s -C SDL2-2.0.5 2> /dev/null > /dev/null
	@printf "\r$(GREEN)[SDL] Compilation done.                                                   \n$(NO_COLOR)"

mlx:
	@make -s -C minilibx_macos 2> /dev/null > /dev/null

lib:
	@make -s -C libft

gra:
	@make -s -C graphics

$(BINDIR):
	@mkdir bin

clean:
	@make -s -C libft clean
	@make -s -C graphics clean
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Bin removed.                                                   \n$(NO_COLOR)"

fclean:
	@make -s -C SDL2-2.0.5 clean
	@make -s -C minilibx_macos clean
	@make -s -C libft fclean
	@make -s -C graphics fclean
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Bin removed.                                                   \n$(NO_COLOR)"
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                               \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
