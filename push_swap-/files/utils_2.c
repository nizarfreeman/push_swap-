/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:52:20 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:52:35 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <utils.h>

int	ft_atoi(const char *s, int *flag_2)
{
	unsigned long long	res;
	int					flag;
	int					double_sign;
	int					check;

	flag = 0;
	double_sign = 0;
	skip_spaces(&s);
	sign_check(&s, &flag, &double_sign);
	if (double_sign)
		return (0);
	res = 0;
	check = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		check = ll_check(res, flag, flag_2);
		if (check != 1)
			return (check);
		s++;
	}
	if (flag)
		return ((int)(-res));
	return ((int)res);
}


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	if (!s)
		return (0);
	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int	get_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
