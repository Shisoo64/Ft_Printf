#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int nb)
{
        unsigned int    buf;

        buf = nb;
        if (nb < 0)
        {
                buf = -buf;
                write(1, "-", 1);
        }
        if (buf <= 9)
		ft_putchar(buf + '0');
	if (buf > 9)
	{
		ft_putnbr(buf / 10);
		ft_putnbr(buf % 10);
	}
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list args;
	int	len;

	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			if (str[i] == '%' && str[i + 1] == 's')
                		len += ft_putstr(va_arg( args, char * ));
			if (str[i] == '%' && str[i + 1] == 'i')
                		ft_putnbr(va_arg( args, int ));
			if (str[i] == '%' && str[i + 1] == 'c')
                		len += ft_putchar((char)va_arg( args, int ));
			if (str[i] == '%' && str[i + 1] == '%')
                		len += ft_putchar('%');
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	main (void)
{
	ft_printf("\nWritten char: %i\n\n", ft_printf("str: %s", "salut les gars") );
	ft_printf("\nX Written char: %i\n\n", ft_printf("int: %i", 123) );
	ft_printf("\nWritten char: %i\n\n", ft_printf("chr: %c", 'x') );
	ft_printf("\nWritten char: %i\n\n", ft_printf("per: %%") );
	return (0);
}
