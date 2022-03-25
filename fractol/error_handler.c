/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:36:00 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:55:09 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	destory(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, (mlx->img).img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}

void	print_error(char *error_meessage)
{
	printf("%s\n", error_meessage);
	exit(1);
}

void	graphic_error_handle(t_fractol *fractol, int graphic_err)
{
	if (graphic_err == MLX_ERROR)
		print_error("mlx allocation error.");
	if (graphic_err == WIN_ERROR)
		print_error("mlx window allocation error.");
	else if (graphic_err == IMG_ERROR)
	{
		mlx_destroy_window(fractol->mlx.mlx_ptr, fractol->mlx.win_ptr);
		print_error("mlx img allocation error.");
	}
	else if (graphic_err == IMG_ADDR_ERROR)
	{
		destory(&(fractol->mlx));
		print_error("img address assign error.");
	}
}
