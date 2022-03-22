/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:42:53 by jim               #+#    #+#             */
/*   Updated: 2022/03/22 22:42:45 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol_struct.h"
#include "fractol.h"

int	key_hook(t_mlx mlx, t_img img, int keycode)
{
	(void)mlx;
	(void)img;
	if (keycode == 53)
	{
		printf("You press ESC key. It will be closed.\n");
		// destory(mlx, img);
		exit(0);
	}
	return (0);
}
