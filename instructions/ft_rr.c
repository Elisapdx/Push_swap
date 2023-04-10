/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:00:33 by elisa             #+#    #+#             */
/*   Updated: 2023/03/13 16:09:59 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack *groot)
{
	t_plates	*temp;
	t_plates	*first;

	if (groot->a && groot->a->next)
	{
		first = groot->a;
		while (groot->a->next->next)
			groot->a = groot->a->next;
		temp = groot->a->next;
		groot->a->next = NULL;
		groot->a = first;
		temp->next = groot->a;
		groot->a = temp;
	}	
}

void	ft_rrb(t_stack *groot)
{
	t_plates	*temp;
	t_plates	*first;

	if (groot->b && groot->b->next)
	{
		first = groot->b;
		while (groot->b->next->next)
			groot->b = groot->b->next;
		temp = groot->b->next;
		groot->b->next = NULL;
		groot->b = first;
		temp->next = groot->b;
		groot->b = temp;
	}	
}

void	ft_rrr(t_stack *groot)
{
	ft_rra(groot);
	ft_rrb(groot);
}
