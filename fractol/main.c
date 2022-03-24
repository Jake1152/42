/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:57 by jim               #+#    #+#             */
/*   Updated: 2022/03/23 20:58:32 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_struct.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_mlx			mlx;
	t_coordinates	coordinates;

	if (argc < 5)
	{
		print_right_input_example();
		return (0);
	}
	if (init_graphic(&mlx, &mlx.img) == 0)
	{
		destory(&mlx);
		return (0);
	}
	coordinates.fractal_type = argv[1];
	coordinates.img = mlx.img;
	init_value(&coordinates, argv);
	// loop_hook(void *param);
	draw_fractol(&mlx.img, &coordinates, argv[1]);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &coordinates);

	mlx_loop(mlx.mlx_ptr);
	return (0);
}
