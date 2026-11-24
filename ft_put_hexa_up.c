/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:20:02 by amanet            #+#    #+#             */
/*   Updated: 2026/11/24 21:27:09 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_bin_hexa_up(char *n)
{
	int		i;
	int		temp;
	char	c;

	i = 16;
	if (!n)
		return (0);
	while (i > 0)
	{
		temp = 0;
		temp += 1 * n[i];
		temp += 2 * n[i - 1];
		temp += 4 * n[i - 2];
		temp += 8 * n[i - 3];
		if ((temp % 16) > 9)
			c = ((temp % 16) - 9) + ('A' - 1);
		else
			c = (temp % 16) + '0';
		write(1, &c, 1);
		i -= 4;
	}
	return (8);
}
int	ft_put_hexa_up_negative(int n)
{
	return (ft_put_bin_hexa_up(ft_to_bin(n)));
}

int	ft_put_hexa_up(int n)
{
	int		i;
	char	c;
	int		temp;

	i = 1;
	if (n < 0)
		return (ft_put_hexa_up_negative(n));
	temp = n;
	while (temp >= 16)
	{
		temp /= 16;
		i++;
	}
	if (n >= 16)
		ft_put_hexa_up(n / 16);
	if ((n % 16) > 9)
		c = ((n % 16) - 9) + ('A' - 1);
	else
		c = (n % 16) + '0';
	write(1, &c, 1);
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("\n%d", ft_put_hexa_up(0));
// 	return (0);
// }
