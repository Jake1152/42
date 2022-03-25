/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:43:22 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:55:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

# include <stddef.h>
# define WIDTH		900
# define HEIGHT		600

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

typedef struct s_coordinates
{
	double	init_re;
	double	init_im;
	double	c_re;
	double	c_im;
	int		complex_re_len;
	int		complex_im_len;
}				t_coordinates;

typedef struct s_fractol
{
	t_mlx			mlx;
	size_t			max_iter;
	double			magnification;
	char			*fractal_type;
	t_coordinates	coordinates;
}				t_fractol;

typedef enum e_m_code
{
	ON_LEFT = 1,
	ON_RIGHT = 2,
	UP_WHEEL = 4,
	DOWN_WHEEL = 5,
}			t_m_code;

typedef enum e_graphic_err
{
	SUCCESS = 0,
	MLX_ERROR = 1,
	WIN_ERROR = 2,
	IMG_ERROR = 3,
	IMG_ADDR_ERROR = 4,
}			t_e_error_flag;
#endif
