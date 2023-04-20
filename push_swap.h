/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:24:58 by elisa             #+#    #+#             */
/*   Updated: 2023/04/18 15:48:27 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* STRUCTURES */

typedef struct s_plates
{
	int				value;
	int				index;
	struct s_plates	*next;
}	t_plates;

typedef struct s_stack
{
	t_plates	*a;
	int			size_a;
	t_plates	*b;
	int			size_b;
	int			end;
	int			max_a;
	int			max;
}	t_stack;

/* INSTRUCTIONS */

/* ft_s.c */
void		ft_sa(t_stack *groot);
void		ft_sb(t_stack *groot);
void		ft_ss(t_stack *groot);

/* ft_p.c */
void		ft_pa(t_stack *groot);
void		ft_pb(t_stack *groot);

/* ft_r.c */
void		ft_ra(t_stack *groot);
void		ft_rb(t_stack *groot);
void		ft_rr(t_stack *groot);

/* ft_rr.c */
void		ft_rra(t_stack *groot);
void		ft_rrb(t_stack *groot);
void		ft_rrr(t_stack *groot);

/* create.c */

int			ft_atoi(const char *str);
int			valid_argument(int argc, char **argv);
int			check_str(t_stack *groot, char *str);
t_stack		*create(t_stack *groot, int argc, char **argv);

/* init.c */
void		insert_a(t_stack *groot, int nb);
void		insert_b(t_stack *groot, int nb);
void		affiche_pile(t_plates **first);

/* tri_petit_nb.c */
void		tri_inf3(t_stack *groot);
void		tri_3(t_stack *groot);
void		tri_4(t_stack *groot);
void		tri_5(t_stack *groot);

/* utils.c */
void		free_tab(char **tab);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		smart_remonte(t_stack *groot, int pos);
int			find_position_min(t_stack *groot);

/* ft_split.c */
char		**ft_split(char const *s, char c);

/* ft_stacking_up.c */
t_plates	*ft_lstnew(int index);
t_plates	*ft_lstlast(t_plates *lst);
void		ft_lstadd_back(t_plates **first, t_plates *new);
void		ft_lstdelone(t_plates *lst);
size_t		ft_strlen(const char *s);

/* raise.c */
void		turn_up_a(t_stack *groot, int ind, int choix);
void		index_nb(t_stack *groot);
t_plates	*find_position_max_a(t_stack *groot, int *position);
t_plates	*find_position_max_b(t_stack *groot, int *position);

/* main.c */
void		use(void (*move)(t_stack *), t_stack *groot, char *str);

void		tri_tall_nbr(t_stack *groot);

/* check_error.c */

int			stack_tri(t_stack *groot);
int			check_duplicate(t_stack *groot);
int			check_signe(int argc, char **argv);

#endif