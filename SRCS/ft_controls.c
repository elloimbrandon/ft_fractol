/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:22:34 by brfeltz           #+#    #+#             */
/*   Updated: 2019/10/03 17:11:03 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fractol.h"

void	handle_mlx(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_window = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fractol");
	info->mlx_image = mlx_new_image(info->mlx, WIDTH, HEIGHT);
}

void	control_window(t_info *info)
{
	if (info->max_trigger)
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

int		mouse_management(int key, int x, int y, t_info *info)
{
	if (key == 5)
		info->events->zoom -= (info->events->zoom / 10);
	if (key == 4)
		info->events->zoom += (info->events->zoom / 10);
	check_fractal(info);
	return (0);
}

int		motion_management(int x, int y, t_info *info)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (info->check_j && info->julia_tick)
			info = motion_j(x, y, info);
		check_fractal(info);
	}
	return (0);
}

t_info	*motion_j(int x, int y, t_info *info)
{
	info->julia->imag_xy = ((double)x / (WIDTH));
	info->julia->imag_yx = ((double)y / (WIDTH));
	if (info->julia->imag_xy > 2)
		info->julia->imag_xy = info->julia->imag_xy - 2;
	if (info->julia->imag_yx > 2)
		info->julia->imag_yx = info->julia->imag_yx - 2;
	return (info);
}
