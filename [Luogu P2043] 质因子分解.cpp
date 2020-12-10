#include <stdio.h>

const int N = 1e4 + 5;

int n, a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int tmp = i;
        for (int j = 2; j <= i; j++)
            while (tmp % j == 0)
            {
                a[j]++;
                tmp /= j;
            }
    }
    for (int i = 1; i <= 10000; i++)
        if (a[i] != 0)
            printf("%d %d\n", i, a[i]);
    return 0;
}