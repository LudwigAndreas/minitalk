/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:53:16 by lsherry           #+#    #+#             */
/*   Updated: 2022/03/12 15:53:19 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_msg	g_msg;

void	ft_anshandler(int sigsum, siginfo_t *sig, void *context)
{
	if (sigsum == SIGUSR1)
		g_msg.counter += 1;
	(void ) sig;
	(void ) context;
}

int	ft_send_msg(pid_t pid, char *msg, struct sigaction *sigact)
{
	size_t	i;
	int		bit;

	i = 0;
	while (i < ft_strlen(msg))
	{
		bit = 128;
		while (bit > 0)
		{
			if (bit & msg[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit /= 2;
			if (bit == 0)
			{
				sigaction(SIGUSR1, sigact, NULL);
				if (i + 1 != g_msg.counter)
					return (i);
			}
			usleep(190);
		}
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	size_t				sent;
	struct sigaction	sigact;

	if (argc != 3)
	{
		ft_printf("try: \"./client PID_SERVER STRING_TO_PASS\"\n");
		exit(0);
	}
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_anshandler;
	g_msg.counter = 0;
	pid = ft_atoi(argv[1]);
	sent = ft_send_msg(pid, argv[2], &sigact);
	if (sent == ft_strlen(argv[2]))
		ft_printf("Message arrived.\nSent %d characters\n", sent);
	else
		ft_printf("Message error.\n", sent);
	return (0);
}
