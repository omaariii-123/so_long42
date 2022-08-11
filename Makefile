CC = gcc

CFLAGS = -Wall  -Werror -Wextra

LIBS = -Imlx -Lmlx -lmlx -framework OpenGL -framework Appkit 


RM = rm -f

O_FILES =  $(FILES:.c=.o)

FILES = so_long.c  ft_movments.c ft_draw.c ft_move.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_check_errors.c 

all : NAME

NAME : ./so_long

./so_long : $(O_FILES)
	$(CC) $(O_FILES) $(LIBS) -o $@ 

clean :
	$(RM) *.o
fclean : clean
	$(RM) so_long  

re : fclean all
