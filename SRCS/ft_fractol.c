#include "../HEADERS/ft_fractol.h"
#include <stdio.h> ///// REMOVEEEEEEEEEEEE
// BONUS ----->
//Two valid parameters in the command line, resulting in two fractals in two windows.

int		main(int argc, char **argv)
{
	t_info *info;

	info = (t_info*)ft_memalloc(sizeof(t_info));
	if (argc == 2)
	{
		init_struct(info, argc);
		arg_check(argv[1], info);
		if (info->check_j || info->check_m || info->check_b)
		{
			handle_mlx(info);
			check_form(info);
			printf("success!\n"); ///// REMOVE
			// mlx_hook(info->mlx_window, 4, 0, mouse_management, info);
			// mlx_hook(info->mlx_window, 2, 0, key_management, info);
			// mlx_hook(info->mlx_window, 6, 0, motion_management, info);
			// mlx_hook(info->mlx_window, 17, 0, ft_close, info);
			mlx_loop(info->mlx);
		}
	}
	else
		error_management(argc, info);
}

/*
** Here we check again, a third time to see which argument/fractal was passed
** and which fractal algorithm function to use and from there it will go through
** a series of functions and after print it into a mlx window.
*/

void	check_form(t_info *info)
{
	mlx_clear_window(info->mlx, info->mlx_window);
	if (info->check_m)
		ft_mandelbrot(info); //function for mandelbrot
	//if (info->check_j)
	//	ft_julia(info); //function for julia
	//if (info->check_b)
	//	ft_burns(info); //funciton for burns
	else
	{
		ft_putendl("Error");
		exit(1);
	}
	
}

void	all_pixel(t_info *info, int x, int y, int pix_color)
{
	void	*i;
	int		c_val;

	if (x < WIDTH && y < HEIGHT)
	{
		i = mlx_get_data_addr(info->mlx_image, &(info->bits_per_pix), &(info->size_l), &(info->endian));
		c_val = mlx_get_color_value(info->mlx, pix_color);
		ft_memcpy(i + 4 * WIDTH * y + x * 4, &c_val, sizeof(int));
	}
}

void	ft_mandelbrot(t_info *info)
{
	while(info->mandel->x != WIDTH)
	{
		info->mandel->y = 0;
		while(info->mandel->y != HEIGHT)
		{
			m_scale(info);
			info->mandel->count = 0;
			while (++info->mandel->count != info->mandel->p_iterate &&  
			(sqrt((info->mandel->imag_x * info->mandel->imag_x) + (info->mandel->imag_y * info->mandel->imag_y)) < 3)) // 3.0
				square_root_mandel(info->mandel);
			if (info->mandel->p_iterate == info->mandel->count)
				all_pixel(info, info->mandel->x, info->mandel->y, 0);
			else
				all_pixel(info, info->mandel->x, info->mandel->y, info->mandel->count * info->mandel->color);
			info->mandel->y++;
		}
		info->mandel->x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->mlx_image, 0, 0);
}

t_man		*square_root_mandel(t_man *mandel)
{
	mandel->temp = (mandel->imag_x * mandel->imag_x) - (mandel->imag_y * mandel->imag_y);
	mandel->real_x = mandel->temp;
	mandel->real_y = 2 * mandel->imag_x * mandel->imag_y;
	mandel->imag_x = mandel->real_x + mandel->imag_x;
	mandel->imag_y = mandel->real_y + mandel->imag_y;
	mandel->temp = 0;
	return (mandel);
}

void		m_scale(t_info *info)
{
	info->mandel->imag_x = ((double)(info->mandel->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->x_offset);
	info->mandel->imag_y = ((double)(info->mandel->y - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->y_offset);
	info->mandel->temp_x = info->mandel->imag_x;
	info->mandel->temp_y = info->mandel->imag_y;
}


// void	ft_julia(t_info *info)
// {

// }

// void	ft_burns(t_info *info)
// {

// }

void	handle_mlx(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_window = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fractol");
	info->mlx_image = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->mlx_ptr = mlx_get_data_addr(info->mlx_image, &(info->bits_per_pix),
	&(info->size_l), &(info->endian));
}

void	arg_check(char	*str, t_info *info)
{
	if (ft_strcmp(str, "mandel") == 0)
		info->check_m = 1;
	else if (ft_strcmp(str, "julia") == 0)
		info->check_j = 1;
	else if (ft_strcmp(str, "burns") == 0)
		info->check_b = 1;
	else
		error_management(info->arg, info);
}

void	init_struct(t_info *info, int argc)
{
	info->mandel = (t_man*)ft_memalloc(sizeof(t_man));
	info->julia = (t_jul*)ft_memalloc(sizeof(t_jul));
	info->burns = (t_bur*)ft_memalloc(sizeof(t_bur));
	info->events = (t_evn*)ft_memalloc(sizeof(t_evn));
	info->arg = argc;
	info->mandel->x = 0;
	info->mandel->y = 0;
	info->mandel->imag_x = 0;
	info->mandel->imag_y = 0;
	info->mandel->temp_x = 0;
	info->mandel->temp_y = 0;
	info->mandel->temp = 0;
	info->mandel->color = 25;
	info->mandel->count = 0;
	info->mandel->p_iterate = 50;
	info->mandel->real_x = 0;
	info->mandel->real_y = 0;
	info->julia->x = 0;
	info->julia->y = 0;
	info->julia->imag_x = 0;
	info->julia->imag_y = 0;
	info->julia->temp_x = 0;
	info->julia->temp_y = 0;
	info->julia->count = 0;
	info->julia->p_iterate = 0;
	info->julia->real_x = 0;
	info->julia->real_y = 0;
	info->burns->x = 0;
	info->burns->y = 0;
	info->burns->imag_x = 0;
	info->burns->imag_y = 0;
	info->burns->temp_x = 0;
	info->burns->temp_y = 0;
	info->burns->count = 0;
	info->burns->p_iterate = 0;
	info->burns->real_x = 0;
	info->burns->real_y = 0;
	info->check_m = 0;
	info->check_j = 0;
	info->check_b = 0;
	info->events->zoom = 1;
	info->events->x_offset = 0;
	info->events->y_offset = 0;
}

void	error_management(int argc, t_info *info)
{
	if (argc < 2)
	{
		ft_putendl("Usage: Not enough arguments...ex [mandel, julia, burns]");
		free(info);
		exit(1);
	}
	if (argc > 2)
	{
		ft_putendl("Usage: Too many arguments...");
		free(info);
		exit(1);
	}
	if (!(info->check_m && info->check_j && info->check_b))
	{
		ft_putendl("Usage: Wrong Argument..ex [mandel, julia, burns]");
		free(info);
		exit(1);
	}
}

// int		mouse_management(int key, int x, int y, t_info *info)
// {
// 	if (key == 5)
// 		info->events->zoom -= (info->events->zoom / 10);
// 	if (key == 4)
// 		info->events->zoom += (info->events->zoom / 10);
// 	check_form(info);
// 	return (0);
// }

// int	key_management(int key, t_info *info)
// {

// }

// int	motion_management(int key, t_info *info)
// {

// }

// int		ft_close(void *ptr)
// {
// 	(void)ptr;
// 	exit(0);
// }