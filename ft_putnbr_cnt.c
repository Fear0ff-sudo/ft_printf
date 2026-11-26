/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 17:31:23 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 17:35:13 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_cnt(int n)
{
	char	c;
	int		res;

	res = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		res++;
	}
	if (n >= 10)
		res += ft_putnbr_cnt(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (res + 1);
}
// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		ft_putnbr_cnt(ft_atoi(argv[1]), 1);
// 		//ft_putnbr_cnt(-2147483648, 1);
// 	}
// 	return (0);
// }