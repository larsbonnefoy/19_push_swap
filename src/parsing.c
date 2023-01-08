#include "push_swap.h"
#include <stdio.h>
void is_valid_number(char *str);
void check_big_input(int argc, char *argv[]);
void check_small_input(int *argc, char *argv[]);
void check_duplicates(int argc, char *argv[]);

void check_input(int *argc, char *argv[])
{
	if (*argc > 2)
		check_big_input(*argc, argv);
	else if (*argc == 2)
		check_small_input(argc, argv);
	else
	{
		printf("1\n");
		error();
	}
}

void check_big_input(int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		is_valid_number(argv[i]);
		i++;
	}
	check_duplicates(argc, argv);
}

//pb c'est que tab n'as pas argv[0] => ft_join;
void check_small_input(int *argc, char *argv[])
{
	int		i;
	int		space_flag;
	char	**tab;
	int		argc_cp;

	i = -1;
	space_flag = 0;
	while (argv[1][++i] != '\0')
	{
		if (argv[1][i] == ' ')
			space_flag = 1;
	}
	if (space_flag == 0)
		error();
	argv[1] = ft_strjoinf("place_holder ", argv[1]);
	if (argv[1] == NULL)
		error();
	printf("%s\n", argv[1]);
	tab = ft_split(argv[1], ' ');
	if (tab == NULL)
		error();
	argc_cp = 1;
	while (tab)
		argc_cp++;
	*argc = argc_cp;
	check_big_input(*argc, tab);
	argv = tab;
}

void check_duplicates(int argc, char *argv[])
{
	int i;
	int j;
	int curr_number;

	i = 1;
	while (i < argc)
	{
		curr_number = ft_atoi(argv[i]);	
		j = i + 1;
		while (j < argc)
		{
			if (curr_number == ft_atoi(argv[j]))
				error();
			j++;
		}
		i++;
	}
}

void is_valid_number(char *str)
{
	int a;

	a = 0;
	if (ft_isdigit(str[0]) == 1)
		a++;
	else if ((str[0] == '-' || str[0] == '+' ) && ft_strlen(str) > 1)
		a++;
	else
		error();
	while (str[a] != '\0')
	{
		if (ft_isdigit(str[a]) == 1)
			a++;
		else
			error();
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		error();
}
