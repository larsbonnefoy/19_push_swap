/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:24:47 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/02 18:07:56 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack);

void	rra(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_printf("rra\n");
	reverse_rotate(stack);
}

void	rrb(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_printf("rrb\n");
	reverse_rotate(stack);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ft_printf("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next->next != NULL)
			tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack, last_node);
}
