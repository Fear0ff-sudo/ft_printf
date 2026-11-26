/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:05:30 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 16:15:37 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

// static int	ft_printf_args(const char *s)
// {
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	while(s[i])
// 	{
// 		if(s[i] == '%' && s[i + 1] != '%')
// 			res++;
// 		else if (s[i] == '%' && s[i + 1] == '%')
// 			i++;
// 		i++;
// 	}
// 	return (res);
// }

static void	ft_call_ft(const char *s, va_list args)
{
	if (s[0] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (s[0] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	//else if (s[0] == 'p')
	// 	ft_PLACE_HOLDER(va_arg(args, void *), 1);
	else if (s[0] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (s[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (s[0] == 'u')
		ft_put_unsigned_int(va_arg(args, unsigned int));
	else if (s[0] == 'X')
		ft_put_hexa_up(va_arg(args, unsigned int));
	else if (s[0] == 'x')
		ft_put_hexa_low(va_arg(args, unsigned int));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			ft_call_ft(s + i + 1, args);
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
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	void	*test = "test";

	printf("Un char :\n");
	ft_printf("ft   : %c\n", 'c');
	printf("real : %c\n", 'c');
	printf("\n");

	printf("Un string :\n");
	ft_printf("ft   : %s \n", "Hello World!");
	printf("real : %s \n", "Hello World!");
	printf("\n");

	printf("Un void * :\n");
	// ft_printf("ft   : %s \n", "Hello World!");
	printf("real : %p \n", &test);
	printf("\n");

	printf("Un decimal :\n");
	ft_printf("ft   : %d \n", 42);
	printf("real : %d \n", 42);
	printf("\n");

	printf("Un int :\n");
	ft_printf("ft   : %i \n", 42);
	printf("real : %i \n", 42);
	printf("\n");

	printf("Un unsigned decimal :\n");
	ft_printf("ft   : %u \n", 42);
	printf("real : %u \n", 42);
	printf("\n");

	printf("Hexa low :\n");
	ft_printf("ft   : %x %x %x\n", 42, -42, 5800);
	printf("real : %x %x %x\n", 42, -42, 5800);
	printf("\n");

	printf("Hexa UP :\n");
	ft_printf("ft   : %X %X %X\n", 42, -42, 5800);
	printf("real : %X %X %X\n", 42, -42, 5800);
	printf("\n");

	printf("Percentage :\n");
	ft_printf("ft   : %x %% %%x\n", 42);
	printf("real : %x %% %%x\n", 42);
	printf("\n");
	return (0);
}
