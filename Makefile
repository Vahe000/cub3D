NAME		= cub3D
SRCS		= $(wildcard ./srcs/*.c)
O_FILES		= objects
OBJS		= $(patsubst ./srcs/%.c, ./$(O_FILES)/%.o, $(SRCS))
CC			= gcc
INCLUDES	= -I./includes 
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
MINILBX		= -lmlx -framework OpenGL -framework AppKit

./objects/%.o: ./srcs/%.c ./includes/*.h
	@$(CC) $(CFLAGS) $(INCLUDES) -Imlx -o $@ -c $<

all : $(NAME)

$(NAME) : $(O_FILES) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MINILBX) -o $(NAME)
	@echo "$(GRN)$(NAME) created!$(DEF)"

$(O_FILES) :
	mkdir $(O_FILES)

clean :
	$(RM) $(OBJS)
	@echo "$(YEL)Object files deleted!$(DEF)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED)All deleted!$(DEF)"

re : fclean all

.PHONY: all clean fclean re

#COLORS
BLK = \033[0;30m
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m
RED = \033[1;31m
DEF = \033[0m
