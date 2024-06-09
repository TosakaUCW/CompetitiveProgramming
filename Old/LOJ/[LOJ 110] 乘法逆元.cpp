#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 3e6 + 5;

int n, P;
int inv[N];

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
    n = read(), P = read(), puts("1");
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (P - P / i) % P * inv[P % i] % P, printf("%lld\n", inv[i]);
    return 0;
}