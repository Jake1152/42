/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:57:05 by jim               #+#    #+#             */
/*   Updated: 2022/03/23 20:58:57 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img-> line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractol(t_img *img, t_coordinates *coordinates, char *fractal_type)
{
	size_t	iter;
	int		width_coordinate;
	int		height_coordinate;

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
			if (iter < coordinates->max_iter)
				my_mlx_pixel_put(img, width_coordinate, \
				height_coordinate, iter << 21 | iter << 12 | iter << 4);
			// printf("iter : %zu\n", iter);
			height_coordinate++;
		}
		width_coordinate++;
	}
}
