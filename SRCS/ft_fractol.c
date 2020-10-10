/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:22:54 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/04 13:26:22 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			mlx_controls(info);
			mlx_loop(info->mlx);
		}
	}
	else
		error_management(argc, info);
}

void	mlx_controls(t_info *info)
{
	check_fractal(info);
	mlx_hook(info->mlx_window, 2, 0, key_management, info);
	mlx_hook(info->mlx_window, 4, 0, mouse_management, info);
	mlx_hook(info->mlx_window, 6, 0, motion_management, info);
	mlx_hook(info->mlx_window, 17, 0, ft_close, info);
}

void	check_fractal(t_info *info)
{
	//mlx_clear_window(info->mlx, info->mlx_window); // dont need, runs faster
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
}

int		key_management(int key, t_info *info)
{
	if (key == 53)
		exit(1);
	if (key == 38)
		info->julia_tick = 1;
	info = key_color_up(key, info);
	info = key_color_down(key, info);
	info = key_iteration(key, info);
	info = key_iteration2(key, info);
	info = key_zoom_move(key, info);
	check_fractal(info);
	return (0);
}

int		ft_close(void *ptr)
{
	(void)ptr;
	exit(0);
}
