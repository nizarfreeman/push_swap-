#include <stdio.h>

static int	count_string_nums(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
			{
				if ((str[i] >= '0' && str[i] <= '9')
					|| str[i] == '-' || str[i] == '+')
				{
					count++;
					while (str[i] && str[i] != ' '
						&& str[i] != '\"')
						i++;
				}
				if (str[i] && str[i] != '\"')
					i++;
			}
		}
		else if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == '-' || str[i] == '+')
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		if (str[i])
			i++;
	}
	return (count);
}


int	count_elements(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		total += count_string_nums(av[i]);
		i++;
	}
	return (total);
}
#include <stdlib.h>
int main(int ac, char **av)
{
	printf("%d\n", count_elements(ac, av));
	int *jj = malloc(0 * sizeof(int));
	return (0);
}
