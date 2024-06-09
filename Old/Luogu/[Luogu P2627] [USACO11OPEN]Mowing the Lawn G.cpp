#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, k;
int a[N], f[N], sum[N];
int Q[N], head, tail;

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
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        sum[i] = read() + sum[i - 1];
    for (int i = 1; i <= n + 1; i++)
    {
        while (head <= tail and Q[head] + k < i - 1)
            ++head;
        f[i] = f[Q[head]] - sum[Q[head]] + sum[i - 1];
        while (head <= tail and f[Q[tail]] - sum[Q[tail]] <= f[i] - sum[i])
            --tail;
        Q[++tail] = i;
    }
    printf("%lld", f[n + 1]);
    return 0;
}