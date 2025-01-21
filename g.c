#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void	skip_spaces(const char **s);
void	sign_check(const char	**s, int *flag, int *double_sign);
int	ll_check(unsigned long long res, int flag);
int	ft_atoi(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
int	count_words(const char *s, char c);
int	get_len(const char *s, char c);
void	free_array(char **arr);
void	skip_delim(const char	**s, char c);
char	**ft_split(const char *s, char c);

typedef struct   a
{
	int	*arr;
	int	size;
	int	top;
} stack_a;

typedef struct  b
{
	int	*arr;
	int	size;
	int	top;
} stack_b;

void	sa_(int *arr)
{
	int	tmp;

	tmp = *arr;
	*arr = *(arr + 1);
	*(arr + 1) = tmp;
}

void	sb_(int *arr)
{
	int	tmp;

	tmp = *arr;
	*arr = *(arr + 1);
	*(arr + 1) = tmp;
}

void	ss_(int *a, int *b)
{
	sa_(a);
	sb_(b);
}

int	scan_flet(char *s)
{
	while (s)
	{
		if (!((*s >= '0' && *s <= '9') || *s == ' ' || 
			*s == '\"' || *s == '-' || *s == '+'))
			return (0);
		s++:
	}
	return (1);
}
int	search_dq(char *s)
{
	int	flag;

	flag = 0;
	s++;
	while (s)
	{
		if (*s != ' ' && *s != '\"')
			flag = 1;
		if (*s == '\"' && flag)
			return (1);
		s++;
	}
	return (0);
}

int	parse_quoted(char *str, int *y, stack_a **a, int *count)
{
}

int	parse_number(char *str, int *y, stack_a **a, int *count)
{
}

int	parse(stack_a **a, int ac, char **av)
{
}

int	count_string_nums(char *str)
{
}

int	check_valid(char *s)
{
	if (*s == '\"' && (!search_dq(s)))
		return (0);




}

int	count_elements(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		if (!check_valid(av[i])
			return (0);
		total += count_string_nums(av[i]);
		i++;
	}
	return (total);
}

int	set_a(stack_a **a, int ac, char **av)
{
	int	count;

	count = count_elements(ac, av);
	if (!count)
		return (0);
	*a = malloc(sizeof(stack_a));
	if (!*a)
		return (0);
	(*a)->arr = malloc(count * sizeof(int));
	if (!(*a)->arr)
	{
		free(*a);
		return (0);
	}
	(*a)->top = -1;
	(*a)->size = count;
	if (!parse(a, ac, av))
	{
		free((*a)->arr);
		free(*a);
		return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	stack_a	*a;
	stack_b	*b;

	if (!set_a(&a, ac, av))
		return (0);
	for (int i = 0; i < a->size; i++)
		printf("%d ", a->arr[i]);
	printf("\n");
}

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

int	ll_check(unsigned long long res, int flag)
{
	if (res > LONG_MAX)
	{
		if (flag == 1)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *s)
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
		check = ll_check(res, flag);
		if (check != 1)
			return (check);
		s++;
	}
	if (flag)
		return ((int)(-res));
	return ((int)res);
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
