/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:52 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:17:22 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include <stddef.h>

void	to_complex_plane_coordinate(t_fractol *fractol)
{
	double	complex_re;
	double	complex_im;

	complex_re = fractol->coordinates.c_re;
	complex_im = fractol->coordinates.c_im;
	complex_re = (complex_re - WIDTH / 2) / HEIGHT * fractol->magnification \
					* 4 ;
	complex_im = ((HEIGHT / 2) - complex_im) / HEIGHT \
					* fractol->magnification * 4;
	fractol->coordinates.c_re = complex_re;
	fractol->coordinates.c_im = complex_im;
}

size_t	mandelbrot(t_fractol *fractol)
{
	double	x;
	double	y;
	double	prev_x;
	size_t	iter;

	to_complex_plane_coordinate(fractol);
	x = fractol->coordinates.init_re;
	y = fractol->coordinates.init_im;
	iter = 1;
	while (x * x + y * y < 4 && iter < fractol->max_iter)
	{
		prev_x = x;
		x = x * x - y * y + fractol->coordinates.c_re - 0.5;
		y = 2 * prev_x * y + fractol->coordinates.c_im;
		iter++;
	}
	return (iter);
}

size_t	julia(t_fractol *fractol)
{
	double	x;
	double	y;
	double	prev_x;
	size_t	iter;

	to_complex_plane_coordinate(fractol);
	x = fractol->coordinates.c_re;
	y = fractol->coordinates.c_im;
	iter = 1;
	while (x * x + y * y < 4 && iter < fractol->max_iter)
	{
		prev_x = x;
		x = x * x - y * y + fractol->coordinates.init_re;
		y = 2 * prev_x * y + fractol->coordinates.init_im;
		iter++;
	}
	return (iter);
}
