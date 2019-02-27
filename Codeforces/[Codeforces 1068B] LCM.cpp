#include <math.h>
#include <stdio.h>

long long n, ans = 1;

int main()
{
    scanf("%lld", &n);
    for (int i = 2, m = sqrt(n); i <= m; i++)
    {
        int tmp = 1;
        while (n % i == 0)
            n /= i, tmp++;
        ans *= tmp;
    }
    if (n > 1)
        ans *= 2;
    printf("%lld", ans);
    return 0;
}