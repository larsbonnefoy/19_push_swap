/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:34:26 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/05 16:12:41 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;
	(void) stack_b;
	stack_a = init_stack(argv, argc);
	stack_b = NULL;
	radix_sort(&stack_a, &stack_b);
//	min_sort(&stack_a, &stack_b);
//	insertion_sort(&stack_a);
//	if (is_sorted(&stack_a) == 1)
//		ft_printf("OUAIS C'EST OK C SORTED\n");
	return (0);
}
