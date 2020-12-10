#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 5e5 + 5;
const int P = 20000311;

int n, m, ans;
int a[N], cnt[N], pow2[N];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

signed main()
{
    n = m = read(), pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read(), a[i] <= n ? cnt[a[i]]++ : 0, pow2[i] = (pow2[i - 1] << 1LL) % P;
    for (int i = 1, mul = 1; i <= n; i++)
        (ans += mul * pow2[m -= cnt[i]] % P * i % P) %= P, (mul *= (pow2[cnt[i]] - 1 + P) % P) %= P;
    return printf("%lld", ans), 0;
}