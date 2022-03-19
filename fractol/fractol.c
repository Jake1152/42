/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:52 by jim               #+#    #+#             */
/*   Updated: 2022/03/19 20:09:58 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include <unistd.h>

void	draw_fratol(t_img *img, double init_a, double init_b)
{
	size_t	i;
	size_t	j;
	size_t	iter;

	i = 0;
	j = 0;
	while (i <= WIDTH)
	{
		while (j <= HEIGHT)
		{
			if (iter == )
				;
			j++;
		}
		i++;
	}
}

size_t	mandelbrot(t_img *img, double a, double b)
{
	int	x;
	int	y;
	int	prev_x;

}

size_t	julia(t_img *img, double a, double b)
{
	;
}
