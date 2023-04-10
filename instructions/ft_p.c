/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:00:41 by elisa             #+#    #+#             */
/*   Updated: 2023/03/30 15:24:28 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack *groot)
{
	t_plates	*temp;

	if (groot->b)
	{
		groot->size_b--;
		groot->size_a++;
		temp = groot->b->next;
		groot->b->next = groot->a;
		groot->a = groot->b;
		groot->b = temp;
	}
}

void	ft_pb(t_stack *groot)
{
	t_plates	*temp;

	if (groot->a)
	{
		groot->size_a--;
		groot->size_b++;
		temp = groot->a->next;
		groot->a->next = groot->b;
		groot->b = groot->a;
		groot->a = temp;
	}
}
