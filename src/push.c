/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:06:06 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/02 18:06:35 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node_b;

	if (*stack_b == NULL)
		return ;
	ft_printf("pa\n");
	first_node_b = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, first_node_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node_a;

	if (*stack_a == NULL)
		return ;
	ft_printf("pb\n");
	first_node_a = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, first_node_a);
}
