#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i++])
                ;
        return (--i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(long nb, char *base)
{
	unsigned int    buf;
	static int	len;
	unsigned int	baselen;

	baselen = ft_strlen(base);
	buf = nb;
	if (nb < 0)
	{
		buf = -buf;
		len += ft_putchar('-');
	}
	if (buf <= baselen - 1)
		len += ft_putchar(base[buf]);
	if (buf > baselen - 1)
	{
		ft_putnbr_base(buf / baselen, base);
		ft_putnbr_base(buf % baselen, base);
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
	if (format == 'c')
		len += ft_putchar((char)va_arg( args, int ));
	if (format == 's')
		len += ft_putstr(va_arg( args, char * ));
	if (format == 'i')
		len += ft_putnbr_base(va_arg( args, int ), "0123456789");
	if (format == 'u')
		len += ft_putnbr_base(va_arg( args, unsigned int ), "0123456789");
	if (format == 'x')
		len += ft_putnbr_base(va_arg( args, int ), "0123456789abcdef");
	if (format == 'X')
		len += ft_putnbr_base(va_arg( args, int ), "0123456789ABCDEF");
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
	ft_printf("\nWritten char: %i\n\n", ft_printf("chr: %c", 'x') );
	ft_printf("\nWritten char: %i\n\n", ft_printf("str: %s", "salut les gars") );
	ft_printf("\nWritten char: %i\n\n", ft_printf("uns: %u", 4294967295) );
	ft_printf("\nWritten char: %i\n\n", ft_printf("int: %i", 2147483647) );
	ft_printf("\nWritten char: %i\n\n", ft_printf("hex: %x", 2147483647) );
	ft_printf("\nWritten char: %i\n\n", ft_printf("HEX: %X", 2147483647) );
	ft_printf("\nWritten char: %i\n\n", ft_printf("per: %%") );
	return (0);
}
