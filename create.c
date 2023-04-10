/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:40 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:06:18 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	i;

	a = 1;
	b = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
			a *= -1;
			i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = b + (str[i] - 48);
		if (!(str[i + 1] < '0' || str[i + 1] > '9'))
			b = b * 10;
		i++;
	}
	return (a * b);
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
	if (!valid_argument(argc, argv))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	while (i != argc)
	{
		check_str(groot, argv[i]);
		i++;
	}
	return (groot);
}
