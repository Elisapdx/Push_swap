/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:43:02 by elisa             #+#    #+#             */
/*   Updated: 2023/04/15 11:57:34 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	smart_remonte(t_stack *groot, int position)
{
	if (position + 1 > groot->size_a / 2)
	{
		while (position < groot->size_a)
		{
			use(ft_rra, groot, "rra\n");
			position++;
		}
	}
	else
	{
		while (position != 0)
		{
			use(ft_ra, groot, "ra\n");
			position--;
		}
	}
}

int	find_position_min(t_stack *groot)
{
	int			i;
	int			position;
	t_plates	*tmp;
	t_plates	*min;

	i = 0;
	position = i;
	tmp = groot->a;
	min = tmp;
	while (tmp)
	{
		if (min->index > tmp->index)
		{
			min = tmp;
			position = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (position);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
