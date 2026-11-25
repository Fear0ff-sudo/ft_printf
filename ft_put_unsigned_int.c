/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 11:05:22 by amanet            #+#    #+#             */
/*   Updated: 2026/11/25 15:29:07 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int n)
{
	char			c;
	unsigned int	i;
	unsigned int	temp;

	i = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		i++;
	}
	if (n >= 10)
		ft_put_unsigned_int(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (i);
}
