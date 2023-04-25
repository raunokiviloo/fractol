NAME = fractol

LIBFT = $(DIR_LIBFT)/libft.a
MINILIBX = $(DIR_MINILIBX)/libmlx.a

DIR_LIBFT = libft
DIR_MINILIBX = mlx_linux
DIR_OBJ = obj/

SRC = events.c fractol.c init.c render.c util.c   
VPATH = src

HEADER = inc/fractol.h

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(DIR_LIBFT)/*.o
OBJS = $(addprefix $(DIR_OBJ), $(OBJ))

RM = rm -f

CC = clang
INC = -I./inc -I/usr/include -Imlx_linux -Ilibft
LIB = -Lmlx_linux -lmlx_Linux -Llibft -lft -L/usr/lib -lXext -lX11 -lm
CFLAGS = -Wall -Wextra -Werror -ggdb


all: $(NAME) 

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "Successfully made $(NAME)!"
	
$(LIBFT): $(SRC_LIBFT)
	@$(MAKE) -s -C $(DIR_LIBFT)
	
$(MINILIBX): $(SRC_MINILIBX)
	@$(MAKE) -s -C $(DIR_MINILIBX)

$(DIR_OBJ)%.o: %.c $(HEADER)
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< $(INC) -o $@
	
bonus: all 
	
clean:
	@$(RM) $(OBJS) $(OBJ_LIBFT)
	@echo "Objects removed successfully!"

fclean: clean
	@$(RM) $(LIBFT) $(MINILIBX) $(NAME)
	@echo "Executable removed successfully!"

re:	fclean all

.PHONY:	all, bonus, clean, fclean, re
