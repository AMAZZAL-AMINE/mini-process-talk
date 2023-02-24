/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:19:32 by mamazzal          #+#    #+#             */
/*   Updated: 2023/01/08 17:19:35 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct	s_custum_ha_struct
{
	int		old_pid;
	char	*binary_string;
	int		counter;
} s_handle;

void	print_process_id(pid_t pid)
{
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	binary_to_ascii(char *str)
{
	int		i;
	int		j;
	int		sum;
	char	chr;

	i = 0;
	j = 7;
	sum = 0;
	while (i < 8)
	{
		sum += (str[j] - 48) * ft_power(i);
		chr = sum;
		i++;
		j--;
	}
	ft_putchar(chr);
}

void	server(int sign, siginfo_t *data, void *context)
{
	context = NULL;
	if (s_handle.old_pid != data->si_pid)
	{
		s_handle.old_pid = data->si_pid;
		s_handle.counter = 0;
	}
	if (s_handle.counter == 0)
	{
		s_handle.binary_string = malloc(sizeof(char) * 8);
		if (!s_handle.binary_string)
			exit(1);
	}
	if (sign == SIGUSR1)
		s_handle.binary_string[s_handle.counter++] = '1';
	else if (sign == SIGUSR2)
		s_handle.binary_string[s_handle.counter++] = '0';
	if (s_handle.counter == 8)
	{
		binary_to_ascii(s_handle.binary_string);
		free(s_handle.binary_string);
		s_handle.counter = 0;
	}
}

int	main(void)
{
	int					pid_;
	struct sigaction	act;

	pid_ = getpid();
	act.sa_sigaction = server;
	print_process_id(pid_);
	while (true)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
