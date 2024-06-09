#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (c > a)
            printf("1 ");
        else
            printf("-1 ");
        if (a * b > c)
            printf("%lld\n", b);
        else
            printf("-1\n");
    }
    return 0;
}