/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:40 by elisa             #+#    #+#             */
/*   Updated: 2023/04/15 11:57:24 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	overflow(void)
{
	write(2, "Error\n", 7);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int	element;
	int	nbr;
	int	i;

	element = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
			element *= -1;
			i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr * 10 + (str[i] - '0')) / 10 != nbr)
			overflow();
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (element * nbr);
}

int	valid_argument(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ')
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_str(t_stack *groot, char *str)
{
	int		res;
	int		j;
	char	**tab;

	j = -1;
	tab = ft_split(str, ' ');
	while (tab[++j])
	{
		res = ft_atoi(tab[j]);
		insert_a(groot, res);
	}
	free_tab(tab);
	return (1);
}

t_stack	*create(t_stack *groot, int argc, char **argv)
{
	int	i;

	i = 1;
	if (!(valid_argument(argc, argv) && check_signe(argc, argv)))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	while (i != argc)
	{
		check_str(groot, argv[i]);
		i++;
	}
	if (!check_duplicate(groot))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	return (groot);
}
