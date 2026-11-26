/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:05:30 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 19:02:45 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_call_ft(const char *s, va_list args)
{
	if (s[0] == 'c')
		return (ft_putchar_cnt(va_arg(args, int)));
	else if (s[0] == 's')
		return (ft_putstr_cnt(va_arg(args, char *)));
	else if (s[0] == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	else if (s[0] == 'd')
		return (ft_putnbr_cnt(va_arg(args, int)));
	else if (s[0] == 'i')
		return (ft_putnbr_cnt(va_arg(args, int)));
	else if (s[0] == 'u')
		return (ft_put_unsigned_int(va_arg(args, unsigned int)));
	else if (s[0] == 'x')
		return (ft_put_hexa_low(va_arg(args, unsigned int)));
	else if (s[0] == 'X')
		return (ft_put_hexa_up(va_arg(args, unsigned int)));
	return (0);
}

static int	ft_call_or_print(int *pi, const char *s, va_list args)
{
	int	i;
	int	res;

	i = *pi;
	res = 1;
	if (s[i] == '%' && s[i + 1] != '%')
	{
		res = ft_call_ft(s + i + 1, args);
		i++;
	}
	else if (s[i] == '%' && s[i + 1] == '%')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	else
		ft_putchar_fd(s[i], 1);
	i++;
	*pi = i;
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(args, s);
	while (s[i])
	{
		res += ft_call_or_print(&i, s, args);
	}
	va_end(args);
	return (res);
}
// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	void	*test = "test";
// 	int ft_count;
// 	int real_count;

// 	printf("Char :\n");
// 	ft_count = ft_printf("ft   : %c %c\n", 'c', '*');
// 	real_count = printf("real : %c %c\n", 'c', '*');
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("String :\n");
// 	ft_count = ft_printf("ft   : %s %s\n", "Hello World!", "");
// 	real_count = printf("real : %s %s\n", "Hello World!", "");
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Void * :\n");
// 	ft_count = ft_printf("ft   : %p %p\n", &test, NULL);
// 	real_count = printf("real : %p %p\n", &test, NULL);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Decimal :\n");
// 	ft_count = ft_printf("ft   : %d %d %d %d\n", 42, -42, INT_MAX, INT_MIN);
// 	real_count = printf("real : %d %d %d %d\n", 42, -42, INT_MAX, INT_MIN);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Int :\n");
// 	ft_count = ft_printf("ft   : %i %i %i %i\n", 42, -42, INT_MAX, INT_MIN);
// 	real_count = printf("real : %i %i %i %i\n", 42, -42, INT_MAX, INT_MIN);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Unsigned decimal :\n");
// 	ft_count = ft_printf("ft   : %u %u\n", 42, UINT_MAX);
// 	real_count = printf("real : %u %u\n", 42, UINT_MAX);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Hexa low :\n");
// 	ft_count = ft_printf("ft   : %x %x %x\n", INT_MAX, -42, 5800);
// 	real_count = printf("real : %x %x %x\n", INT_MAX, -42, 5800);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Hexa UP :\n");
// 	ft_count = ft_printf("ft   : %X %X %X\n", INT_MAX, -42, 5800);
// 	real_count = printf("real : %X %X %X\n", INT_MAX, -42, 5800);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");

// 	printf("Percentage :\n");
// 	ft_count = ft_printf("ft   : %x %% %%x\n", 42);
// 	real_count = printf("real : %x %% %%x\n", 42);
// 	printf("-- ft count   : %d --\n", ft_count);
// 	printf("-- real count : %d --\n", real_count);
// 	printf("\n");
// 	return (0);
// }
