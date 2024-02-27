NAME = so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
RM			=	rm -rf


#FILES AND PATH
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	src/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCPATH_SRCS	=so_long.c main.c parsing.c init_stack.c
SRCPATH_DIR	=	src/
SRCPATH		=	$(addprefix $(SRCPATH_DIR), $(SRCPATH_SRCS))
OBJ_SRC		=	$(SRCPATH:.c=.o)

UTILSPATH_SRCS	=ft_split.c ft_strdup.c
UTILSPATH_DIR	=utils/
UTILSPATH		=$(addprefix $(UTILSPATH_DIR), $(UTILSPATH_SRCS))
OBJ_UTILS		=$(UTILSPATH:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME): 		$(OBJ_SRC) $(OBJ_UTILS)
				@$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_UTILS) -o $(NAME)
				@echo "$(GREEN)$(NAME) Created!$(DEFAULT)"


all:			$(NAME)

clean:
				@$(RM) $(OBJ_SRC) $(OBJ_UTILS)
				@echo "$(YELLOW)Object Files Deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)All Deleted!$(DEFAULT)"

# bonus:			$(OBJ_F) $(OBJ_SRC) $(OBJ_B) $(OBJ_GNL) $(OBJ_BONUS)
# 				@$(CC) ${CFLAGS} $(OBJ_F) $(OBJ_SRC) $(OBJ_B) $(OBJ_GNL) $(OBJ_BONUS) -o checker
# 				@echo "$(PINK)$(BONUS_NAME) with bonus created!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PINK 	= \033[1;45m
DEFAULT = \033[0m