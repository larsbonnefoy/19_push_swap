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
	
	//check_input(&argc, argv);
	stack_a = init_stack(argv, argc);
	stack_b = NULL;
	if (argc < 5)	
		min_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);

	ft_lstclear(&stack_a);
	return (0);
}

//si argc < 5 autre sort pcq radix trop lent
//=> devoir passer &argc pour modif la valeur dans le cas ou argv == str;
