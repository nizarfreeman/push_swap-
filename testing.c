#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_pali(unsigned long long n)
{
    if (n < 0)
        return (0);
    unsigned long long cp = 0;
    unsigned long long nn = n;
    while (n > 0)
    {
        cp = cp * 10 + n % 10;
        n /= 10;
    }
    return (nn == cp);
}

int largestPalindrome(int n)
{
    unsigned long long max = (int)(pow(10, n) - 1);
    unsigned long long res = 0;
    unsigned long long ret = res;

    while ((int)(log10(max) + 1) == n)
    {
        unsigned long long max_1 = max - 1;
        while ((int)(log10(max_1) + 1) == n)
        {
            res = max_1 * max;
            if (is_pali(res))
                if (res > ret)
                    ret = res;
            if (ret >= max * max)
                return (ret % 1337);
            max_1--;
        }
        max--;
    }  
    return (ret % 1337);
}
int main()
{
	printf("%d\n\n", largestPalindrome(5));

}
