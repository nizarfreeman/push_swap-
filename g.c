#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	skip_spaces(const char **s);
void	sign_check(const char	**s, int *flag, int *double_sign);
int	ll_check(unsigned long long res, int flag, int *flag_2);
int	ft_atoi(const char *s, int *flag_2);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
int	count_words(const char *s, char c);
int	get_len(const char *s, char c);
void	free_array(char **arr);
void	skip_delim(const char	**s, char c);
char	**ft_split(const char *s, char c);
int	ft_isdigit(int c);

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

void	pa_(stack_a *a, stack_b *b)
{
	if (b->top == -1 || a->top + 1 >= a->size)
		return ;
	a->arr[++(a->top)] = b->arr[(b->top)--];
}

void	pb_(stack_a *a, stack_b *b)
{
	if (a->top == -1 || b->top + 1 >= b->size)
		return ;
	b->arr[++(b->top)] = a->arr[(a->top)--];
}

void	ra_(stack_a *a)
{
	int	tmp;
	int	i;

	if (a->top < 1)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = tmp;
}

void	rb_(stack_b *b)
{
	int	tmp;
	int	i;

	if (b->top < 1)
		return ;
	tmp = b->arr[0];
	i = 0;
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = tmp;
}

void	rr_(stack_a *a, stack_b *b)
{
	ra_(a);
	rb_(b);
}

void	rra_(stack_a *a)
{
	int	tmp;
	int	i;

	if (a->top < 1)
		return ;
	tmp = a->arr[a->top];
	i = a->top;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
}

void	rrb_(stack_b *b)
{
	int	tmp;
	int	i;

	if (b->top < 1)
		return ;
	tmp = b->arr[b->top];
	i = b->top;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = tmp;
}

void	rrr_(stack_a *a, stack_b *b)
{
	rra_(a);
	rrb_(b);
}

int	dup_check(int *arr, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i <= index)
	{
		j = i + 1;
		while (j <= index)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			i++;
			continue ;
		}
		if ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			return (0);
		if (s[i] != '-' && s[i] != '+' && !ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_empty(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (1);
		s++;
	}
	return (0);
}

int	count_string_nums(char *str)
{
	char	**arr;
	int	ret;
	int	i;

	arr = ft_split(str, ' ');
	if (!arr)
		return (0);
	ret = 0;
	i = 0;
	while (arr[i])
	{
		ret++;
		i++;
	}
	i = 0;
	free_array(arr);	
	return (ret);
}

int	count_elements(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		if (!check_valid(av[i]) || !check_if_empty(av[i]))
			return (0);
		total += count_string_nums(av[i]);
		i++;
	}
	return (total);
}

int	push_(stack_a **a, char **arr)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (arr[i])
	{
		(*a)->arr[++((*a)->top)] = ft_atoi(arr[i], &flag);
		if (!flag)
			return (0);
		i++;
	}
	return (1);
}

int	fill_stack(stack_a **a, int ac, char **av)
{
	char	**arr;
	int	i;
	int	y;

	i = 1;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (0);
		if (!push_(a, arr))
			return (0);
		y = 0;
		free_array(arr);
		i++;
	}
	return (1);
}

int	set_a(stack_a **a, int ac, char **av)
{
	int	count;

	count = count_elements(ac, av);
	if (!count || ac == 1)
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
	if (!fill_stack(a, ac, av) || !dup_check((*a)->arr, (*a)->top))
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

	if (ac < 2)
		return (0);
	if (!set_a(&a, ac, av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	for (int i = 0; i < a -> size; i++)
		printf("%d ", a->arr[i]);
	free(a->arr);
	free(a);
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
