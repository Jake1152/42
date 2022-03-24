/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:36:00 by jim               #+#    #+#             */
/*   Updated: 2022/03/23 17:46:51 by jim              ###   ########seoul.kr  */
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
