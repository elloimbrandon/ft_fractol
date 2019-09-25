#include "../HEADERS/ft_fractol.h"
#include <stdio.h> ///// REMOVEEEEEEEEEEEE


int		main(int argc, char **argv)
{
	int i;
	t_info *info;

	i = 0;
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
			// could change, just thinking ahead
			// mlx_hook(info->mlx_window, 2, 0, key_management, info);
			// mlx_hook(info->mlx_window, 4, 0, mouse_management, info);
			// mlx_hook(info->mlx_window, 6, 0, motion_management, info);
			// mlx_hook(info->mlx_window, 17, 0, ft_close, info);
			// mlx_loop(info->mlx);
		}
	}
	else
		error_management(argc, info);
}

void	check_form(t_info *info)
{
	if (info->check_m)
		ft_mandelbrot(info); //function for mandelbrot
	if (info->check_j)
		ft_julia(info); //function for julia
	if (info->check_b)
		ft_burns(info); //funciton for burns
	else
	{
		ft_putendl("Error");
		exit(1);
	}
	
}

void	i_window(t_info *info, t_info mlx_window, t_info mlx_image)
{

}

void	ft_mandelbrot(t_info *info)
{
	while(info->mandel->x != WIDTH)
	{
		while(info->mandel->y != HEIGHT)
		{
			m_scale(info);
			info->mandel->count = 0; // try without?
			while(++info->mandel->count != info->mandel->p_iterate &&  
			(sqrt((info->mandel->imag_x * info->mandel->imag_x) + (info->mandel->imag_y * info->mandel->imag_y)) < 3.0)) // dif func try 3
				square_root_madel(info->mandel);
			// handle madelbrot equation using correct var's
			  
			info->mandel->y++;
		}
		info->mandel->x++;
	}

}

t_man		square_root_mandel(t_man *mandel) // return pointer
{
	mandel->temp = (mandel->imag_x * mandel->imag_x) - (mandel->imag_y * mandel->imag_y);
	mandel->real_x = mandel->temp;
	mandel->real_y = 2 * mandel->imag_x * mandel->imag_y;
	mandel->imag_x = mandel->real_x + mandel->imag_x;
	mandel->imag_y = mandel->real_y + mandel->imag_y;
	return (*mandel);

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
	info->mandel->count = 0;
	info->mandel->p_iterate = 0;
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
	info->events->zoom = 0;
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

// void	mouse_management(int key, t_info *info)
// {

// }

// void	key_management(int key, t_info *info)
// {

// }

// void	motion_management(int key, t_info *info)
// {

// }

// int		ft_close(void *ptr)
// {
// 	(void)ptr;
// 	exit(0);
// }