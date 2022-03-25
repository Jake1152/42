/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:57:05 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:21:04 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "fractol.h"
#include "mlx.h"

void	calculate_fractal(t_fractol *fractol, int x, int y)
{
	size_t	iter;
	int		color;

	iter = fractol->max_iter;
	fractol->coordinates.c_re = x;
	fractol->coordinates.c_im = y;
	if (ft_strncmp(fractol->fractal_type, "mandelbrot", \
		ft_strlen(fractol->fractal_type)) == 0)
		iter = mandelbrot(fractol);
	else if (ft_strncmp(fractol->fractal_type, "julia", \
		ft_strlen(fractol->fractal_type)) == 0)
		iter = julia(fractol);
	else
		print_error("not a valid fractal type.\n");
	if (iter < fractol->max_iter)
		color = iter << 21 | iter << 12 | iter << 4;
	else
		color = 0x0;
	my_mlx_pixel_put(&(fractol->mlx.img), x, y, color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img-> line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractol(t_fractol *fractol)
{
	int		width_coordinate;
	int		height_coordinate;

	width_coordinate = 0;
	while (width_coordinate <= WIDTH)
	{
		height_coordinate = 0;
		while (height_coordinate <= HEIGHT)
		{
			calculate_fractal(fractol, width_coordinate, height_coordinate);
			height_coordinate++;
		}
		width_coordinate++;
	}
	mlx_put_image_to_window(fractol->mlx.mlx_ptr, fractol->mlx.win_ptr, \
							fractol->mlx.img.img_ptr, 0, 0);
}
