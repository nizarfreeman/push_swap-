/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:52:48 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:52:57 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <utils.h>

void	skip_delim(const char	**s, char c)
{
	while (**s == c)
		(*s)++;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	y;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	i = 0;
	while (s && *s && res)
	{
		y = 0;
		skip_delim(&s, c);
		if (!*s)
			break ;
		res[i] = (char *) malloc((get_len(s, c) + 1) * sizeof(char));
		if (!res[i])
		{
			free_array(res);
			return (NULL);
		}
		while (*s && *s != c)
			res[i][y++] = *s++;
		res[i++][y] = '\0';
	}
	if (res)
		res[i] = NULL;
	return (res);
}
