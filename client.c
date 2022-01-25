/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:47:10 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/25 13:47:10 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_dec_to_bin(char *av, int pid_serv)
{
	unsigned char	trader;

	trader = 0b10000000;
	while (1)
	{
		while (trader != 0)
		{
			if (!(*av & trader) && kill(pid_serv, SIGUSR1) == -1)
			{	
				ft_putendl_fd("Signaling error!", 2);
				exit (0);
			}
			else if ((*av & trader) && kill(pid_serv, SIGUSR2) == -1)
			{
				ft_putendl_fd("Signaling error!", 2);
				exit (0);
			}
			trader = trader >> 1;
			usleep(100);
		}
		if (*(av++) == '\0')
			break ;
		if (trader == 0)
			trader = 0b10000000;
	}
}

static void	handle_sigusr_c(int sig)
{
	if (sig == SIGUSR1)
		ft_putendl_fd("Server signal caught!", 1);
	exit (0);
}

static int	ft_error_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (0);
	while (av[1][i] != '\0')
	{
		if (ft_isdigit(av[1][i++]) == 0 || av[1][0] == '-')
		{
			ft_putendl_fd("PID error.", 2);
			return (0);
		}
	}
	if (ft_strlen(av[2]) > 2084)
	{
		ft_putendl_fd("Message string too long.", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	actusr_c;

	if (ft_error_check(ac, av) == 0)
		return (0);
	ft_memset(&actusr_c, '\0', sizeof(actusr_c));
	actusr_c.sa_handler = handle_sigusr_c;
	sigemptyset(&actusr_c.sa_mask);
	pid = ft_atoi(av[1]);
	ft_dec_to_bin(av[2], pid);
	if (sigaction(SIGUSR1, &actusr_c, NULL) == -1)
	{
		ft_putendl_fd("Error in sigaction", 2);
		return (0);
	}
	while (1)
	{
		sleep(5);
		ft_putendl_fd("No signal received", 2);
		break ;
	}
	return (0);
}
