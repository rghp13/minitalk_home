/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:04:23 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/22 17:15:14 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern t_array	g_buffer;

int	ft_convert_pid_str(void)
{
	printf("The Server PID is = %d\n", getpid());
	return (0);
}

void	ft_store_bit(int sig, siginfo_t *si, void *arg)
{
	(void)arg;
	(void)sig;
	g_buffer.pid = si->si_pid;
	if (sig == SIGUSR1)
		ft_add_bit(0);
	else if (sig == SIGUSR2)
		ft_add_bit(1);
	else
	{
		printf("ERROR! SIGNO IS SET TO VAL %d\n", si->si_signo);
		exit(1);
	}
}
