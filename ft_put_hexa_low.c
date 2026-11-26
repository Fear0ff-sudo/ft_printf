/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:06:45 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 17:53:26 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_bin_hexa_low(char *n)
{
	int		i;
	int		temp;
	char	c;

	i = 0;
	if (!n)
		return (0);
	while (i < 32)
	{
		temp = 0;
		temp += (1 * (n[i + 3] - '0'));
		temp += (2 * (n[i + 2] - '0'));
		temp += (4 * (n[i + 1] - '0'));
		temp += (8 * (n[i] - '0'));
		if ((temp % 16) > 9)
			c = ((temp % 16) - 9) + ('a' - 1);
		else
			c = (temp % 16) + '0';
		write(1, &c, 1);
		i += 4;
	}
	return (8);
}

static int	ft_put_hexa_low_negative(int n)
{
	return (ft_put_bin_hexa_low(ft_to_bin(n)));
}

int	ft_put_hexa_low(int n)
{
	int		i;
	char	c;
	int		temp;

	i = 1;
	if (n < 0)
		return (ft_put_hexa_low_negative(n));
	temp = n;
	while (temp >= 16)
	{
		temp /= 16;
		i++;
	}
	if (n >= 16)
		ft_put_hexa_low(n / 16);
	if ((n % 16) > 9)
		c = ((n % 16) - 9) + ('a' - 1);
	else
		c = (n % 16) + '0';
	write(1, &c, 1);
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("\n%d", ft_put_hexa_low(0));
// 	return (0);
// }