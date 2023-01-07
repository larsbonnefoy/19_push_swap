/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:51:38 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/02 18:04:39 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *tmp, char stack_name)
{
	while (tmp)
	{
		if (stack_name == 'a')
			ft_printf("%d\n", tmp->content);
		else
			ft_printf(" 	%d\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	ft_printf("%p", tmp_a);
	ft_printf(" %p\n", tmp_b);
	ft_printf("a	b\n-	-\n");
	while (tmp_a && tmp_b)
	{
		ft_printf("%x", tmp_a->content);
		ft_printf(" 	%x\n", tmp_b->content);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_a)
		print_stack(tmp_a, 'a');
	else if (tmp_b)
		print_stack(tmp_b, 'b');
}

t_list	*init_stack(char *nbr[], int argc)
{
	t_list	*stack;
	int		a;

	a = 1;
	while (a < argc)
	{
		if (a == 1)
			stack = ft_lstnew(ft_atoi(nbr[a]));
		else
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(nbr[a])));
		a++;
	}
	return (stack);
}

int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int rotate_dir(t_list **stack, t_list *node)
{
	t_list *tmp;
	int pos;
	int len;
	int node_seen;

	pos = 0;
	len = 0;
	node_seen = 0;
	tmp = *stack;
	while (tmp != NULL)
	{	
		if (tmp == node)
			node_seen = 1;	
		if (node_seen == 0)
			pos++;
		len++;
		tmp = tmp->next;
	}
	if (pos*2 <= len)
		return (1);
	else
		return (0);
}
