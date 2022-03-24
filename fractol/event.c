/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:42:53 by jim               #+#    #+#             */
/*   Updated: 2022/03/23 20:58:52 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol_struct.h"
#include "fractol.h"

typedef enum e_m_code
{
	ON_LEFT = 1,
	ON_RIGHT = 2,
	UP_WHEEL = 4,
	DOWN_WHEEL = 5,
}			t_m_code;

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		printf("You press ESC key. It will be closed.\n");
		destory(mlx);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_coordinates *coordinates)
{
	(void)x;
	(void)y;
	if (mousecode == ON_LEFT)
		printf("Hellow from 1 click!\n");
	else if (mousecode == UP_WHEEL)
		coordinates->magnification *= 0.1;
	else if (mousecode == DOWN_WHEEL)
		coordinates->magnification *= 10.0;
	draw_fractol(&coordinates->img, coordinates, coordinates->fractal_type);
	return (0);
}
