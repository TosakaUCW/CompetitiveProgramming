#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, ans = INF;
int a[N], b[N], c[N], sum[N];

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
        for (int j = 0, x = a[i]; j < std::min(i, 30); j++, x ^= a[i - j])
            for (int k = 0, y = 0; k < std::min(n - i, 30); k++)
                if (x > (y ^= a[i + 1 + k]))
                    ans = std::min(ans, j + k);
    return printf("%d", ans == INF ? -1 : ans), 0;
}