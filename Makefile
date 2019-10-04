SRCS = ./SRCS/ft_fractol.c ./SRCS/scale_root.c ./SRCS/init_structs.c ./SRCS/ft_keys.c ./SRCS/ft_controls.c ./SRCS/checks_pix.c ./SRCS/fractols.c

NAME = fractol

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MINLIB = minilibx_macos

MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@make -C $(MINLIB)
	@gcc $(SRCS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

debug:
	@gcc $(SRCS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address
