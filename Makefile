NAME = so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
MLX_FLAGS	=	-L mlx -lmlx -framework OpenGL -framework AppKit
MLX			=	MLX/libmlx.a
RM			=	rm -rf


#FILES AND PATH
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	src/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCPATH_SRCS	=main.c parsing.c init_stack.c path_finding.c map_init.c player_controller.c exitandfree.c enemy.c
SRCPATH_DIR	=	src/
SRCPATH		=	$(addprefix $(SRCPATH_DIR), $(SRCPATH_SRCS))
OBJ_SRC		=	$(SRCPATH:.c=.o)

UTILSPATH_SRCS	=ft_split.c ft_strdup.c ft_memset.c ft_itoa.c ft_memcpy.c
UTILSPATH_DIR	=utils/
UTILSPATH		=$(addprefix $(UTILSPATH_DIR), $(UTILSPATH_SRCS))
OBJ_UTILS		=$(UTILSPATH:.c=.o)

BONUS_NAME 	=	so_long_bonus

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_SRC) $(OBJ_UTILS) $(MLX)
				@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_SRC) $(OBJ_UTILS) $(MLX) -o $(NAME) 
				@echo "$(GREEN)$(NAME) Created!$(DEFAULT)"
$(MLX):
				@$(MAKE) -C mlx/

all:			$(NAME)

clean:
				@$(RM) $(OBJ_SRC) $(OBJ_UTILS)
				@$(MAKE) -C mlx/ clean
				@echo "$(YELLOW)Object Files Deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME) $(BONUS_NAME)
				@echo "$(RED)All Deleted!$(DEFAULT)"

bonus:			$(OBJ_SRC) $(OBJ_UTILS) $(MLX)
				@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_SRC) $(OBJ_UTILS) $(MLX) -o $(BONUS_NAME)
				@echo "$(PINK)so_long with bonus created!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PINK 	= \033[1;45m
DEFAULT = \033[0m