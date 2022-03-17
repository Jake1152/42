#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define		MAX_ITER				30
#define		X_EVENT_KEY_PRESS		2
#define		X_EVENT_KEY_EXIT		17
#define		X_EVENT_MOUSE_PRESS		4
#define		X_EVENT_MOUSE_MOTION	6
#define		WIN_WIDTH				800
#define		WIN_HEIGHT				800
#define		KEY_ESC					53

typedef	struct	s_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef	struct	s_mlx{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

size_t	mandelbrot(double a, double b)
{
	double x;
	double y;
	double x_prev;
	size_t	iter;

	a = a / WIN_WIDTH * 4 - 2;
	b = b / WIN_HEIGHT * -4 + 2;
	iter = 1;
	x = 0;
	y = 0;
	while (iter < MAX_ITER)
	{
		x_prev = x;
		x = x * x - y * y + a;
		y = 2 * x_prev * y + b;
		// printf("iter: %zu, x: %f, y: %f\n", iter, x, y);
		if ((x * x + y * y) > 4)
			return iter;
		iter++;
	}
	return (iter);
}

size_t	julia(double x, double y, double a, double b)
{
	double	x_prev;
	size_t	iter;

	iter = 1;
	x = x / WIN_WIDTH * 4 - 2;
	y = y / WIN_HEIGHT * (-4) + 2;
	while (iter < MAX_ITER)
	{
		x_prev = x;
		x = x * x - y * y + a;
		y = 2 * x_prev * y + b;
		// printf("iter: %zu, x: %f, y: %f\n", iter, x, y);
		if ((x * x + y * y) > 4)
			return iter;
		iter++;
	}
	return (iter);
}

int		window_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

int		key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	return(0);
}

int		close(int keycode)
{
	(void)keycode;
	exit(0);
}

void	put_pixel(t_img *img)
{
	int		iter;
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h <= WIN_HEIGHT)
	{
		count_w = -1;
		// while문을 1개로 만든다.
		// check threshold
		// 
		while (++count_w <= WIN_WIDTH)
		{
			iter = mandelbrot(count_w, count_h);
			// printf("iter : %d\n", iter);
			// iter = julia(count_w, count_h, 0.285, 0);
			// printf("iter : %d\n", iter);
			if (iter < MAX_ITER)
				my_mlx_pixel_put(img, count_w, count_h, 0x00FFFFFF);
			else
				my_mlx_pixel_put(img, count_w, count_h, 0x00000000);
		}
	}
}

int main(void)
{
	// x,y,a,b
	// double	idx, threshold;
	t_mlx	mlx;

	if (!window_init(&mlx))
		return (0);
	put_pixel(&mlx.img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, close, 0);
	mlx_loop(mlx.mlx_ptr);

	// idx = 0;
	// threshold = 2.0;
	// while (idx < threshold)
	// {
	// 	printf("mandelbrot(%f, %f) : %zu\n", idx, idx, mandelbrot(idx, idx));
	// 	// printf("idx : %ll")
	// 	idx += 0.01;
	// }
		
	return (0);
}


/*
iter
*/