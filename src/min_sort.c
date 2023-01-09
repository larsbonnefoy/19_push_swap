/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:44:17 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/09 14:45:51 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	min_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_addr;
	t_list	*tmp;
	int		rotate_up;

	while (is_sorted(stack_a) == 0)
	{
		min_addr = find_min(stack_a);
		rotate_up = rotate_dir(stack_a, min_addr);
		tmp = *stack_a;
		while (tmp != min_addr && tmp)
		{
			if (rotate_up == 1) 
				ra(stack_a);
			else
				rra(stack_a);
			tmp = *stack_a;
		}
		if (is_sorted(stack_a) == 1)
			break;
		if (tmp == min_addr)
			pb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
