#include "push_swap.h"

t_list *find_min(t_list **stack)
{
	t_list *tmp;
	t_list *min_addr;
	
	tmp = *stack;
	min_addr = tmp;
	while (tmp != NULL)
	{
		if (min_addr->content > tmp->content)
			min_addr = tmp;
		tmp = tmp->next;
	}
	return (min_addr);
}

t_list *find_max(t_list **stack)
{
	t_list *tmp;
	t_list *max_addr;
	
	tmp = *stack;
	max_addr = tmp;
	while (tmp != NULL)
	{
		if (max_addr->content < tmp->content)
			max_addr = tmp;
		tmp = tmp->next;
	}
	return (max_addr);
}

int len_stack(t_list **stack_a)
{
	t_list	*tmp;
	int 	a;

	if (*stack_a == NULL)
		return (0);
	a = 0;
	tmp = *stack_a;
	while (tmp)
	{
		a++;
		tmp = tmp->next;
	}
	return (a);
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
