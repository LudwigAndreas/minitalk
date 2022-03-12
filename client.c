#include "minitalk.h"

int	get_answer()

int	ft_send_msg(pid_t pid, char *msg)
{
	size_t i;
	int bit;

	i = 0;
	while (i < ft_strlen(msg))
	{
		bit = 128;
		while (bit > 0)
		{
			if (bit & msg[i])
			{
				ft_printf("%d -- bit\n", 1);
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf("%d -- bit\n", 0);
				kill(pid, SIGUSR2);
			}
			bit /= 2;
			usleep(5);
		}
		if (!get_answer)
			return i;
		i++;
	}
	return (i);
}

int main(int argc, char ** argv)
{
	pid_t	pid;
	size_t 	sent;
	struct sigaction sigact;

	
	if (argc != 3)
	{
		ft_printf("usage:  client [PID] [MESSAGE]\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	sent = ft_send_msg(pid, argv[2]);
	if (sent == ft_strlen(argv[2]))
		ft_printf("Message arrived.\nSent %d characters\n", sent);
	else
		ft_printf("Message error.\nSent %d characters", sent);

	return(0);
}
