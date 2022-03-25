/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:57:16 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:46:25 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_struct.h"
#include "fractol.h"
#include "mlx.h"
#include <stddef.h>

void	init_value(t_fractol *fractol, char **argv)
{
	fractol->fractal_type = argv[1];
	fractol->max_iter = (size_t)ft_atoi(argv[4]);
	fractol->coordinates.init_re = ft_atof(argv[2]);
	fractol->coordinates.init_im = ft_atof(argv[3]);
	fractol->coordinates.complex_im_len = 2.0;
	fractol->coordinates.complex_re_len = 3.0;
	fractol->magnification = 1.0;
}

int	init_graphic(t_fractol *fractol)
{
	fractol->mlx.mlx_ptr = mlx_init();
	if (fractol->mlx.mlx_ptr == NULL)
		return (MLX_ERROR);
	fractol->mlx.win_ptr = mlx_new_window(fractol->mlx.mlx_ptr, \
							WIDTH, HEIGHT, "my precious");
	if (fractol->mlx.win_ptr == NULL)
		return (WIN_ERROR);
	fractol->mlx.img.img_ptr = mlx_new_image((*fractol).mlx.mlx_ptr, \
								 WIDTH, HEIGHT);
	if (fractol->mlx.img.img_ptr == NULL)
		return (IMG_ERROR);
	fractol->mlx.img.addr = mlx_get_data_addr(fractol->mlx.img.img_ptr, \
								&(fractol->mlx.img.bits_per_pixel), \
								&(fractol->mlx.img.line_length), \
								&(fractol->mlx.img.endian));
	if (fractol->mlx.img.addr == NULL)
		return (IMG_ADDR_ERROR);
	return (SUCCESS);
}
