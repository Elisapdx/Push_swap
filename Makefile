# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisa <elisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:40:39 by elisa             #+#    #+#              #
#    Updated: 2023/03/25 12:06:31 by elisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= main.c init.c ft_stacking_up.c create.c utils.c tri_petit_nb.c test_tall_nb.c raise.c ft_split.c instructions/ft_p.c instructions/ft_s.c instructions/ft_r.c instructions/ft_rr.c

NAME= push_swap
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)

all:$(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
