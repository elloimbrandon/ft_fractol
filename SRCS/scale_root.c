/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:23:27 by brfeltz           #+#    #+#             */
/*   Updated: 2019/10/03 17:14:38 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fractol.h"

void	m_scale(t_info *info)
{
	info->mandel->imag_x = ((double)(info->mandel->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->x_offset);
	info->mandel->imag_y = ((double)(info->mandel->y - (HEIGHT / 2)) /
		(double)(HEIGHT / 4) * info->events->zoom + info->events->y_offset);
	info->mandel->old_x = info->mandel->imag_x;
	info->mandel->old_y = info->mandel->imag_y;
}

void	j_scale(t_info *info)
{
	info->julia->imag_x = ((double)(info->julia->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->x_offset);
	info->julia->imag_y = ((double)(info->julia->y - (HEIGHT / 2)) /
		(double)(HEIGHT / 4) * info->events->zoom + info->events->y_offset);
	info->julia->old_x = info->julia->imag_xy;
	info->julia->old_y = info->julia->imag_yx;
}

void	b_scale(t_info *info)
{
	info->burn_s->imag_x = ((double)(info->burn_s->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->x_offset);
	info->burn_s->imag_y = ((double)(info->burn_s->y - (HEIGHT / 2)) /
		(double)(HEIGHT / 4) * info->events->zoom + info->events->y_offset);
	info->burn_s->real_x = info->burn_s->imag_xy;
	info->burn_s->real_y = info->burn_s->imag_yx;
}

void	square_root_mandel(t_man *mandel)
{
	mandel->real_x = (mandel->imag_x * mandel->imag_x)
		- (mandel->imag_y * mandel->imag_y);
	mandel->real_y = 2 * mandel->imag_x * mandel->imag_y;
	mandel->imag_x = mandel->real_x + mandel->old_x;
	mandel->imag_y = mandel->real_y + mandel->old_y;
}

void	square_root_julia(t_jul *julia)
{
	julia->real_x = (julia->imag_x * julia->imag_x)
		- (julia->imag_y * julia->imag_y);
	julia->real_y = 2 * julia->imag_x * julia->imag_y;
	julia->imag_x = julia->real_x + julia->old_x;
	julia->imag_y = julia->real_y + julia->old_y;
}
