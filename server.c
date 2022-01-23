/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:49:49 by daalmeid          #+#    #+#             */
/*   Updated: 2022/01/17 14:49:49 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_global	g_global;

static void handle_sigusr1(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char letter = 0b11111111;
	static unsigned char trader = 0b10000000;

	if (ucontext == NULL)
		return ;
	if (sig == 10)
		letter ^= trader;
	else if (sig == 12)
		letter |= trader;
	trader = trader >> 1;
	if (trader == 0)
	{	
		g_global.letter = letter;
		g_global.message[g_global.index++] = letter;
		trader = 0b10000000;
		letter = 0b11111111;
	}
	g_global.c_pid = info->si_pid;
}

int main()
{
   struct sigaction actusr1;
   
   g_global.index = 0;
   g_global.letter = 'a';
   ft_memset( &actusr1, '\0', sizeof(actusr1));
   actusr1.sa_sigaction = handle_sigusr1;
   actusr1.sa_flags = SA_SIGINFO;
   sigemptyset(&actusr1.sa_mask);
   sigaddset(&actusr1.sa_mask, SIGUSR1);
   sigaddset(&actusr1.sa_mask, SIGUSR2);
   ft_putnbr_fd(getpid(), 1);
   ft_putchar_fd('\n', 1);
   if (sigaction(SIGUSR1, &actusr1, NULL) == -1)
   	{	
   		ft_printf("Error in sigaction\n");
		exit (0);
	}
   if (sigaction(SIGUSR2, &actusr1, NULL) == -1)
   	{	
   		ft_printf("Error in sigaction\n");
		exit (0);
	}
   while(1)
   {
	   if (g_global.letter == '\0')
	   {
		   kill(g_global.c_pid, SIGUSR1);
		   ft_putstr_fd(g_global.message, 1);
		   g_global.letter = 'a';
		   g_global.index = 0;
	   }
   }
   return (0);
}
