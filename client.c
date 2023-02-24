/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:19:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/01/08 17:19:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_handler(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr("Kill Error: Process not found");
		exit(1);
	}
}

int	*one_and_zero_arr(int c)
{
	int	save;
	int	*total;
	int	index;

	index = 7;
	total = malloc(8 * sizeof(int));
	while (index >= 0)
	{
		save = c % 2;
		total[index] = save;
		c = c / 2;
		index--;
	}
	return (total);
}

void	send_signal_to_process(int pid, char *str)
{
	int	counter;
	int	*binarys;
	int	n;

	counter = 0;
	while (str[counter])
	{
		binarys = one_and_zero_arr(str[counter]);
		n = 0;
		while (n < 8)
		{
			if (binarys[n] == 1)
				kill_handler(pid, SIGUSR1);
			else
				kill_handler(pid, SIGUSR2);
			n++;
			usleep(500);
		}
		counter++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_putstr("Syntax Error: Argement must be 2");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
		{
			ft_putstr("Error : PID must be a number");
			return (0);
		}
		i++;
	}
	send_signal_to_process(pid, argv[2]);
	return (0);
}
