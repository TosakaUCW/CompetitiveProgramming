#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, ans;
int a[N], f[N], g[N];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        f[i] = a[i] > a[i - 1] ? f[i - 1] + 1 : 1, ans = std::max(ans, f[i - 1] + 1);
    for (int i = n; i >= 1; i--)
        g[i] = a[i + 1] > a[i] ? g[i + 1] + 1 : 1, ans = std::max(ans, g[i + 1] + 1);
    for (int i = 1; i <= n; i++)
        if (a[i - 1] + 1 < a[i + 1])
            ans = std::max(ans, f[i - 1] + 1 + g[i + 1]);
    return printf("%d", ans), 0;
}