#include <stdio.h>
#include <unistd.h>

int	bin_dec(const char *bin)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (bin[i])
	{
		res = (res << 1) | (bin[i] - '0');
		i++;
	}
	return (res);
}

void	put_bin(int num)
{
	int i;
	char bit;
	char waa[32] = {0};

	i = sizeof(int) * 8 - 1;
	while (i >= 0)
	{
		bit = ((num >> i) & 1) + '0';
		write(1, &bit, 1);
		waa[i] = bit;
		i--;
	}
	write(1, "\n\n\n", 3);
	for (i = 0; i < 32; i++)
		printf("%d\n", waa[i]);
}

int main(int ac, char **av)
{
	put_bin(2147483647);
	//pintf("%d\n", 42 >> 0);
	return (0);
}
