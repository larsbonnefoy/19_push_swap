/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:57:23 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/10 15:57:38 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_tab_error(char **argv, int is_str)
{
	if (is_str == 1)
		free_tab(argv);
	error();
}

void	free_stack(t_list **stack, char **argv, int is_str)
{
	ft_lstclear(stack);
	free_tab_error(argv, is_str);
}
