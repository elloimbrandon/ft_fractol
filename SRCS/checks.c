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
		ft_mandelbrot(info);
	else if (info->check_j)
    {
	 	ft_julia(info);
        info->julia->imag_xy = -.73;
        info->julia->imag_yx = -.19;
    }
    else if (info->check_b)
    {
	    ft_burns(info);
        info->burns->imag_xy = .0;
        info->burns->imag_yx = .0;
    }
	else
	{
		ft_putendl("Error");
		exit(1);
	}
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