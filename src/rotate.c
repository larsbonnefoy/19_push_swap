/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:39:28 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/02 18:08:41 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack);

void	ra(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_printf("ra\n");
	rotate(stack);
}

void	rb(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_printf("rb\n");
	rotate(stack);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ft_printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}

void	rotate(t_list **stack)
{
	t_list	*first_node;

	first_node = *stack;
	*stack = (*stack)->next;
	first_node->next = NULL;
	ft_lstadd_back(stack, first_node);
}
