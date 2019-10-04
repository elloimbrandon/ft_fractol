/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_pix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:59:50 by brfeltz           #+#    #+#             */
/*   Updated: 2019/10/03 16:25:29 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fractol.h"

void	arg_check(char *str, t_info *info)
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

void	all_pixel(t_info *info, int x, int y, int pix_color)
{
	void	*ptr;
	int		c_val;

	if (x < WIDTH && y < HEIGHT)
	{
		ptr = mlx_get_data_addr(info->mlx_image,
			&(info->bits_per_pix), &(info->size_l), &(info->endian));
		c_val = mlx_get_color_value(info->mlx, pix_color);
		ft_memcpy(ptr + 4 * WIDTH * y + x * 4, &c_val, sizeof(int));
	}
}

/*
** Stored burning ship sqaure root funtion here for norm
*/

void	square_root_burn_s(t_bur *burn_s)
{
	burn_s->old_x = burn_s->real_x;
	burn_s->real_x = burn_s->real_x * burn_s->real_x
		- burn_s->real_y * burn_s->real_y + burn_s->imag_x;
	burn_s->real_y = 2 * fabs(burn_s->real_y * burn_s->old_x) + burn_s->imag_y;
	burn_s->count += 1;
}
