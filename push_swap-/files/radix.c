#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

long int ft_atol(const char *str)
{
	long int	res = 0;
	int	neg_flag = 0;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg_flag = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (neg_flag)
		{
			res *= -1;
			if (res < (LONG_MIN / 10))
				return (LONG_MIN);
			res *= -1;
		}
		if (res > (LONG_MAX / 10))
			return (LONG_MAX);
		res = res * 10 + (*str - '0');
		str++;
	}
	if (neg_flag)
		res *= -1;
	return (res);
}

int	count_(unsigned int max)
{
	int	count;

	count = 0;
	if (max == 0)
		return (1);
	while (max > 0)
	{
		count++;
		max /= 10;
	}
	return (count);
}

int	get_max(int ac, int *arr)
{
	unsigned int	max;
	unsigned int	abs;
	int		i;

	max = 0;
	i = 0;
	while (i < ac)
	{
		if (arr[i] == INT_MIN)
			abs = ((unsigned int)INT_MAX) + 1;
		else if (arr[i] < 0)
			abs = -arr[i];
		else
			abs = arr[i];
		if (abs > max)
			max = abs;
		i++;
	}
	return (count_(max));
}

void	subroutine_(int *arr, int size, int exp)
{
	int *output;
	int count[20] = {0};
	int i;
	int digit;

	output = malloc(size * sizeof(int));
	if (!output)
		return ;
	i = 0;
	while (i < size)
	{
		digit = ((arr[i] / exp) % 10);
		count[digit + 10]++;
		i++;
	}
	i = 1;
	while (i < 20)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		digit = ((arr[i] / exp) % 10);
		output[count[digit + 10] - 1] = arr[i];
		count[digit + 10]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = output[i];
		i++;
	}
	free(output);
}

void	sort_(int *arr, int size)
{
	int max_digits;
	int exp;
	int i;

	max_digits = get_max(size, arr);
	exp = 1;
	i = 0;
	while (i < max_digits)
	{
		subroutine_(arr, size, exp);
		exp *= 10;
		i++;
	}
}

int main(int ac, char **av)
{
	int	size;
	int i;
	int *arr;

	size = ac - 1;
	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i] = ft_atol(av[i + 1]);
		i++;
	}
	sort_(arr, size);
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}
