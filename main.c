/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:46:41 by elisa             #+#    #+#             */
/*   Updated: 2023/04/19 15:07:18 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* prends en parametre les fonctions utilisees dont le type de retour est un 
void et le parametre est la structure "t_stack *" + ce qu'elle a besoin pour 
fonctionner + ce qu'on veut afficher */

void	use(void (*instructions)(t_stack *), t_stack *groot, char *str)
{
	instructions(groot);
	ft_putstr(str);
}

void	choose_tri(t_stack *groot)
{
	if (!stack_tri(groot))
	{
		if (groot->size_a == 2)
			tri_inf3(groot);
		else if (groot->size_a == 3)
			tri_3(groot);
		else if (groot->size_a == 4)
			tri_4(groot);
		else if (groot->size_a == 5)
			tri_5(groot);
		else if (groot->size_a > 5)
			tri_tall_nbr(groot);
	}
}

int	find_max(t_stack *groot)
{
	int			pos;
	int			i;
	t_plates	*tmp;

	i = -1;
	find_position_max_a(groot, &pos);
	tmp = groot->a;
	while (++i < pos)
		tmp = tmp->next;
	return (tmp->value);
}

int	main(int argc, char **argv)
{
	t_stack	groot;

	if (argc < 2)
		return (1);
	groot.a = NULL;
	groot.b = NULL;
	groot.size_a = 0;
	groot.size_b = 0;
	if (!create(&groot, argc, argv))
		return (1);
	if (groot.size_a <= 100)
		groot.end = groot.size_a / 5;
	else if (groot.size_a >= 100 && groot.size_a <= 500)
		groot.end = groot.size_a / 12;
	else
		groot.end = groot.size_a / 15;
	groot.max_a = find_max(&groot);
	groot.max = groot.size_a;
	index_nb(&groot);
	choose_tri(&groot);
}
