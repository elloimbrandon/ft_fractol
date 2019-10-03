#include "../HEADERS/ft_fractol.h"

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
			// check_fractal(info); 
			mlx_controls(info);
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
	info->burn_s = (t_bur*)ft_memalloc(sizeof(t_bur));
	info->events = (t_evn*)ft_memalloc(sizeof(t_evn));
	info->arg = argc;
	info->mandel->x = 0;
	info->mandel->y = 0;
	info->mandel->imag_x = 0;
	info->mandel->imag_y = 0;
	info->mandel->temp = 0;
	info->mandel->color = 2051;
	info->mandel->count = 1;
	info->mandel->iterate_max = 50;
	info->mandel->real_x = 0;
	info->mandel->real_y = 0;
	info->julia->x = 0;
	info->julia->y = 0;
	info->julia->imag_x = 0;
	info->julia->imag_y = 0;
	info->julia->imag_xy = -.73;
    info->julia->imag_yx = -.19;
	info->julia->color = 2051;
	info->julia->count = 1;
	info->julia->iterate_max = 50;
	info->julia->real_x = 0;
	info->julia->real_y = 0;
	info->burn_s->x = 0;
	info->burn_s->y = 0;
	info->burn_s->imag_x = 0;
	info->burn_s->imag_y = 0;
	info->burn_s->imag_xy = .0;
    info->burn_s->imag_yx = .0;
	info->burn_s->color = 2051;
	info->burn_s->count = 1;
	info->burn_s->iterate_max = 50;
	info->burn_s->real_x = 0;
	info->burn_s->real_y = 0;
	info->check_m = 0;
	info->check_j = 0;
	info->check_b = 0;
	info->events->zoom = 1;
	info->events->x_offset = 0;
	info->events->y_offset = 0;
}
