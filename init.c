/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:30:53 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:06:22 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_a(t_stack *groot, int nb)
{
	t_plates	*n;

	n = ft_lstnew(nb);
	ft_lstadd_back(&groot->a, n);
	groot->size_a++;
}

void	insert_b(t_stack *groot, int nb)
{
	t_plates	*new;
	t_plates	*now;

	new = malloc(sizeof(new));
	new->index = nb;
	new->next = NULL;
	if (groot->b)
	{
		now = groot->b;
		while (now->next != NULL)
			now = now->next;
		now->next = new;
	}
	else
		groot->b = new;
	groot->size_b++;
}

void	affiche_pile(t_plates **first)
{
	t_plates	*element;

	element = (*first);
	while (element)
	{
		printf("value %d index %d\n", element->value, element->index);
		element = element->next;
	}
}
