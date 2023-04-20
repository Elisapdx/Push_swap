# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisa <elisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:40:39 by elisa             #+#    #+#              #
#    Updated: 2023/04/10 16:28:52 by elisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= check_error.c create.c ft_split.c ft_stacking_up.c init.c main.c raise.c tri_petit_nb.c tri_tall_nb.c utils.c instructions/ft_p.c instructions/ft_s.c instructions/ft_r.c instructions/ft_rr.c

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
