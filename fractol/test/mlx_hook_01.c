#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keycode : %d\n", keycode);
	printf("Hello from key_hook!\n");
	if (keycode == 53)
	{
		printf("You press ESC key. It will be closed.\n");
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
