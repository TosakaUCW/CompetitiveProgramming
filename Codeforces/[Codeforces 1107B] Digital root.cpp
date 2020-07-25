#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long k, x;
        scanf("%I64d%I64d ", &k, &x);
        printf("%I64d\n", 9LL * (k - 1) + x);
    }
    return 0;
}