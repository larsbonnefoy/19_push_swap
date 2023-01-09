/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:07:38 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/09 16:47:50 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_string_entites(char *str)
{ 
	int	i;
	int digit_flag;

	digit_flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] != ' ')
		{
			digit_flag+=1;
			i++;
		}
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (digit_flag);
}

void	check_duplicates(int argc, char *argv[])
{
	int i;
	int j;
	int curr_number;

	i = 1;
	while (i < argc)
	{
		curr_number = ft_atoi(argv[i]);	
		j = i + 1;
		while (j < argc)
		{
			if (curr_number == ft_atoi(argv[j]))
				error();
			j++;
		}
		i++;
	}
}

void is_valid_number(char *str)
{
	int a;

	a = 0;
	if (ft_isdigit(str[0]) == 1)
		a++;
	else if ((str[0] == '-' || str[0] == '+' ) && ft_strlen(str) > 1)
		a++;
	else
		error();
	while (str[a] != '\0')
	{
		if (ft_isdigit(str[a]) == 1)
			a++;
		else
			error();
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		error();
}
