NAME = fractol

LIBFT = $(DIR_LIBFT)/libft.a
MINILIBX = $(DIR_MINILIBX)/*.a

DIR_LIBFT = libft
DIR_MINILIBX = mlx_linux
DIR_SRC = src

SRC = $(DIR_SRC)/fractol.c
SRC_LIBFT = $(DIR_LIBFT)/*.c
SRC_MINILIBX = $(DIR_MINILIBX)/*.c 

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(DIR_LIBFT)/*.o

RM = rm -f

CC = clang

CFLAGS = -Wall -Wextra -Werror -ggdb


all: $(NAME)

bonus: all 

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Successfully made $(NAME)!"
	
$(LIBFT): $(SRC_LIBFT)
	@$(MAKE) -s -C $(DIR_LIBFT)
	
$(MINILIBX): $(SRC_MINILIBX)
	@$(MAKE) -s -C $(DIR_MINILIBX)
		
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -Ilibft -O3 -c $< -o $@
	
clean:
	@$(RM) $(OBJ) $(OBJ_LIBFT)
	@echo "Objects removed successfully!"

fclean: clean
	@$(RM) $(LIBFT) $(MINILIBX) $(NAME)
	@echo "Executable removed successfully!"

re:	fclean all

.PHONY:	all, bonus, clean, fclean, re
