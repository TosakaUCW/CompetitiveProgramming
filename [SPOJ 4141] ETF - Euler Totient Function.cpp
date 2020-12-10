#include <math.h>
#include <stdio.h>

int n;

int phi(int n)
{
    int res = n, m = sqrt(n);
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", phi(x));
    }
    return 0;
}