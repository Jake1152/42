/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:57 by jim               #+#    #+#             */
/*   Updated: 2022/03/22 22:36:54 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_struct.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_mlx			mlx;
	t_img			img;
	t_coordinates	coordinates;

	if (argc != 4)
	{
		print_right_input_example();
		return (0);
	}
	if (init_graphic(&mlx, &img) == 0)
	{
		destory(mlx, img);
		return (0);
	}
	init_value(&coordinates, ft_atof(argv[2]), ft_atof(argv[3]));
	draw_fractol(&img, &coordinates, argv[1]);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
