#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m, ans = INF;
int a[N], b[N];

int main()
{
    n = read(), m = read(), a[n + 1] = INF;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, x1, x2, y; i <= m; i++)
    {
        x1 = read(), x2 = read(), y = read();
        if (x1 == 1)
            b[++b[0]] = x2;
    }
    std::sort(a + 1, a + 1 + n), std::sort(b + 1, b + 1 + b[0]);
    for (int i = 1, x; i <= n + 1; i++)
        x = std::lower_bound(b + 1, b + 1 + b[0], a[i]) - b,
        ans = std::min(ans, i + b[0] - x);
    return printf("%d", ans), 0;
}