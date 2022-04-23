#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
        unsigned int    buf;
	static int	len;

        buf = nb;
        if (nb < 0)
        {
                buf = -buf;
                write(1, "-", 1);
        }
        if (buf <= 9)
		len += ft_putchar(buf + '0');
	if (buf > 9)
	{
		ft_putnbr(buf / 10);
		ft_putnbr(buf % 10);
	}
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (i);
}

int	ft_params (char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_putstr(va_arg( args, char * ));
	if (format == 'i')
		len += ft_putnbr(va_arg( args, int ));
	if (format == 'c')
		len += ft_putchar((char)va_arg( args, int ));
	if (format == '%')
               len += ft_putchar('%');
	return (len);
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
			len += ft_params(str[++i], args);
	}
	va_end(args);
	return (len);
}

int	main (void)
{
	ft_printf("\nWritten char: %i\n\n", ft_printf("str: %s", "salut les gars") );
	ft_printf("\nWritten char: %i\n\n", ft_printf("int: %i", 1234567) );
	ft_printf("\nWritten char: %i\n\n", ft_printf("chr: %c", 'x') );
	ft_printf("\nWritten char: %i\n\n", ft_printf("per: %%") );
	return (0);
}
