#include <mlx.h>
#include <math.h>
#include <stdlib.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	// square
	for (int i = 5; i<100; i++)
		for (int j=5; j<100; j++)
			my_mlx_pixel_put(&img, i, j, i*j << 16);
	// triangle left side
	for (int i=300; i<600; i++)
		for (int j=600; j>600-(i-300); j--)
			my_mlx_pixel_put(&img, i, j, i << 12);
	// triangle right side
	for (int i=300; i<600; i++)
		for (int j=600; j<600+(i-300); j++)
			my_mlx_pixel_put(&img, i, j,  i << 12);
	// circle
	// 750, 750 지점을 원점으로 잡는다.
	// square 시작점과 origin을 잡고서 한다?
	for (int i=600; i<900; i++)
		for (int j=600; j<900; j++)
			if (pow(abs(750 - i), 2) + pow(abs(750 - j), 2) <= pow(100, 2) * 2)
				my_mlx_pixel_put(&img, i, j, i*j);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
