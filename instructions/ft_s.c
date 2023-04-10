/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:00:10 by elisa             #+#    #+#             */
/*   Updated: 2023/03/13 15:57:59 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *groot)
{
	t_plates	*temp;

	if (groot->a && groot->a->next)
	{
		temp = groot->a->next;
		groot->a->next = groot->a->next->next;
		temp->next = groot->a;
		groot->a = temp;
	}	
}

void	ft_sb(t_stack *groot)
{
	t_plates	*temp;

	if (groot->b && groot->b->next)
	{
		temp = groot->b->next;
		groot->b->next = groot->b->next->next;
		temp->next = groot->b;
		groot->b = temp;
	}	
}

void	ft_ss(t_stack *groot)
{
	ft_sa(groot);
	ft_sb(groot);
}
