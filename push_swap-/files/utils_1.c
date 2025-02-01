/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:50:35 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:52:03 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <utils.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *) s;
	while (n--)
		*src++ = (unsigned char) c;
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, size * count);
	return (ret);
}

void	skip_spaces(const char	**s)
{
	while ((**s >= 9 && **s <= 13) || **s == ' ')
		(*s)++;
}

void	sign_check(const char **s, int *flag, int *double_sign)
{
	if (**s == '-' || **s == '+')
	{
		if (*(*s + 1) == '+' || (*(*s + 1)) == '-')
		{
			*double_sign = 1;
			return ;
		}
		if (**s == '-')
			*flag = 1;
		(*s)++;
	}
}

int	ll_check(unsigned long long res, int flag, int *flag_2)
{
	if (res > INT_MAX)
	{
		if (flag == 1 && res == 2147483648ULL)
			return (-2147483648);
		if (flag == 1)
		{
			*flag_2 = 0;
			return (0);
		}
		else
		{
			*flag_2 = 0;
			return (-1);
		}
	}
	return (1);
}
