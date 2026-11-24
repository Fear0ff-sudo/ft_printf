/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:20:02 by amanet            #+#    #+#             */
/*   Updated: 2026/11/20 15:07:28 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa_up(int n)
{
	int		i;
	char	c;
	int		temp;

	i = 1;
	temp = n;
	while(temp >= 16)
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
