/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:10 by rlaforge          #+#    #+#             */
/*   Updated: 2022/04/25 20:58:19 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINFT_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

int     ft_printf(const char *str, ...);
int     ft_params(char format, va_list args);
int     ft_putptr(unsigned long ptr);
int     ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int     ft_putchar(char c);
int     ft_putnbr_base(long long nb, char *base);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
