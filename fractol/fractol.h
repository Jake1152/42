/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:24:56 by jim               #+#    #+#             */
/*   Updated: 2022/03/25 15:44:53 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "fractol_struct.h"

void	init_value(t_fractol *coordinates, char **argv);
int		init_graphic(t_fractol *fractol);

size_t	julia(t_fractol *fractol);
size_t	mandelbrot(t_fractol *fractol);
void	to_complex_plane_coordinate(t_fractol *fractol);

void	draw_fractol(t_fractol *fractol);
void	calculate_fractal(t_fractol *fractol, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int mousecode, int x, int y, t_fractol *fractol);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atof(const char *str);
int		ft_atoi(const char *str);

void	print_right_input_example(void);

void	graphic_error_handle(t_fractol *fractol, int graphic_err);
void	print_error(char *error_meessage);
void	destory(t_mlx *mlx);

#endif
