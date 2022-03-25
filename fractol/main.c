/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:57 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:48:52 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_struct.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_fractol		fractol;
	int				graphic_err_flag;

	if (argc < 5)
	{
		print_right_input_example();
		return (0);
	}
	graphic_err_flag = init_graphic(&fractol);
	if (graphic_err_flag != SUCCESS)
		graphic_error_handle(&fractol, graphic_err_flag);
	init_value(&fractol, argv);
	draw_fractol(&fractol);
	mlx_mouse_hook(fractol.mlx.win_ptr, mouse_hook, &fractol);
	mlx_key_hook(fractol.mlx.win_ptr, key_hook, &fractol.mlx);
	mlx_loop(fractol.mlx.mlx_ptr);
	return (0);
}
