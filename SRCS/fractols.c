#include "../HEADERS/ft_fractol.h"

void	ft_mandelbrot(t_info *info)
{	
	info->mandel->x = 0;
	while(info->mandel->x != WIDTH)
	{
		info->mandel->y = 0;
		while(info->mandel->y != HEIGHT)
		{
			m_scale(info);
			info->mandel->count = 0;
			while (++info->mandel->count != info->mandel->iterate_max &&  
			(sqrt((info->mandel->imag_x * info->mandel->imag_x) + (info->mandel->imag_y * info->mandel->imag_y)) < 3.0)) /// no decimal
				square_root_mandel(info->mandel);
			if (info->mandel->iterate_max == info->mandel->count)
				all_pixel(info, info->mandel->x, info->mandel->y, 0);
			else
				all_pixel(info, info->mandel->x, info->mandel->y, info->mandel->count * info->mandel->color);
			info->mandel->y++;
		}
		info->mandel->x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->mlx_image, 0, 0);
}

void	ft_julia(t_info *info)
{
	info->julia->x = 0;
	while(info->julia->x != WIDTH)
	{
		info->julia->y = 0;
		while(info->julia->y != HEIGHT)
		{
			j_scale(info);
			info->julia->count = 0;
			while (++info->julia->count != info->julia->iterate_max &&  
				info->julia->imag_x * info->julia->imag_x + info->julia->imag_y * info->julia->imag_y < 4.0)
				square_root_julia(info->julia);
			if (info->julia->iterate_max == info->julia->count)
				all_pixel(info, info->julia->x, info->julia->y, 0);
			else
				all_pixel(info, info->julia->x, info->julia->y, info->julia->count * info->julia->color);
			info->julia->y++;
		}
		info->julia->x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->mlx_image, 0, 0);
}

void	ft_burn_s(t_info *info)
{
	info->burn_s->x = 0;
    while(info->burn_s->x != WIDTH)
	{
		info->burn_s->y = 0;
		while(info->burn_s->y != HEIGHT)
		{
			b_scale(info);
			info->burn_s->count = 0;
			while (info->burn_s->count != info->burn_s->iterate_max &&  
				info->burn_s->real_x * info->burn_s->real_x + info->burn_s->real_y * info->burn_s->real_y < 4.0)
				square_root_burn_s(info->burn_s);
			if (info->burn_s->iterate_max == info->burn_s->count)
				all_pixel(info, info->burn_s->x, info->burn_s->y, 0);
			else
				all_pixel(info, info->burn_s->x, info->burn_s->y, info->burn_s->count * info->burn_s->color);
			info->burn_s->y++;
		}
		info->burn_s->x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->mlx_image, 0, 0);
}