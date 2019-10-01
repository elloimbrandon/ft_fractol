#include "../HEADERS/ft_fractol.h"
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
			//mlx_controls(info); // could move to check form
			mlx_loop(info->mlx);
		}
	}
	else
		error_management(argc, info);
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
	info->julia->color = 25;
	info->julia->count = 0;
	info->julia->p_iterate = 50;
	info->julia->real_x = 0;
	info->julia->real_y = 0;
	info->burns->x = 0;
	info->burns->y = 0;
	info->burns->imag_x = 0;
	info->burns->imag_y = 0;
	info->burns->color = 25;
	info->burns->count = 0;
	info->burns->p_iterate = 50;
	info->burns->real_x = 0;
	info->burns->real_y = 0;
	info->check_m = 0;
	info->check_j = 0;
	info->check_b = 0;
	info->events->zoom = 1;
	info->events->x_offset = 0;
	info->events->y_offset = 0;
}
