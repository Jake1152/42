/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:24:56 by jim               #+#    #+#             */
/*   Updated: 2022/03/23 20:59:03 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "fractol_struct.h"
# include <stddef.h>
/* init */
void	init_value(t_coordinates *coordinates, char **argv);
int		init_graphic(t_mlx *mlx, t_img *img);

/* fractal */
size_t	julia(t_coordinates *coordinates);
size_t	mandelbrot(t_coordinates *coordinates);
void	to_complex_plane_coordinate(t_coordinates *coordinates);

/* draw */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_fractol(t_img *img, t_coordinates *coordinates, \
						char *fractal_type);

/* event */
int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int mousecode, int x, int y, t_coordinates *coordinates);

/* utils */
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atof(const char *str);
int		ft_atoi(const char *str);

/* print */
void	print_right_input_example(void);

/* error handler */
void	print_error(char *error_meessage);
void	destory(t_mlx *mlx);

#endif
