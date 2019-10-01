#include "../HEADERS/ft_fractol.h"

void		m_scale(t_info *info)
{
	info->mandel->imag_x = ((double)(info->mandel->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->x_offset);
	info->mandel->imag_y = ((double)(info->mandel->y - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->y_offset);
	info->mandel->old_x = info->mandel->imag_x;
	info->mandel->old_y = info->mandel->imag_y;
}

void		j_scale(t_info *info)
{
	info->julia->imag_x = ((double)(info->julia->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->x_offset);
	info->julia->imag_y = ((double)(info->julia->y - (WIDTH / 2)) /
		(double)(WIDTH / 4) * info->events->zoom + info->events->y_offset);
	// info->julia->old_x = info->julia->imag_xy;
	// info->julia->old_y = info->julia->imag_yx;
	// info->julia->count = 0;
}

t_man		*square_root_mandel(t_man *mandel)
{
	mandel->temp = (mandel->imag_x * mandel->imag_x) - (mandel->imag_y * mandel->imag_y);
	mandel->real_x = mandel->temp;
	mandel->real_y = 2 * mandel->imag_x * mandel->imag_y;
	mandel->imag_x = mandel->real_x + mandel->old_x;
	mandel->imag_y = mandel->real_y + mandel->old_y;
	mandel->temp = 0;
	return (mandel);
}

t_jul		*square_root_julia(t_jul *julia)
{	
	julia->imag_x = julia->real_x + julia->old_x;
	julia->imag_y = julia->real_y + julia->old_y;
	julia->real_x = (julia->imag_x * julia->imag_x) - (julia->imag_y * julia->imag_y);
	julia->real_y = 2 * julia->imag_x * julia->imag_y;
	return (julia);
}