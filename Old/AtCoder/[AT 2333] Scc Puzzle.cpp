#include <stdio.h>

long long n, m, ans;

int main()
{
    scanf("%lld%lld", &n, &m);
    ans = m - n * 2;
    printf("%lld\n", ans > 0 ? n + (ans >> 2) : m >> 1);
    return 0;
}