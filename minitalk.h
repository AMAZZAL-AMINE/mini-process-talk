/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:26:27 by mamazzal          #+#    #+#             */
/*   Updated: 2023/01/10 19:26:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>/* for kill, signal */
# include <unistd.h>/* for write */
# include <stdlib.h>/* for malloc, free, exit */
# include <stdbool.h>/* for bool */

void	kill_handler(int pid, int sig);
int		*one_and_zero_arr(int c);
void	send_signal_to_process(int pid, char *str);

int		ft_power(int power);
void	binary_to_ascii(char *str);
void	server(int sign, siginfo_t *data, void *context);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_atoi(const char *str);

#endif
