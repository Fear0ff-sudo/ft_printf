/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanet <amanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:42:05 by amanet            #+#    #+#             */
/*   Updated: 2026/11/27 14:51:29 by amanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"

int		ft_putchar_cnt(char c);
int		ft_putstr_cnt(char *s);
int		ft_putnbr_cnt(int n);

int		ft_put_unsigned_int(unsigned int n);
int		ft_put_hexa_up(int n);
int		ft_put_hexa_low(int n);
int		ft_putvoid(void *adress);

char	*ft_to_bin(int n);
void	ft_bin_reverse(char *s);

int		ft_isinstr(char c, char *str);

int		ft_printf(const char *s, ...);

#endif
