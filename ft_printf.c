/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:05:30 by amanet            #+#    #+#             */
/*   Updated: 2026/11/17 10:04:04 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

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
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%' && s[i + 1] != '%')
		{
			ft_call_ft(s + i + 1, args);
			i++;
		}
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
		else if (ft_isprint(s[i]))
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	// printf("%d", ft_printf_args("%%d%s%%"));
	ft_printf("Un nombre : %d\n Un char : %c", 42, 'c');
	return (0);
}
