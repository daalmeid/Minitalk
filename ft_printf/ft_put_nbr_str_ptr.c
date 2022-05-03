/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:23:53 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/22 15:15:50 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr_printf(int nbr)
{
	int	i;
	int	j;

	i = nbr;
	j = 1;
	while (i > 9 || i < -9)
	{
		i /= 10;
		j++;
	}
	if (nbr < 0)
		j++;
	ft_putnbr_fd(nbr, 1);
	return (j);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	if (s == 0)
	{	
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

static void	check_putnbr_ptr(unsigned long nbr, char *base)
{
	if (nbr > 15)
	{
		check_putnbr_ptr(nbr / 16, base);
	}
	write(1, &(base[nbr % 16]), 1);
}

int	ft_putnbr_ptr(unsigned long nbr, char *base)
{	
	unsigned long	i;
	int				j;

	ft_putstr_fd("0x", 1);
	i = nbr;
	j = 1;
	while (i > 15)
	{
		i /= 16;
		j++;
	}
	check_putnbr_ptr(nbr, base);
	return (j + 2);
}

/*int	main(void)
{
	int	n;
	int	fd;

	n = 21474836;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}*/