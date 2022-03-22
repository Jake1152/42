/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:52 by jim               #+#    #+#             */
/*   Updated: 2022/03/22 22:47:12 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "fractol.h"
#include "mlx.h"
#include <unistd.h>

void	to_complex_plane_coordinate(t_coordinates *coordinates)
{
	double	complex_re;
	double	complex_im;

	complex_re = coordinates->c_re;
	complex_im = coordinates->c_im;
	// complex_re = (complex_re - WIDTH / 2) \
	// 				/ WIDTH * coordinates->complex_re_len;
	// complex_im = ((HEIGHT / 2) - complex_im) \
	// 				/ HEIGHT * coordinates->complex_im_len;
	// complex plane size는 나중에 준다.
	complex_re = (complex_re / (WIDTH / coordinates->complex_re_len)) - 1.5;
	complex_im = (complex_im / (HEIGHT / coordinates->complex_im_len)) - 1.0;
	coordinates->c_re = complex_re;
	coordinates->c_im = complex_im;
}

size_t	mandelbrot(t_coordinates *coordinates)
{
	double	x;
	double	y;
	double	prev_x;
	size_t	iter;

	to_complex_plane_coordinate(coordinates);
	x = coordinates->init_re;
	y = coordinates->init_im;
	iter = 1;
	while (x * x + y * y < 4 && iter < MAX_ITER)
	{
		prev_x = x;
		x = x * x - y * y + coordinates->c_re - 0.5;
		y = 2 * prev_x * y + coordinates->c_im;
		iter++;
	}
	return (iter);
}

size_t	julia(t_coordinates *coordinates)
{
	double	x;
	double	y;
	double	prev_x;
	size_t	iter;

	to_complex_plane_coordinate(coordinates);
	coordinates->init_re = 0.285;//-0.7269;//0.285;
	coordinates->init_im = 0.01;//0.1889;//0.01;
	x = coordinates->c_re;
	y = coordinates->c_im;
	iter = 1;
	while (x * x + y * y < 4 && iter < MAX_ITER)
	{
		prev_x = x;
		x = x * x - y * y + coordinates->init_re;
		y = 2 * prev_x * y + coordinates->init_im;
		iter++;
	}
	return (iter);
}
