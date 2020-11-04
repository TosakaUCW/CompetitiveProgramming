#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 3e5 + 5;
const int P = 998244353;

int n, ans;
int a[N], inv[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

signed main()
{
    n = read();
    for (int i = 1; i <= n * 2; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n * 2);
    for (int i = 1; i <= n; i++)
        ans = (ans - a[i] + P) % P;
    for (int i = n + 1; i <= 2 * n; i++)
        (ans += a[i]) %= P;
    for (int i = 2 * n; i >= n + 1; i--)
        ans = ans * i % P;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = inv[P % i] * (P - P / i) % P;
        (ans *= inv[i]) %= P;
    }
    return printf("%lld", ans), 0;
}