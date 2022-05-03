/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:13 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/06 15:35:06 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

static void	ft_puthex_pos(int nbr, char *base)
{
	int		i;

	i = ft_strlen(base);
	if (i < 16)
		return ;
	if (nbr > i - 1)
		ft_puthex_pos(nbr / i, base);
	write(1, &(base[nbr % i]), 1);
}

static void	print_hex_neg(int bin [], char *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		if (bin[i] == 1)
			bin[i] = 0;
		else if (bin[i] == 0)
			bin[i] = 1;
		i++;
	}
	while (--i >= 0 && bin[i] == 1)
		bin[i] = 0;
	if (i >= 0)
		bin[i] = 1;
	i = 0;
	while (i < 32)
	{
		j = bin[i] * 8 + bin[i + 1] * 4 + bin[i + 2] * 2 + bin[i + 3];
		write(1, &(base[j]), 1);
		i += 4;
	}
}

static void	ft_puthex_neg(int nb, char *base)
{
	int	bin[32];
	int	i;

	i = 0;
	while (i < 32)
		bin[i++] = 0;
	i = 31;
	if (nb < 0)
	{	
		bin[i] = -nb % 2;
		nb /= 2;
		i--;
	}
	nb = -nb;
	while (i >= 0 && nb > 0)
	{
		bin[i] = nb % 2;
		nb /= 2;
		i--;
	}
	print_hex_neg(bin, base);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;

	i = nbr;
	j = 1;
	while (i > 15 || i < -15)
	{
		i /= 16;
		j++;
	}
	if (nbr >= 0)
		ft_puthex_pos(nbr, base);
	else if (nbr < 0)
	{	
		ft_puthex_neg(nbr, base);
		j = 8;
	}
	return (j);
}

/*
int	main(void)
{
	int		nbr;
	char	*base;

	nbr = -2147483648;
	base = "0123456789";
	ft_putnbr_base(nbr, base, "");
	write(1, "\n", 1);
	nbr = 10;
	base = "0123456789ABCDEF";
	ft_putnbr_base(nbr, base, "");
	write(1, "\n", 1);
	nbr = -2147483647;
	base = "01";
	ft_putnbr_base(nbr, base, "");
	write(1, "\n", 1);
	nbr = 0x7FFFFFFF;
	base = "01234567";
	ft_putnbr_base(nbr, base, "");
}
*/