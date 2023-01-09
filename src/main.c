/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:34:26 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/09 17:10:28 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printf_tab(char **tab);

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;
	int		is_string;

	is_string = 0;
	if (argc == 2)
		is_string = 1;
	argv = check_input(&argc, argv);
	stack_a = init_stack(argv, argc);
	stack_b = NULL;
	if (argc < 12)
		min_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	if (is_string == 1)
		free_tab(argv);
	ft_lstclear(&stack_a);
	return (0);
}

void printf_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_printf("tab[%d] = %s ",i, tab[i]);	
		i++;
	}
}
