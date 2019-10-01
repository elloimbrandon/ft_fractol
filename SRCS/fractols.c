#include "../HEADERS/ft_fractol.h"

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

void	ft_julia(t_info *info)
{
	while(info->julia->x != WIDTH)
	{
		info->julia->y = 0;
		while(info->julia->y != HEIGHT)
		{
			j_scale(info);
			info->julia->count = 0;
			while (++info->julia->count != info->julia->p_iterate &&  
				info->julia->imag_x * info->julia->imag_x + info->julia->imag_y * info->julia->imag_y < 4) // 4.0
				square_root_julia(info->julia);
			if (info->julia->p_iterate == info->julia->count)
				all_pixel(info, info->julia->x, info->julia->y, 0);
			else
				all_pixel(info, info->julia->x, info->julia->y, info->julia->count * info->julia->color);
			info->julia->y++;
		}
		info->julia->x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->mlx_image, 0, 0);
}

void	ft_burns(t_info *info)
{
    while(info->burns->x != WIDTH)
	{
		info->burns->y = 0;
		while(info->burns->y != HEIGHT)
		{
			b_scale(info);
			info->burns->count = 0;
			while (info->burns->count != info->burns->p_iterate &&  
				info->burns->real_x * info->burns->real_x + info->burns->real_y * info->burns->real_y < 4) // 4.0
				square_root_burns(info->burns);
			if (info->burns->p_iterate == info->burns->count)
				all_pixel(info, info->burns->x, info->burns->y, 0);
			else
				all_pixel(info, info->burns->x, info->burns->y, info->burns->count * info->burns->color);
			info->burns->y++;
		}
		info->burns->x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->mlx_image, 0, 0);
}