#include "ft_printf.h"

/*
		0. specifier or just string 
		   printf("hello \nwolrd, %s hi?, nice to meet you? \n\n Hi my name is %s I'm in %d\n\n", name1, name2, num);
		1.  just string
			write function or putchar
			putchar 써도 되는지 확인 필요
		2. specifier
			%기호가 나오면 시작
		
		- 필요한 것 
		format에는 "adgdsfgdf %d %%\n\n" 같은 것만 나오는가?
		ap는 어떻게 처리하는가?
		printf("%d %d %d", num1, num2, num3);
		즉 arguments들을 va_ function들을 사용하여 처리하여야하는데 어떻게 하는가?
*/
int main()
{
	ft_printf("test\nsentence\n");
	ft_printf("%c %c", 'a', 'b');
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		return_size;
	va_list	ap;

	return_size = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (format == '%')
		{
			format++;
			if (format == 'c')
			{
				ap
			}
			// va_arg(ap, int);
		}
		else
		{
			write(1, format, 1);
			return_size++;
		}
		
		format++;
	}
	va_end(ap);
	return (return_size);
}
