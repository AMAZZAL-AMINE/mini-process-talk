/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:26:37 by mamazzal          #+#    #+#             */
/*   Updated: 2023/01/10 19:26:39 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
	{
		i += ft_putchar('0');
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	ci;
	int	fr;
	int	isminus;

	ci = 0;
	isminus = 1;
	fr = 0;
	while ((str[ci] >= '\t' && str[ci] <= '\r') || str[ci] == ' ')
	{
		ci++;
	}
	if (str[ci] == '-' || str[ci] == '+')
	{
		if (str[ci] == '-')
		{
			isminus = -1;
		}
		ci++;
	}
	while (str[ci] >= '0' && str[ci] <= '9')
	{
		fr = (fr * 10) + (str[ci] - '0');
		ci++;
	}
	return (fr * isminus);
}

int	ft_power(int power)
{
	int	result;

	result = 1;
	while (power--)
		result *= 2;
	return (result);
}
