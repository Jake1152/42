#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

# define WIDTH		1920
# define HEIGHT		1080

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

#endif
