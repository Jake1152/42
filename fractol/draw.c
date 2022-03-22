/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:57:05 by jim               #+#    #+#             */
/*   Updated: 2022/03/22 22:40:49 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img-> line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractol(t_img *img, t_coordinates *coordinates, char *fractal_type)
{
	int	iter;
	int	width_coordinate;
	int	height_coordinate;

	width_coordinate = 0;
	while (width_coordinate <= WIDTH)
	{
		height_coordinate = 0;
		while (height_coordinate <= HEIGHT)
		{
			coordinates->c_re = width_coordinate;
			coordinates->c_im = height_coordinate;
			if (ft_strncmp(fractal_type, "mandelbrot", \
				ft_strlen(fractal_type)) == 0)
				iter = mandelbrot(coordinates);
			else if (ft_strncmp(fractal_type, "julia", \
				ft_strlen(fractal_type)) == 0)
				iter = julia(coordinates);
			else
				print_error("not a valid fractal type.\n");
			if (iter >= MAX_ITER)
				my_mlx_pixel_put(img, width_coordinate, \
				height_coordinate, 0x0000FF00);
			height_coordinate++;
		}
		width_coordinate++;
	}
}
