/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:53:23 by lsherry           #+#    #+#             */
/*   Updated: 2022/03/12 15:53:26 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler(int sigsum, siginfo_t *sig, void *context)
{
	static char	newchar;
	static int	i;
	char		bit;
	pid_t		pid;

	i++;
	if (sigsum == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	bit = bit << (8 - i);
	newchar = newchar | bit;
	if (i == 8)
	{
		write(1, &newchar, 1);
		i = 0;
		newchar = 0;
		pid = sig->si_pid;
		kill(pid, SIGUSR1);
	}
	(void) context;
}

int	main(void)
{
	struct sigaction	sigact;

	ft_printf("CURRENT PID: %u\n", getpid());
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
