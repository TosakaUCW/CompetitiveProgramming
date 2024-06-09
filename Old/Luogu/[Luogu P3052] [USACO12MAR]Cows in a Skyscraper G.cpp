#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 18 + 1;
const int INF = 0x3f3f3f3f;

int n, m, sta;
int a[N], f[N][1 << N];

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

int main()
{
    memset(f, 0x3f, sizeof f);
    n = read(), m = read(), sta = (1 << n) - 1;
    for (int i = 0; i < n; i++)
        f[1][1 << i] = a[i] = read();
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= sta; i++)
            if (f[k][i] != INF)
                for (int j = 0; j < n; j++)
                {
                    if (i & (1 << j))
                        continue;
                    if (f[k][i] + a[j] <= m)
                        f[k][i | (1 << j)] = std::min(f[k][i | (1 << j)], f[k][i] + a[j]);
                    else
                        f[k + 1][i | (1 << j)] = std::min(f[k][i | (1 << j)], a[j]);
                }
    for (int i = 0; i <= n; i++)
        if (f[i][sta] != INF)
        {
            printf("%d", i);
            break;
        }
    return 0;
}