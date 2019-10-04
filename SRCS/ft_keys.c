/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:23:07 by brfeltz           #+#    #+#             */
/*   Updated: 2019/10/03 17:11:09 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fractol.h"

t_info	*key_color_up(int key, t_info *info)
{
	if (info->check_m && key == 8)
	{
		if (info->mandel->color < 90000000)
			info->mandel->color *= 2;
	}
	if (info->check_j && key == 8)
	{
		if (info->julia->color < 90000000)
			info->julia->color *= 2;
	}
	if (info->check_b && key == 8)
	{
		if (info->burn_s->color < 90000000)
			info->burn_s->color *= 2;
	}
	return (info);
}

t_info	*key_color_down(int key, t_info *info)
{
	if (info->check_m && key == 9)
	{
		if (info->mandel->color > 2051)
			info->mandel->color /= 2;
	}
	if (info->check_j && key == 9)
	{
		if (info->julia->color > 2051)
			info->julia->color /= 2;
	}
	if (info->check_b && key == 9)
	{
		if (info->burn_s->color > 2051)
			info->burn_s->color /= 2;
	}
	return (info);
}

t_info	*key_iteration(int key, t_info *info)
{
	if (info->check_m)
	{
		if (key == 24 && info->mandel->iterate_max < 81)
			info->mandel->iterate_max += 20;
		if (key == 27 && info->mandel->iterate_max > 20)
			info->mandel->iterate_max -= 20;
		else if (key == 24 && info->mandel->iterate_max > 80)
			info->max_trigger = 1;
	}
	else if (info->check_j)
	{
		if (key == 24 && info->julia->iterate_max < 81)
			info->julia->iterate_max += 20;
		if (key == 27 && info->julia->iterate_max > 20)
			info->julia->iterate_max -= 20;
		else if (key == 24 && info->julia->iterate_max > 80)
			info->max_trigger = 1;
	}
	return (info);
}

t_info	*key_iteration2(int key, t_info *info)
{
	if (info->check_b)
	{
		if (key == 24 && info->burn_s->iterate_max < 81)
			info->burn_s->iterate_max += 20;
		if (key == 27 && info->burn_s->iterate_max > 20)
			info->burn_s->iterate_max -= 20;
		else if (key == 24 && info->burn_s->iterate_max > 80)
			info->max_trigger = 1;
	}
	return (info);
}

t_info	*key_zoom_move(int key, t_info *info)
{
	double	z;

	z = info->events->zoom;
	if (key == 19)
		info->events->zoom -= (z / 10);
	else if (key == 18)
		info->events->zoom += (z / 10);
	else if (key == 125)
		info->events->y_offset -= .01 * z * 2;
	else if (key == 126)
		info->events->y_offset += .01 * z * 2;
	else if (key == 124)
		info->events->x_offset -= .01 * z * 2;
	else if (key == 123)
		info->events->x_offset += .01 * z * 2;
	return (info);
}
