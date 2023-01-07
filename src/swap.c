#include "push_swap.h"

static void swap_cont(t_list **stack);

void sa(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_printf("sa\n");
	swap_cont(stack);
}

void sb(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ft_printf("sb\n");
	swap_cont(stack);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ft_printf("ss\n");
	swap_cont(stack_a);
	swap_cont(stack_b);
}

void swap_cont(t_list **stack)
{
	t_list *first_node;
	t_list *third_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	third_node = (*stack)->next->next;
	*stack = first_node->next;
	(*stack)->next = first_node;
	(*stack)->next->next = third_node;

}
