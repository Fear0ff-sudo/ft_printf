/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:05:30 by amanet            #+#    #+#             */
/*   Updated: 2026/11/16 16:33:35 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf_args(const char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while(s[i])
	{
		if(s[i] == '%' && s[i + 1] != '%')
			res++;
		else if (s[i] == '%' && s[i + 1] == '%')
			i++;
		i++;
	}
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		param;

	i = 0;
	param = ft_printf_args(s);
	va_start(args, param);
	while(s[i])
	{
		if(s[i] == '%' && s[i + 1] != '%')
		{
			if (s[i + 1] == 'c')
				ft_putchar_fd(va_arg(args, char), 1);
			else if (s[i + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			//else if (s[i + 1] == 'p')
			// 	ft_PLACE_HOLDER(va_arg(args, void *), 1);
		}
		else if (s[i] == '%' && s[i + 1] == '%')
			i++;
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	// printf("%d", ft_printf_args("%%d%s%%"));
	ft_printf("%d", 1);
	return (0);
}
