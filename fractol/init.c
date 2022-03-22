/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:57:16 by jim               #+#    #+#             */
/*   Updated: 2022/03/22 22:28:19 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "mlx.h"

void	init_value(t_coordinates *coordinates, double init_re, double init_im)
{
	coordinates->init_re = init_re;
	coordinates->init_im = init_im;
	coordinates->complex_im_len = 2.0;
	coordinates->complex_re_len = 3.0;
}

int	init_graphic(t_mlx *mlx, t_img *img)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == (void *)0)
		return (0);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (img->img_ptr == (void *)0)
		return (0);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
	if (img->addr == (void *)0)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "my precious");
	if (mlx->win_ptr == (void *)0)
		return (0);
	return (1);
}
