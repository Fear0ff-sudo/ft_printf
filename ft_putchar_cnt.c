/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 17:12:24 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 17:15:07 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_cnt(char c)
{
	write(1, &c, 1);
	return (1);
}
// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		ft_putchar_cnt(argv[1][0]);
// 	}
// 	return (0);
// }