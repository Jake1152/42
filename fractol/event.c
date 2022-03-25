/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:42:53 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:28:49 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol_struct.h"
#include "fractol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		destory(mlx);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (mousecode == UP_WHEEL)
		fractol->magnification *= 0.2;
	else if (mousecode == DOWN_WHEEL)
		fractol->magnification *= 2.0;
	draw_fractol(fractol);
	return (0);
}
