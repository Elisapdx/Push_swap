/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:23 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:30:12 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turn_up_a(t_stack *groot, int up, int down)
{
	if (down >= up)
	{
		while (up-- > 0)
		{
			use(ft_ra, groot, "ra\n");
		}
	}
	else if (up > down)
	{
		while (down++ < groot->size_a)
		{
			use(ft_rra, groot, "rra\n");
		}
	}
	use(ft_pb, groot, "pb\n");
}

void	index_nb(t_stack *groot)
{
	int			i;
	t_plates	*tmp;
	t_plates	*min;

	i = 0;
	while (i < groot->size_a)
	{
		tmp = groot->a;
		min = groot->a;
		while (min && min->index != -1)
			min = min->next;
		while (tmp)
		{
			if (tmp->value < min->value && tmp->index == -1)
				min = tmp;
			tmp = tmp->next;
		}
		if (min->index == -1)
			min->index = i;
		i++;
	}
}

t_plates	*find_position_max_b(t_stack *groot, int *position)
{
	int			i;
	t_plates	*tmp;
	t_plates	*max;

	i = 0;
	*position = 0;
	tmp = groot->b;
	max = groot->b;
	while (tmp)
	{
		if (tmp->index > max->index)
		{
			*position = i;
			max = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (max);
}

t_plates	*find_position_max_a(t_stack *groot, int *position)
{
	int			i;
	t_plates	*tmp;
	t_plates	*max;

	i = 0;
	*position = 0;
	tmp = groot->a;
	max = groot->a;
	while (tmp)
	{
		if (tmp->index > max->index)
		{
			*position = i;
			max = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (max);
}
