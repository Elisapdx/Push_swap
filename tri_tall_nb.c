/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tall_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:13:49 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:11:18 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition_up(t_stack *groot, int end, int start)
{
	int			pos;
	t_plates	*tmp;

	pos = 0;
	tmp = groot->a;
	while (pos < groot->size_a / 2)
	{
		if (tmp->index < end && tmp->index >= start)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

int	partition_down(t_stack *groot, int end, int start)
{
	int			pos;
	int			med;
	t_plates	*tmp;

	pos = 0;
	med = groot->size_a / 2;
	tmp = groot->a;
	while (med < groot->size_a)
	{
		if (tmp->index >= start && tmp->index < end)
			return (pos);
		pos++;
		med++;
		tmp = tmp->next;
	}
	return (0);
}

void	chunck(t_stack *groot, int start)
{
	int	ind_down;
	int	ind_up;
	int	limit;
	int	end;

	end = groot->end;
	start = 0;
	while (groot->size_a)
	{
		limit = 0;
		while (limit < groot->end)
		{
			ind_down = partition_down(groot, end, start);
			ind_up = partition_up(groot, end, start);
			turn_up_a(groot, ind_up, ind_down);
			limit++;
		}
		start = end;
		end += groot->end;
	}
}

void	tall_nbr(t_stack *groot)
{
	t_plates	*tmp;
	int			i;
	int			start;

	i = 0;
	start = 0;
	chunck(groot, start);
	while (groot->size_b)
	{
		tmp = find_position_max_b(groot, &i);
		while (groot->b != tmp)
		{
			if (i < groot->size_b / 2)
				use(ft_rb, groot, "rb\n");
			else
				use(ft_rrb, groot, "rrb\n");
		}
		use(ft_pa, groot, "pa\n");
	}
}
