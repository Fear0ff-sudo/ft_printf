/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 11:10:46 by amanet            #+#    #+#             */
/*   Updated: 2026/11/26 17:52:55 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int		ft_putchar_cnt(char c);
int		ft_putstr_cnt(char *s);
int		ft_putnbr_cnt(int n);

int		ft_put_unsigned_int(unsigned int n);
int		ft_put_hexa_up(int n);
int		ft_put_hexa_low(int n);
int		ft_putvoid(void *adress);

char	*ft_to_bin(int n);

#endif
