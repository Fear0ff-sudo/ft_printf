/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:51:35 by amanet            #+#    #+#             */
/*   Updated: 2026/11/25 15:27:49 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(int n)
{
	int		i;
	int		temp;

	i = 1;
	temp = n;
	while (temp >= 2)
	{
		temp /= 2;
		i++;
	}
	return (i);
}

static char	*ft_to_bin_pos(int n)
{
	int		i;
	int		temp;
	char	*res;

	i = 0;
	temp = ft_get_size(n);
	res = malloc(sizeof(char) * 32 + 1);
	if (!res)
		return (NULL);
	ft_memset(res, '0', 32);
	while (i < temp)
	{
		res[(32 - 1) - i] = '0' + (n % 2);
		n /= 2;
		i++;
	}
	res[32] = '\0';
	return (res);
}

static char	*ft_to_bin_negative(int n)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_to_bin_pos(n * -1);
	while (res[i])
	{
		if (res[i] == '0')
			res[i] = '1';
		else
			res[i] = '0';
		i++;
	}
	i = 0;
	while (i < 32)
	{
		if (res[(32 - 1) - i] == '0')
		{
			res[(32 - 1) - i] = '1';
			return (res);
		}
		res[(32 - 1) - i] = '0';
		i++;
	}
	return (res);
}

char	*ft_to_bin(int n)
{
	if (n < 0)
		return (ft_to_bin_negative(n));
	return (ft_to_bin_pos(n));
}
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		printf("%s\n", ft_to_bin(ft_atoi(argv[1])));
// 	}
// 	return (0);
// }
