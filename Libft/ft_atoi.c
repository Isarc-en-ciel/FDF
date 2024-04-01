/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:58:10 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/28 14:53:09 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	i;
	long long	x;
	long long	sign;

	i = 0;
	sign = 1;
	x = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + str[i] - '0';
		i++;
	}
	if ((x * sign > INT_MAX) || (x * sign < INT_MIN))
		ft_overflow();
	if (x > 100000)
		x = 100000;
	return (x * sign);
}

void	ft_overflow(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
