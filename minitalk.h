#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "libftprintf/ft_printf.h"

typedef struct	s_msg
{
	int		counter;
	char	*chr;
}				t_msg;

#endif