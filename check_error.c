/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:02:47 by elisa             #+#    #+#             */
/*   Updated: 2023/04/20 15:16:59 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_tri(t_stack *groot)
{
	t_plates	*tmp;

	tmp = groot->a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_duplicate(t_stack *groot)
{
	t_plates	*tmp;
	t_plates	*now;
	int			nbr;

	now = groot->a;
	while (now)
	{
		nbr = now->value;
		tmp = now->next;
		while (tmp)
		{
			if (nbr == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		now = now->next;
	}
	return (1);
}

int	check_signe(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
