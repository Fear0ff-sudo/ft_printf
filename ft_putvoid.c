/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:55:42 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 17:29:28 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_void_to_hexa_low(unsigned long n)
{
	int				i;
	char			c;
	unsigned long	temp;

	i = 1;
	temp = n;
	while (temp >= 16)
	{
		temp /= 16;
		i++;
	}
	if (n >= 16)
		ft_void_to_hexa_low(n / 16);
	if ((n % 16) > 9)
		c = ((n % 16) - 9) + ('a' - 1);
	else
		c = (n % 16) + '0';
	write(1, &c, 1);
	return (i);
}

int	ft_putvoid(void *adress)
{
	if (!adress)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_void_to_hexa_low((unsigned long)adress) + 2);
}
