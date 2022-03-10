#include "mlx.h"

double	mandelbrot(double x, double y, double const a, double const b)
{
	/*
		mandelbrot set
		아래 점화식으로 정의된 수열이 발산하지 않는 성질을 갖도록 하는
		복소수 c의 집합으로 정의된다.
		z_0 = 0	// z_n은 complex
		z_{n+1} = (z_n)^2 + c

		(x_0, y_0) = (0, 0)
		x_{n+1} = x^2 - y^2 + a
		y_{n+1} = 2*x_n *y_n + b

		f(0) = 0
		f(1) = (a, b)
		f(2) = (a^2 - b^2 + a, 2ab + b)
		f(3) = 
	*/
	if (x == 0 && y == 0)
		return (0);
	
}

int main(void)
{
	// x,y,a,b
	mandelbrot(3, 3, 42, 42);

	return (0);
}

int	fib(int num)
{
	if (num <= 0)
		return 0;
	if (num <= 2)
		return 1;
	return fib(num - 1) + fib(num - 2);
}
// fib(3)