/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:46:58 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/25 13:46:58 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

t_global	g_global;

static void	handle_sigusr1(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	letter = 0b11111111;
	static unsigned char	trader = 0b10000000;

	(void) ucontext;
	if (sig == SIGUSR1)
		letter ^= trader;
	else if (sig == SIGUSR2)
		letter |= trader;
	trader >>= 1;
	if (trader == 0)
	{	
		g_global.message[g_global.index++] = letter;
		trader = 0b10000000;
		letter = 0b11111111;
		g_global.c_pid = info->si_pid;
	}
}

static void	prep_act(struct sigaction *act)
{
	ft_memset(act, '\0', sizeof(*act));
	act->sa_sigaction = handle_sigusr1;
	act->sa_flags = SA_SIGINFO;
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	sigaddset(&act->sa_mask, SIGUSR2);
}

int	main(void)
{
	struct sigaction	actusr1;

	g_global.index = 0;
	g_global.message[g_global.index] = 'a';
	prep_act(&actusr1);
	ft_printf("%d\n", getpid());
	if (sigaction(SIGUSR1, &actusr1, NULL) == -1
		|| sigaction(SIGUSR2, &actusr1, NULL) == -1)
	{
		ft_putendl_fd("Error in sigaction.", 2);
		return (0);
	}
	while (1)
	{
		pause();
		if (g_global.index != 0 && g_global.message[g_global.index - 1] == '\0')
		{
			ft_printf("%s\n", g_global.message);
			usleep(100);
			kill(g_global.c_pid, SIGUSR1);
			g_global.index = 0;
		}
	}
	return (0);
}
