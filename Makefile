SRCS = ./SRCS/ft_fractol.c 

FLAGS = -Wall -Wextra -Werror

NAME = fractol

LIBFT = libft

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@rm -rf fractol
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

debug:
	@gcc $(FLAGS) $(SRCS) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address


