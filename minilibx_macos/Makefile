#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: $(NOM)

$(NOM):	$(OBJ)
	@printf "\r$(GREEN)[MINILIBX] Bin compilation done.                                                  \n"
	@printf "$(YELLOW)[MINILIBX] Compiling $(NOM)..."
	ar rc $(NOM) $(OBJ)
	ranlib $(NOM)
	@printf "\r$(GREEN)[MINILIBX] $(NOM) compiled.                                           \n$(NO_COLOR)"

clean:
	@printf "$(YELLOW)[MINILIBX] Removing bin..."
	rm -f $(NOM) $(OBJ) *~
	@printf "\r$(GREEN)[MINILIBX] Bin removed.                                 \n$(NO_COLOR)"
	@printf "$(YELLOW)[MINILIBX] Removing $(NOM)..."
	rm -f mlx_app
	@printf "\r$(GREEN)[MINILIBX] $(NOM) removed...                               \n$(NO_COLOR)"

re: clean all
