/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:00:04 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/10 16:01:18 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min_addr;

	tmp = *stack;
	min_addr = tmp;
	while (tmp != NULL)
	{
		if (min_addr->content > tmp->content)
			min_addr = tmp;
		tmp = tmp->next;
	}
	return (min_addr);
}

t_list	*find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max_addr;

	tmp = *stack;
	max_addr = tmp;
	while (tmp != NULL)
	{
		if (max_addr->content < tmp->content)
			max_addr = tmp;
		tmp = tmp->next;
	}
	return (max_addr);
}

int	len_stack(t_list **stack_a)
{
	t_list	*tmp;
	int		a;

	if (*stack_a == NULL)
		return (0);
	a = 0;
	tmp = *stack_a;
	while (tmp)
	{
		a++;
		tmp = tmp->next;
	}
	return (a);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_rev_sorted(t_list **stack)
{	
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
