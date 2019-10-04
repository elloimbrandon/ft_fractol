/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:23:18 by brfeltz           #+#    #+#             */
/*   Updated: 2019/10/03 17:12:10 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fractol.h"

void	init_struct(t_info *info, int argc)
{
	info->mandel = (t_man*)ft_memalloc(sizeof(t_man));
	info->julia = (t_jul*)ft_memalloc(sizeof(t_jul));
	info->burn_s = (t_bur*)ft_memalloc(sizeof(t_bur));
	info->events = (t_evn*)ft_memalloc(sizeof(t_evn));
	info->julia_tick = 0;
	info->max_trigger = 0;
	info->arg = argc;
	info->check_m = 0;
	info->check_j = 0;
	info->check_b = 0;
	info->events->zoom = 1;
	info->mandel->color = 2050;
	info->mandel->count = 1;
	info->mandel->iterate_max = 40;
	info->julia->imag_xy = -.73;
	info->julia->imag_yx = -.19;
	info->julia->color = 2050;
	info->julia->count = 1;
	info->julia->iterate_max = 40;
	info->burn_s->imag_xy = .0;
	info->burn_s->imag_yx = .0;
	info->burn_s->color = 2050;
	info->burn_s->count = 1;
	info->burn_s->iterate_max = 40;
}
