#include "../HEADERS/ft_fractol.h"

int		check_fractal(t_info *info)
{
	mlx_clear_window(info->mlx, info->mlx_window);
	if (info->check_m)
	{
		ft_mandelbrot(info);
		control_window(info);
	}
	if (info->check_j)
    {
	 	ft_julia(info);
		control_window(info);
    }
    if (info->check_b)
    {
	    ft_burn_s(info);
		control_window(info);
    }
	return(0);
}

int		mlx_controls(t_info *info)
{
	check_fractal(info);
	mlx_hook(info->mlx_window, 2, 0, key_management, info);
	mlx_hook(info->mlx_window, 4, 0, mouse_management, info);
	mlx_hook(info->mlx_window, 6, 0, motion_management, info);
	mlx_hook(info->mlx_window, 17, 0, ft_close, info);
	return(0);
}
int		key_management(int key, t_info *info)
{
	if(key == 53)
		exit(1);
	if(key == 38)
		info->julia_tick = 1;
	info = key_color_up(key, info);
	info = key_color_down(key,info);
	info = key_iteration(key, info);
	info = key_zoom_move(key, info);
	check_fractal(info);
	return(0);
}

t_info		*key_zoom_move(int key, t_info *info)
{	
	double	z;

	z = info->events->zoom;
	if (key == 19)
		info->events->zoom -= (z / 10);
	else if (key == 18)
		info->events->zoom += (z / 10);
	else if (key == 125)
		info->events->y_offset -= .01 * z * 2;
	else if (key == 126)
		info->events->y_offset += .01 * z * 2;
	else if (key == 124)
		info->events->x_offset -= .01 * z * 2;
	else if (key == 123)
		info->events->x_offset += .01 * z * 2;
	return(info);
}
t_info		*key_iteration(int key, t_info *info)
{
	if (info->check_m)
	{
		if (key == 24 && info->mandel->iterate_max < 81)
			info->mandel->iterate_max += 20;			
		if (key == 27 && info->mandel->iterate_max > 20)
			info->mandel->iterate_max -= 20;
		else if(key == 24 && info->mandel->iterate_max > 80)
			info->max_trigger = 1;
	}
	else if (info->check_j)
	{
		if (key == 24 && info->julia->iterate_max < 81)
			info->julia->iterate_max += 20;
		if (key == 27 && info->julia->iterate_max > 20)
			info->julia->iterate_max -= 20;
		else if(key == 24 && info->julia->iterate_max > 80)
			info->max_trigger = 1;
	}
	else if (info->check_b)
	{
		if (key == 24 && info->burn_s->iterate_max < 81)
			info->burn_s->iterate_max += 20;
		if (key == 27 && info->burn_s->iterate_max > 20)
			info->burn_s->iterate_max -= 20;
		else if(key == 24 && info->burn_s->iterate_max > 80)
			info->max_trigger = 1;
	}
	return(info);
}
t_info		*key_color_down(int key, t_info *info)
{
	if (info->check_m && key == 9)
	{
		if (info->mandel->color > 2051)
			info->mandel->color /= 2;
	}
	if (info->check_j && key == 9)
	{
		if (info->julia->color > 2051)
			info->julia->color /= 2;
	}
	if (info->check_b && key == 9)
	{
		if (info->burn_s->color > 2051)
			info->burn_s->color /= 2;
	}
	return(info);
}

t_info		*key_color_up(int key, t_info *info)
{
	if (info->check_m && key == 8)
	{
		if (info->mandel->color < 90000000)
			info->mandel->color *= 2;
	}
	if (info->check_j && key == 8)
	{
		if (info->julia->color < 90000000)
			info->julia->color *= 2;
	}
	if (info->check_b && key == 8)
	{
		if (info->burn_s->color < 90000000)
			info->burn_s->color *= 2;
	}
	return(info);
}

int		motion_management(int x, int y, t_info *info)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (info->check_j && info->julia_tick)
			info = motion_j(x,y,info);
		check_fractal(info);
	}
	return (0);
}

t_info		*motion_j(int x, int y, t_info *info)
{
	info->julia->imag_xy = ((double)x / (WIDTH));
	info->julia->imag_yx = ((double)y / (WIDTH));
	if (info->julia->imag_xy > 2)
		info->julia->imag_xy = info->julia->imag_xy - 2;
	if (info->julia->imag_yx > 2)
		info->julia->imag_yx = info->julia->imag_yx - 2;
	return(info);
}

void	control_window(t_info *info)
{
	if(info->max_trigger)
	{
		mlx_string_put(info->mlx, info->mlx_window, 0,
			120, 0xFF0000, "MAX ITERATION WARNING!!\n");
		info->max_trigger = 0;
	}
	mlx_string_put(info->mlx, info->mlx_window, 0,
		0, 0x00FF00, "Move [<] [^] [v] [>]");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		20, 0x00FF00, "Zoom [1] IN [2] OUT");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		40, 0x00FF00, "Iterate [+] UP [-] DOWN");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		60, 0x00FF00, "Color [c]");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		80, 0x00FF00, "Mouse use for Julia [j]");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		100, 0x00FF00, "Exit [esc]");
}
void	arg_check(char	*str, t_info *info)
{
	if (ft_strcmp(str, "mandel") == 0)
		info->check_m = 1;
	else if (ft_strcmp(str, "julia") == 0)
		info->check_j = 1;
	else if (ft_strcmp(str, "burn_s") == 0)
		info->check_b = 1;
	else
		error_management(info->arg, info);
}

void	error_management(int argc, t_info *info)
{
	if (argc < 2)
	{
		ft_putendl("Usage: Not enough arguments...ex [mandel, julia, burn_s]");
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
		ft_putendl("Usage: Wrong Argument..ex [mandel, julia, burn_s]");
		free(info);
		exit(1);
	}
}