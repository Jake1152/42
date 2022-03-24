/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:52 by jim               #+#    #+#             */
/*   Updated: 2022/03/23 20:55:06 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "fractol.h"
#include "mlx.h"
#include <stddef.h>

//debug
#include <stdio.h>

void	to_complex_plane_coordinate(t_coordinates *coordinates)
{
	double	complex_re;
	double	complex_im;

	complex_re = coordinates->c_re;
	complex_im = coordinates->c_im;
	complex_re = (complex_re - WIDTH / 2) / HEIGHT * coordinates->magnification \
					* 4 ;
	complex_im = ((HEIGHT / 2) - complex_im) / HEIGHT \
					* coordinates->magnification * 4;
	coordinates->c_re = complex_re;
	coordinates->c_im = complex_im;
	// printf("coordinates->magnification : %f\n", coordinates->magnification);
}
// 화면비율과 프렉탈의 찌그러짐에는 관련이 없어야한다.

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
	while (x * x + y * y < 4 && iter < coordinates->max_iter)
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
	// coordinates->init_re = 0.285;//-0.7269;//0.285;
	// coordinates->init_im = 0.0;//0.1889;//0.01;
	x = coordinates->c_re;
	y = coordinates->c_im;
	iter = 1;
	// printf("coordinates->init_re : %f\n", coordinates->init_re);
	// printf("coordinates->init_im : %f\n", coordinates->init_im);
	while (x * x + y * y < 4 && iter < coordinates->max_iter)
	{
		prev_x = x;
		x = x * x - y * y + coordinates->init_re;
		y = 2 * prev_x * y + coordinates->init_im;
		iter++;
	}
	return (iter);
}
