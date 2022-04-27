/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:30:02 by rlaforge          #+#    #+#             */
/*   Updated: 2022/04/27 14:56:02 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i] != '\0' && str)
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr_p(unsigned long long nb)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcedf";
	if (nb <= 15)
		len += ft_putchar(base[nb]);
	if (nb > 15)
	{
		len += ft_putnbr_p(nb / 16);
		len += ft_putnbr_p(nb % 16);
	}
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	len += ft_putnbr_p(ptr);
	return (len);
}
