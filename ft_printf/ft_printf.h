/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:08:29 by daalmeid          #+#    #+#             */
/*   Updated: 2021/12/06 15:35:01 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_un(unsigned int nbr);
int		ft_putnbr_ptr(unsigned long nbr, char *base);
int		ft_isalpha(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_putstr_printf(char *s);
int		ft_putnbr_printf(int nbr);
int		ft_printf(const char *s, ...);

#endif