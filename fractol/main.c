/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:45:16 by jim               #+#    #+#             */
/*   Updated: 2022/03/16 19:28:11 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_struct.h"

void	window_init(void	*mlx)
{
	mlx = mlx_init();
	if (mlx == NULL)
		error_handler("mlx_init error.\n");
}

void	handle_input_value(int argc, char *argv[], t_mlx mlx)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
		mandelbrot(&mlx);
	else if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
		julia(&mlx);
	else if (ft_strncmp(argv[1], "triangle", ft_strlen("triangle")) == 0)
		triangle(&mlx);
	else
		error_handler("please input correct fractal type.\n");
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
		error_handler("please input fractal type.\n");
	if (window_init(&mlx) == NULL)
		error_handler("Window does not be launched.\n");
	handle_input_value(argc, argv, &mlx.img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	// mlx_hook(mlx.win, event_key_press, 0, key_press, 0);
	// mlx_hook(mlx.win, event_key_press, 0, key_press, 0);
	// mlx_loop(mlx.mlx_ptr);
	// key_press(keycode);
	return (0);
}
