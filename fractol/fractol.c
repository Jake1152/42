/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:52 by jim               #+#    #+#             */
/*   Updated: 2022/03/21 21:10:40 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include <unistd.h>
#include <stdio.h>

size_t	mandelbrot(t_coordinates coordinates)
// size_t	mandelbrot(t_img *img, t_coordinates coordinates)
{
	int		x;
	int		y;
	int		prev_x;
	size_t	iter;

	x = coordinates.x;
	y = coordinates.y;
	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITER)
	{
		prev_x = x;
		x = x * x + y * y + coordinates.a;
		y = 2 * prev_x * y + coordinates.b;
		iter++;
	}
	return (iter);
}

int	main(void)
{
	t_coordinates	coordinates;
	size_t			iter;
	int				i;

	coordinates.x = 0;
	coordinates.y = 0;
	i = 0;
	while (i <= 500)
	{
		coordinates.a = i * 0.01;
		coordinates.b = i * 0.01;
		printf("coordinates.a : %f\n", coordinates.a);
		iter = mandelbrot(coordinates);
		printf("iter : %zu\n", iter);
		i++;
	}
}

size_t	julia(t_coordinates coordinates)
{
	return (0);
}

double	to_complex_plane_coordnate(t_coordinates *coordinates)
{
	coordinates->a;
}

void	draw_fractol(t_img *img, t_coordinates coordinates)
{
	t_coordinates	coordinates;
	size_t			iter;
	int				i;

	coordinates.x = 0;
	coordinates.y = 0;
	while (i <= WIDTH)
	{
		while (j <= HEIGHT)
		{
			iter
			if ( )
				;
			j++;
		}
		i++;
	}
}
