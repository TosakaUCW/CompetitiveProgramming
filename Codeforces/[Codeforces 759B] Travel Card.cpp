#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, t[N], f[N];

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
    n = read(), t[0] = -INF;
    for (int i = 1; i <= n; i++)
        t[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int pos1 = std::lower_bound(t, t + n + 1, t[i] - 89) - t;
        int pos2 = std::lower_bound(t, t + n + 1, t[i] - 1439) - t;
        f[i] = f[i - 1] + 20;
        if (i - pos1 >= 2)
            f[i] = std::min(f[i], f[pos1 - 1] + 50);
        if (i - pos2 >= 5)
            f[i] = std::min(f[i], f[pos2 - 1] + 120);
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", f[i] - f[i - 1]);
    return 0;
}