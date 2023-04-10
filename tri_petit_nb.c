/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_petit_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:29:38 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:23:06 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_inf3(t_stack *groot)
{
	if (groot->a->index > groot->a->next->index)
		use(ft_sa, groot, "sa\n");
}

void	tri_3(t_stack *groot)
{
	int	first;
	int	next;
	int	next_next;

	first = groot->a->index;
	next = groot->a->next->index;
	next_next = groot->a->next->next->index;
	if ((first > next) && (next < next_next) && (next_next > first))
		use(ft_sa, groot, "sa\n");
	else if ((first > next) && (next > next_next) && (next_next < first))
	{
		use(ft_sa, groot, "sa\n");
		use(ft_rra, groot, "rra\n");
	}
	else if ((first > next) && (next < next_next) && (next_next < first))
		use(ft_ra, groot, "ra\n");
	else if ((first < next) && (next > next_next) && (next_next > first))
	{
		use(ft_sa, groot, "sa\n");
		use(ft_ra, groot, "ra\n");
	}
	else if ((first < next) && (next > next_next) && (next_next < first))
		use(ft_rra, groot, "rra\n");
}

void	tri_4(t_stack *groot)
{
	smart_remonte(groot, find_position_min(groot));
	use(ft_pb, groot, "pb\n");
	tri_3(groot);
	use(ft_pa, groot, "pa\n");
}

void	tri_5(t_stack *groot)
{
	smart_remonte(groot, find_position_min(groot));
	use(ft_pb, groot, "pb\n");
	smart_remonte(groot, find_position_min(groot));
	use(ft_pb, groot, "pb\n");
	tri_3(groot);
	use(ft_pa, groot, "pa\n");
	use(ft_pa, groot, "pa\n");
}
