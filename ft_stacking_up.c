/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacking_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:41:08 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:06:21 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_plates	*ft_lstnew(int value)
{
	t_plates	*new;

	new = malloc(sizeof(t_plates));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_plates	*ft_lstlast(t_plates *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_plates **first, t_plates *new)
{
	t_plates	*last;

	if (*first == NULL)
	{
		*first = new;
		return ;
	}
	last = ft_lstlast(*(first));
	last->next = new;
}

void	ft_lstdelone(t_plates *lst)
{
	if (lst != NULL)
	{
		free(lst);
	}
}

size_t	ft_strlen(const char *s)
{
	int	e;

	e = 0 ;
	if (!s)
		return (0);
	while (s[e] != '\0')
		e++;
	return (e);
}
