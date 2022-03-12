#include "minitalk.h"

void	ft_sighandler(int sigsum, siginfo_t *sig, void *context)
{
	static char newchar;
	static int	i;
	char		bit;
	pid_t		pid;

	i++;
	if (sigsum == SIGUSR1)
	{
		bit = 1;
//		write(1, "1\n", 2);
	}
	else
	{
		bit = 0;
//		write(1, "0\n", 2);
	}
	bit = bit << (8 - i);
	newchar = newchar | bit;
	if (i == 8)
	{
		write(1, &newchar, 1);
//		write(1, "\n", 1);
		i = 0;
		newchar = 0;
		pid = sig->si_pid;
		kill(pid, SIGUSR1);
	}
//	i++;
	(void ) sig;
	(void) context;
}

//TODO https://github.com/eschirni/minitalk/blob/master/bonus%20src/server_bonus.c


int main(void)
{
	struct sigaction sigact;

	ft_printf("CURRENT PID: %u\n", getpid());
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return(0);
}
