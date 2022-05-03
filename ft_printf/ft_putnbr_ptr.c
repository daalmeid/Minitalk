/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:57:49 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/19 16:36:34 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

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
