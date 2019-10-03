/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:19:27 by brfeltz           #+#    #+#             */
/*   Updated: 2019/10/02 21:31:00 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

/*
** Macros
*/

# define HEIGHT 800
# define WIDTH 800

/*
** Structs
*/

typedef struct		t_julia
{
	double			x;
	double			y;
	double			old_x;
	double			old_y;
	double			imag_x;
	double			imag_y;
	double			imag_xy;
	double			imag_yx;
	int				color;
	int				count;
	int				iterate_max;
	double			real_x;
	double			real_y;
}					t_jul;

typedef struct		s_burns
{
	double			x;
	double			y;
	double			old_x;
	double			old_y;
	double			imag_x;
	double			imag_y;
	double			imag_xy;
	double			imag_yx;
	int				color;
	int				count;
	int				iterate_max;
	double			real_x;
	double			real_y;
}					t_bur;

typedef struct		s_mandel
{
	double			x;
	double			y;
	double			old_x;
	double			old_y;
	double			imag_x;
	double			imag_y;
	double			temp;
	int				color;
	int				count;
	int				iterate_max;
	double			real_x;
	double			real_y;
}					t_man;

typedef struct		s_events
{
	double			zoom;
	double 			x_offset;
	double			y_offset;

}					t_evn;

typedef	struct		s_info
{
	t_jul			*julia;
	t_man 			*mandel;
	t_bur			*burn_s;
	t_evn 			*events;
	void			*mlx;
	void			*mlx_image;
	void			*mlx_window;
	void			*mlx_ptr;
	int				check_m;
	int				check_j;
	int				check_b;
	int				bits_per_pix;
	int				size_l;
	int				endian;
	int				iterate_max;
	int				arg;
	int				max_trigger;
}					t_info;

/*
** Functions
*/

void		init_struct(t_info *info, int argc);
void		arg_check(char	*str, t_info *info);
int			check_fractal(t_info *info);
// int			fractal_recheck(t_info *info);
int			handle_mlx(t_info *info);
int			mlx_controls(t_info *info);
void		control_window(t_info *info);
void		error_management(int arg, t_info *info);
void		ft_mandelbrot(t_info *info);
void		ft_julia(t_info *info);
void		ft_burn_s(t_info *info);
void		m_scale(t_info *info);
void		j_scale(t_info *info);
void        b_scale(t_info *info);
void		all_pixel(t_info *info, int x, int y, int pix_color);
t_man		square_root_mandel(t_man *mandel);
t_jul		square_root_julia(t_jul *julia);
t_bur       square_root_burn_s(t_bur *burns);
int			key_management(int key, t_info *info);
int			mouse_management(int key, int x, int y, t_info *info);
int			motion_management(int x, int y, t_info *info);
int			motion_j(int x, int y, t_info *info);
t_info		*key_iteration(int key, t_info *info);
t_info		*key_color(int key, t_info *info);
t_info		*key_zoom_move(int key, t_info *info);
int			ft_close(void *ptr);

#endif
