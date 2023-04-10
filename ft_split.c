/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:17:05 by elisa             #+#    #+#             */
/*   Updated: 2023/04/02 15:06:20 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	while (src[res] != '\0')
		res++;
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_to_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_to_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_to_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_to_strs++;
			while (s[i] && s[i] == c)
				i++;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_to_strs++;
	return (nb_to_strs);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_to_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_to_strs = ft_get_nb_to_strs(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_to_strs + 1));
	if (!(tab))
		return (NULL);
	i = -1;
	next_str = (char *)s;
	next_str_len = 0;
	while (++i < nb_to_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!(tab[i]))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
