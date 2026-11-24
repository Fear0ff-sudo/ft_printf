/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:20:02 by amanet            #+#    #+#             */
/*   Updated: 2026/11/24 13:51:07 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int ft_put_hexa_up_negative(int n)
// {
// 	int		i;
// 	char	*res;
// 	char	c;
// 	int		temp;

// 	i = 1;
// 	res = malloc(sizeof(char) * 8 + 1);
// 	if (!res)
// 		return (0);
// 	temp = n;
// 	while (i < 9)
// 	{
// 		if (n >= 2)
// 			ft_put_hexa_up(n / 2);
// 		c = (n % 2) + '0';
// 	}

// 	write(1, &c, 1);
// 	// while (temp >= 16)
// 	// {
// 	// 	temp /= 16;
// 	// 	i++;
// 	// }
// }

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
