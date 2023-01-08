#include "push_swap.h"

void is_valid_number(char *str);
void check_big_input(int argc, char *argv[]);
void check_small_input(int *argc, char *argv[]);
void check_duplicates(int argc, char *argv[]);

void check_input(int *argc, char *argv[])
{
	if (*argc > 2)
		check_big_input(*argc, argv);
	if (*argc == 2)
		check_small_input(argc, argv);
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
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

	i = 0;
	space_flag = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == 32)
			space_flag = 1;
	}
	if (space_flag == 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	tab = ft_split(argv[1], ' ');
	if (tab == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	*argc = 1;
	while (tab)
		*argc = *argc+=1;
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
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

//recoder atoi to atol comme ca on peut check pour max int;
void is_valid_number(char *str)
{
	int a;

	a = 0;
	if (ft_isdigit(str[0]) == 1)
		a++;
	else if ((str[0] == '-' || str[0] == '+' ) && ft_strlen(str) > 1)
		a++;
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (str[a] != '\0')
	{
		if (ft_isdigit(str[a]) == 1)
			a++;
		else
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
	}
}
