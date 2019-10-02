#include "../HEADERS/ft_fractol.h"

/*
** Here we check again, a third time to see which argument/fractal was passed
** and which fractal algorithm function to use and from there it will go through
** a series of functions and after print it into a mlx window.
*/

void	check_form(t_info *info)
{
	mlx_clear_window(info->mlx, info->mlx_window);
	if (info->check_m)
	{
		ft_mandelbrot(info);
		mlx_controls(info);
	}
	else if (info->check_j)
    {
		info->julia->imag_xy = -.73;
        info->julia->imag_yx = -.19;
	 	ft_julia(info);
		mlx_controls(info);
    }
    else if (info->check_b)
    {
		info->burns->imag_xy = .0;
        info->burns->imag_yx = .0;
	    ft_burns(info);
		mlx_controls(info);
    }
	else
	{
		ft_putendl("Usage: .. Error");
		exit(1);
	}
}

void	mlx_controls(t_info *info)
{
	cotrol_window(info);
	// mlx_hook(info->mlx_window, 2, 0, key_management, info);
	mlx_hook(info->mlx_window, 4, 0, mouse_management, info);
	// mlx_hook(info->mlx_window, 6, 0, motion_management, info);
	mlx_hook(info->mlx_window, 17, 0, ft_close, info);
}

void	control_window(t_info *info)
{
	mlx_string_put(info->mlx, info->mlx_window, 0,
		0, 0xFFFFFF, "Move (< ^ v >)");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		20, 0xFFFFFF, "Zoom ([1] IN) ([2] OUT");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		40, 0xFFFFFF, "Iterate ([+] UP) ([-] DOWN)");
	mlx_string_put(info->mlx, info->mlx_window, 0,
		60, 0xFFFFFF, "Color (c)"); // only one.
	mlx_string_put(info->mlx, info->mlx_window, 0,
		80, 0xFFFFFF, "Exit (esc) or *red thingy top left of window*");
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