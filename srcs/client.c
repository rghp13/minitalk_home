/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:26:36 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/22 18:08:01 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**a.out 12345 "hello world"
**send message
**get confirm
**print confirm
**end program
*/

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				s_pid;
	int					i;

	sa.sa_sigaction = ft_handler;
	(void)sa;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		printf("Program requires exactly two arguments\n");
		printf("ARG1 = PID\nARG2 = STRING\n");
		return (-1);
	}
	s_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_bit_check(argv[2][i++], s_pid);
	}
	ft_bit_check('\0', s_pid);
	return (0);
}

void	ft_handler(int sig, siginfo_t *si, void *arg)
{
	(void)sig;
	(void)si;
	(void)arg;
	printf("This Program received a signal it should not have\n");
	exit(-1);
}

void	ft_bit_check(unsigned char bit, pid_t s_pid)
{
	int	bitmask;

	bitmask = 0b10000000;
	while (bitmask)
	{
		usleep(50);
		if (bit & bitmask)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		bitmask = bitmask >> 1;
	}
}
