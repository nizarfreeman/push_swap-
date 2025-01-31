#include <stdio.h>

int	get_bits_num(char c)
{
	for (int i = 7; i >=0; i--)
	{
		if ((c >> i) & 1)
			return (i);
	}
}

int main(int argc, char const *argv[])
{
	char p[3] = {'a', 'z', 'Q'};
	int max = 0;
	for (int i = 0; i < 3; i++)
			if (get_bits_num(p[i]) > max)
				max = get_bits_num(p[i]);
	printf("%d\n", max);
	return 0;
}