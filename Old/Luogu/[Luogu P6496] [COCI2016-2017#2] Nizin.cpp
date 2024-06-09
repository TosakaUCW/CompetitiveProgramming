#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, ans;
int a[N];

signed main()
{
    freopen("nizin.in", "r", stdin), freopen("nizin.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int L = 1, R = n; L < R;)
        if (a[L] > a[R])
            a[--R] += a[R + 1], ++ans;
        else if (a[L] < a[R])
            a[++L] += a[L - 1], ++ans;
        else
            ++L, --R;
    return printf("%lld", ans), 0;
}