SRCS = $(addprefix srcs/,main.c key_handler.c closing.c read_map.c load_textures.c draw.c patrols.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L minilibx-linux -lmlx -lXext -lX11 -lm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C libft

bonus: all

.PHONY: all clean fclean re bonus
