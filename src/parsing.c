/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:04 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/11 13:39:34 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_digit_input(int argc, char *argv[], int is_str);
char	**check_str_input(int *argc, char *argv[]);

char	**check_input(int *argc, char *argv[])
{
	char	**new_argv;

	if (*argc > 2)
	{
		check_digit_input(*argc, argv, 0);
		return (argv);
	}
	else if (*argc == 2)
	{
		new_argv = check_str_input(argc, argv);
		return (new_argv);
	}
	else
		error();
	return (NULL);
}

void	check_digit_input(int argc, char *argv[], int is_str)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		is_valid_number(argv[i], is_str, argv);
		i++;
	}
	check_duplicates(argc, argv, is_str);
}

char	**check_str_input(int *argc, char *argv[])
{
	char	**new_argv;
	int		i;

	if (check_string_entites(argv[1]) < 1)
		error();
	argv[1] = ft_strjoin("place_holder ", argv[1]);
	if (argv[1] == NULL)
		error();
	new_argv = ft_split(argv[1], ' ');
	if (new_argv == NULL)
		error();
	free(argv[1]);
	*argc = 0;
	i = -1;
	while (new_argv[++i] != NULL)
		*argc = *argc + 1;
	check_digit_input(*argc, new_argv, 1);
	return (new_argv);
}
