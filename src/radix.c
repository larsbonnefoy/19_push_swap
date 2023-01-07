
#include "push_swap.h"

int get_bits(int max);
//lulz radixed
//marche que avec des nombres positifs donc on va transformer la liste de 0 a N strictement croissant
void radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int bits;
	int i;
	int j;
	int num;
	int stack_size;

	stack_size = len_stack(stack_a);
	normalize_stack(stack_a);
	bits = get_bits(len_stack(stack_a) - 1);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < stack_size)
		{
			tmp = *stack_a;
			num = tmp->content;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

int get_bits(int max)
{
	int a;

	a = 0;
	while (max != 0)
	{
		max = max >> 1;
		a++;
	}
	return (a);	
}
