#include "push_swap.h"

static int *init_array(int len_stack, t_list **stack_a);
static void mod_values(int len_stack, int *stack_arr, t_list **stack_a);
static void mod_stack(t_list **stack, int *array_mod_values);

void normalize_stack(t_list **stack)
{
	int *arr;
	int len_stck;

	len_stck = len_stack(stack);
	arr = init_array(len_stck, stack);
	mod_values(len_stck, arr, stack);
	free(arr);
}

int *init_array(int len_stack, t_list **stack_a)
{
	int *array;
	t_list *tmp;
	int a;

	array = malloc(sizeof(int) * len_stack);
	if (array == NULL)
		exit(EXIT_FAILURE);
	a = 0;
	tmp = *stack_a;
	while (a < len_stack)
	{
		array[a] = tmp->content;
		a++;
		tmp = tmp->next;
	}
	return (array);
}

void mod_values(int len_stack, int *stack_arr, t_list **stack_a)
{
	int a;
	int b;
	int lower_cnt;
	int *cp_arr;

	a = 0;
	cp_arr = init_array(len_stack, stack_a);
	while (a < len_stack)
	{
		b = 0;
		lower_cnt = 0;
		while (b < len_stack)
		{
			if (cp_arr[a] > cp_arr[b])		
				lower_cnt++;
			b++;
		}
		stack_arr[a] = lower_cnt;
		a++;
	}
	free(cp_arr);
	mod_stack(stack_a, stack_arr);
}

void mod_stack(t_list **stack, int *array_mod_values)
{
	t_list *tmp;
	int a;

	a = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->content = array_mod_values[a];
		a++;
		tmp = tmp->next;
	}
}
