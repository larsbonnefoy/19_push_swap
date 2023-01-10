/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:37 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/10 16:17:44 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits(int max);

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		bits;
	int		i[2];
	int		num;
	int		stack_size;

	stack_size = len_stack(stack_a);
	normalize_stack(stack_a);
	bits = get_bits(len_stack(stack_a) - 1);
	i[0] = -1;
	while (++i[0] < bits)
	{
		i[1] = -1;
		while (++i[1] < stack_size)
		{
			tmp = *stack_a;
			num = tmp->content;
			if (((num >> i[0]) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

int	get_bits(int max)
{
	int	a;

	a = 0;
	while (max != 0)
	{
		max = max >> 1;
		a++;
	}
	return (a);
}
