#include <stdio.h>
#include <algorithm>

typedef long long LL;

const int N = 2e3;
const LL P = 998244353;

LL n, k, ans;
LL x[N + 5], y[N + 5];

LL pow(LL x, LL k)
{
    LL res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

void Lagrange_Interpolation()
{
    for (int i = 1; i <= n; i++)
    {
        LL a = 1, b = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            a = a * (k - x[j]) % P;
            b = b * (x[i] - x[j]) % P;
        }
        ans = (ans + a * pow(b, P - 2) % P * y[i]) % P;
    }
    ans = (ans + P) % P;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &x[i], &y[i]);
    Lagrange_Interpolation();
    printf("%lld", ans);
    return 0;
}