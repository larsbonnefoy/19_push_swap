/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:06:30 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/19 16:48:44 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_create_out(int i, const char *str, int sign);

long	ft_atol(const char *str)
{
	int		sign;
	long	base;
	int		i;

	i = 0;
	base = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (ft_isdigit(str[i]) == 1)
	{	
		base = ft_create_out(i, str, sign);
		return (base * sign);
	}		
	else
		return (0);
}

static long	ft_create_out(int i, const char *str, int sign)
{
	unsigned long int	out;

	out = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		out = (out * 10) + (str[i] - 48);
		if (out > INT_MAX && sign == 1)
			return ((long)INT_MAX + 2);
		else if ((out > (long)INT_MIN * -1) && (sign == -1))
			return ((long)INT_MAX + 2);
		i++;
	}
	return ((long)out);
}
