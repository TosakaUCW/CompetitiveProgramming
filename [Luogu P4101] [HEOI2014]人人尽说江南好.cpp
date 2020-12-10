#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        printf("%d\n", (n - (n / m + (n % m != 0))) % 2 == 0 ? 1 : 0);
    }
    return 0;
}