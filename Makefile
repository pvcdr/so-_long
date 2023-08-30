NAME = so_long

SRC = src/main.c\
	src/error.c\
	src/game.c\
	src/init.c\
	src/maps.c\
	src/move.c\
	src/textures.c\
	src/error2.c\

INC = includes/ft_printf/ft_format.c\
	includes/ft_printf/ft_print_number.c\
	includes/ft_printf/ft_print_str.c\
	includes/ft_printf/ft_printf.c\
	includes/get_next_line/get_next_line_utils.c\
	includes/get_next_line/get_next_line.c

LIBFT_A = libft.a
LIBFT_DIR = ./includes/Libft

OBJ = $(SRC:.c=.o)

CC = cc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_A)
	$(CC) $(OBJ) $(INC) -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_DIR)/$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT_DIR)/$(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re
