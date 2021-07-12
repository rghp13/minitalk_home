/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:26:36 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/10 18:22:04 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

/*
**a.out 12345 "hello world"
**send message
**get confirm
**print confirm
**end program
*/

int	main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t	s_pid;
	char	*binary;
	int i;
	int k;

	sa.sa_sigaction =  ft_handler;
	k = 1;
	if (argc < 3)
		return (-1);
	s_pid = ft_atoi(argv[1]);
	while (k < argc)
	{
		i = 0;
		while (argv[k][i])
		{
			ft_bit_check(argv[k][i++], s_pid);
		}
		ft_bit_check('\0', s_pid);
		pause();
		k++;
	}
	return (0);
}

void	ft_handler(void)
{
	printf("Message was recieved\n");
}

void	ft_bit_check(unsigned char bit, pid_t s_pid)
{
	int bitmask;

	bitmask = 0b10000000;
	while (bitmask)
	{
		if (bit & bitmask)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		usleep(10);
		bitmask >> 1;
	}
}