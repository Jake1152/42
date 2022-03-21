/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:57 by jim               #+#    #+#             */
/*   Updated: 2022/03/21 21:11:29 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_struct.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img-> line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	t_img	img;
	void	*win_ptr;
	size_t	fractol_index;

	/* mlx, window, img init */
	// init_graphic(), init_value() 필요
	mlx_ptr = mlx_init();
	img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "my precious");
	/*  Fractol 그릴 파트, 어떤 argument인지에 따라서 분리한다. */
	draw_fractol();

	// draw_julia();
	// for (int i = 0; i < 50; i++)
		// my_mlx_pixel_put(&img, i, i, 0x0000FF00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 42, 42);
	mlx_loop(mlx_ptr);
	return (0);
}
