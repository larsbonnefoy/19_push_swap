/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:36:43 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/02 18:04:58 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../19_ft_printf/ft_printf.h"
# include"../19_libft/libft.h"

void	print_stack(t_list *tmp, char stack_name);
void	print_stacks(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack);
t_list	*init_stack(char *nbr[], int argc);
int		rotate_dir(t_list **stack, t_list *node);
t_list	*find_min(t_list **stack);
t_list	*find_max(t_list **stack);
int		len_stack(t_list **stack_a);
void	normalize_stack(t_list **stack);
void	check_input(int *argc, char *argv[]);
void	free_tab(char **tab);

void	pb(t_list **stack_b, t_list **stack_a);
void	pa(t_list **stack_b, t_list **stack_a);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack);
void	ra(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

void	min_sort(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
#endif
