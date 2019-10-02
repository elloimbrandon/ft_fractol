#include "../HEADERS/ft_fractol.h"

int		check_fractal(t_info *info)
{
	mlx_clear_window(info->mlx, info->mlx_window);
	if (info->check_m)
	{
		ft_mandelbrot(info);
		control_window(info);
		//mlx_controls(info);
	}
	else if (info->check_j)
    {
		// info->julia->imag_xy = -.73;
        // info->julia->imag_yx = -.19;
	 	ft_julia(info);
		control_window(info);
		//mlx_controls(info);
    }
    else if (info->check_b)
    {
		// info->burns->imag_xy = .0;
        // info->burns->imag_yx = .0;
	    ft_burns(info);
		control_window(info);
		//mlx_controls(info);
    }
	return(0);
}
// int		fractal_recheck(t_info *info)
// {
// 	//mlx_clear_window(info->mlx, info->mlx_window);
// 	if (info->check_m)
// 	{
// 		ft_mandelbrot(info);
// 		mlx_controls(info);
// 	}
// 	else if (info->check_j)
// 	{
// 	 	ft_julia(info);
// 		mlx_controls(info);
// 	}
//     else if (info->check_b)
// 	{
// 	    ft_burns(info);
// 		mlx_controls(info);
// 	}
// 	else
// 	{
// 		ft_putendl("Usage: .. Error");
// 		exit(1);
// 	}
// 	return(0);
// }
int		mlx_controls(t_info *info)
{
	//control_window(info);
	mlx_hook(info->mlx_window, 2, 0, key_management, info);
	mlx_hook(info->mlx_window, 4, 0, mouse_management, info);
	mlx_hook(info->mlx_window, 6, 0, motion_management, info);
	mlx_hook(info->mlx_window, 17, 0, ft_close, info);
	mlx_loop(info->mlx);
	return(0);
}

int		key_management(int key, t_info *info)
{
	if(key == 52)
		exit(1);
	key_color(key, info);
	key_iteration(key, info);
	key_zoom_move(key, info);
	//mlx_clear_window(info->mlx, info->mlx_window);
	check_fractal(info);
	// fractal_recheck(info);
	return(0);
}

int		key_zoom_move(int key, t_info *info)
{	
	double	z;

	z = info->events->zoom;
	if (key == 13)
		info->events->zoom -= (z / 10);
	if (key == 1)
		info->events->zoom += (z / 10);
	if (key == 125)
		info->events->x_offset += .01 * z * 2;
	if (key == 126)
		info->events->x_offset -= .01 * z * 2;
	if (key == 124)
		info->events->x_offset += .01 * z * 2;
	if (key == 123)
		info->events->x_offset -= .01 * z * 2;
	return(0);
}
int		key_iteration(int key, t_info *info)
{
	if (info->check_m)
	{
		if (key == 24)
			info->mandel->p_iterate += 20;
		if (key == 27 && info->mandel->p_iterate >= 20) // maybe no =
			info->mandel->p_iterate -= 20;
	}
	else if (info->check_j)
	{
		if (key == 24)
			info->julia->p_iterate += 20;
		if (key == 27 && info->julia->p_iterate >= 20) // maybe no =
			info->julia->p_iterate -= 20;
	}
	else if (info->check_b)
	{
		if (key == 24)
			info->burns->p_iterate += 20;
		if (key == 27 && info->burns->p_iterate >= 20) // maybe no =
			info->burns->p_iterate -= 20;
	}
	return(0);
}
int		key_color(int key, t_info *info)
{
	if (info->check_m)
	{
		if (key == 8 && info->mandel->color <= 99999999)
			info->mandel->color *= 2;
	}
	else if (info->check_j)
	{
		if (key == 8 && info->julia->color <= 99999999)
			info->julia->color *= 2;
	}
	else if (info->check_b)
	{
		if (key == 8 && info->burns->color <= 99999999)
			info->burns->color *= 2;
	}
	return(0);
}

int		motion_management(int x, int y, t_info *info)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (info->check_j)
			motion_j(x,y,info);
		// mlx_clear_window(info->mlx, info->mlx_window);
		// fractal_recheck(info);
		check_fractal(info);
	}
	return (0);
}

int		motion_j(int x, int y, t_info *info)
{
	info->julia->imag_xy = ((double)x / (WIDTH));
	info->julia->imag_yx = ((double)y / (WIDTH));
	if (info->julia->imag_xy > 2)
		info->julia->imag_xy = info->julia->imag_xy - 2;
	if (info->julia->imag_yx > 2)
		info->julia->imag_yx = info->julia->imag_yx - 2;
	return(0);
}

void	control_window(t_info *info)
{
	mlx_string_put(info->mlx, info->mlx_window, 0,
		0, 0x00FF00, "Move [<] [^] [v] [>]");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		20, 0x00FF00, "Zoom [1] IN [2] OUT");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		40, 0x00FF00, "Iterate [+] UP [-] DOWN");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		60, 0x00FF00, "Color [c]"); // only one.
	mlx_string_put(info->mlx, info->mlx_window, 0,
		80, 0x00FF00, "Exit [esc] or *red thingy top left of window*");
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