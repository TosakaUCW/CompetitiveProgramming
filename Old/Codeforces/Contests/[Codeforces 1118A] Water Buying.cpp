#include <stdio.h>

int a, b, c;
long long n, ans;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d%d%d", &n, &a, &b);
        c = a * 2;
        if (b > c)
            ans = a * n;
        else
            ans = a * (n % 2) + n / 2 * b;
        printf("%I64d\n", ans);
    }
    return 0;
}