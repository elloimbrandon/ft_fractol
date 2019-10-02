#include "../HEADERS/ft_fractol.h"

int		handle_mlx(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_window = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fractol");
	info->mlx_image = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->mlx_ptr = mlx_get_data_addr(info->mlx_image, &(info->bits_per_pix),
	&(info->size_l), &(info->endian));
	return(0);
}

void	all_pixel(t_info *info, int x, int y, int pix_color)
{
	void	*ptr;
	int		c_val; // color code

	if (x < WIDTH && y < HEIGHT)
	{
		ptr = mlx_get_data_addr(info->mlx_image, &(info->bits_per_pix), &(info->size_l), &(info->endian));
		c_val = mlx_get_color_value(info->mlx, pix_color);
		ft_memcpy(ptr + 4 * WIDTH * y + x * 4, &c_val, sizeof(int));
	}
}

int		mouse_management(int key, int x, int y, t_info *info)
{
	if (key == 5)
		info->events->zoom -= (info->events->zoom / 10);
	if (key == 4)
		info->events->zoom += (info->events->zoom / 10);
	// mlx_clear_window(info->mlx, info->mlx_window);
	// fractal_recheck(info);
	check_fractal(info);
	return (0);
}

int		ft_close(void *ptr)
{
	(void)ptr;
	exit(0);
}