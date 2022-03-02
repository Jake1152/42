#include <mlx.h>
#include <stdio.h>

typedef struct  s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int key_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hellow from key_hook!\n");
	return (0);
}

int mouse_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hellow from key_hook!\n");
	return (0);
}

int main(void)
{
	t_vars  vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}

